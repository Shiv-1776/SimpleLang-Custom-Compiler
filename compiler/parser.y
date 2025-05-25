%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "icg.h"

extern FILE *icg_file;

char* new_temp() { return generate_temp(); }
char* new_label() { return generate_label(); }
char *current_while_label_start = NULL;
char *current_while_label_end = NULL;
char *label_else;
char *label_end;

extern int yylex(void);
extern int yylineno;
void yyerror(const char *s);
%}

%start program

%union {
    int    num;
    char  *str;
}

%token <str>   NUMBER STRING IDENTIFIER

%token         CLASS DEF PRINT RETURN NEW IF ELSE WHILE
%token         EQ NEQ LE GE LT GT ASSIGN
%token         PLUS MINUS MUL DIV DOT
%token         LPAREN RPAREN LBRACE RBRACE COMMA NEWLINE

// Fix precedence and associativity
%right         ASSIGN
%left          EQ NEQ
%left          LT GT LE GE
%left          PLUS MINUS
%left          MUL DIV
%left          DOT
%nonassoc      UMINUS
%nonassoc      LOWER_THAN_ELSE
%nonassoc      ELSE

%type <str>    expression primary_expression
%type <str>    statement assignment print_stmt return_stmt if_stmt while_stmt class_def func_def
%type <str>    param_list arg_list

%%

program:
    statements
    {
        optimize_instructions();
        write_instructions_to_file(icg_file);
    }
;

statements:
    /* empty */
  | statements statement_with_newlines
;

statement_with_newlines:
    statement
  | statement_with_newlines NEWLINE
  | NEWLINE
;

statement:
    assignment      { $$ = $1; }
  | print_stmt      { $$ = $1; }
  | return_stmt     { $$ = $1; }
  | if_stmt         { $$ = $1; }
  | while_stmt      { $$ = $1; }
  | class_def       { $$ = $1; }
  | func_def        { $$ = $1; }
;
optional_newlines:
    /* empty */
  | optional_newlines NEWLINE
;
assignment:
    IDENTIFIER ASSIGN expression
    {
        Instruction *inst = create_assign_instruction($1, $3);
        add_instruction(inst);

        if (!lookup_symbol($1)) {
            insert_symbol($1, VAR);
        }
        free($1);
        free($3);
        $$ = NULL;
    }
;

print_stmt:
    PRINT LPAREN expression RPAREN
    {
        Instruction *inst = create_print_instruction($3);
        add_instruction(inst);
        free($3);
        $$ = NULL;
    }
;

return_stmt:
    RETURN expression
    {
        Instruction *inst = create_return_instruction($2);
        add_instruction(inst);
        free($2);
        $$ = NULL;
    }
;

if_stmt:
    IF LPAREN expression RPAREN optional_newlines LBRACE
    {
        // Setup labels before parsing statements
        label_else = new_label();
        label_end = new_label();
        Instruction *inst_if_false = create_if_false_goto_instruction($3, label_else);
        add_instruction(inst_if_false);
        free($3); // prevent memory leak
    }
    statements RBRACE
    {
        // After 'if' block, jump over else
        Instruction *inst_goto_end = create_goto_instruction(label_end);
        add_instruction(inst_goto_end);

        // Label for else block
        Instruction *inst_label_else = create_label_instruction(label_else);
        add_instruction(inst_label_else);
    }
    ELSE optional_newlines LBRACE
    statements
    RBRACE
    {
        // End label
        Instruction *inst_label_end = create_label_instruction(label_end);
        add_instruction(inst_label_end);

        free(label_else);
        free(label_end);
    }
;

while_stmt:
    WHILE LPAREN expression RPAREN optional_newlines LBRACE statements RBRACE // 🔄 MODIFIED
    {
    // If the condition is constant "0", skip generating the loop entirely
    if (strcmp($3, "0") == 0) {
        free($3);
        $$ = NULL;
    } else {
        char *label_start = new_label();
        char *label_end = new_label();

        Instruction *inst_label_start = create_label_instruction(label_start);
        add_instruction(inst_label_start);

        Instruction *inst_if_false = create_if_false_goto_instruction($3, label_end);
        add_instruction(inst_if_false);

        Instruction *inst_goto_start = create_goto_instruction(label_start);
        add_instruction(inst_goto_start);

        Instruction *inst_label_end = create_label_instruction(label_end);
        add_instruction(inst_label_end);

        free($3);
        free(label_start);
        free(label_end);
        $$ = NULL;
    }
}
;
class_def:
    CLASS IDENTIFIER LBRACE statements RBRACE
    {
        if (!lookup_symbol($2)) {
            insert_symbol($2, CLASS_SYM);
            Instruction *inst = create_comment_instruction("# Class %s defined", $2);
            add_instruction(inst);
        } else {
            Instruction *inst = create_comment_instruction("# Warning: Redefinition of class %s", $2);
            add_instruction(inst);
        }
        free($2);
        $$ = NULL;
    }
;

func_def:
    DEF IDENTIFIER LPAREN param_list RPAREN LBRACE statements RBRACE
    {
        if (!lookup_symbol($2)) {
            insert_symbol($2, FUNC);

            Instruction *inst_func = create_function_instruction($2);
            add_instruction(inst_func);

            if ($4 && strlen($4) > 0) {
                char *param_copy = strdup($4);
                char *token = strtok(param_copy, ",");
                while (token) {
                    // Trim whitespace
                    while (*token == ' ') token++;
                    char *end = token + strlen(token) - 1;
                    while (end > token && *end == ' ') *end-- = '\0';
                    
                    insert_symbol(token, VAR);
                    Instruction *param_inst = create_param_instruction(token);
                    add_instruction(param_inst);
                    token = strtok(NULL, ",");
                }
                free(param_copy);
            }

            Instruction *inst_endfunc = create_endfunction_instruction();
            add_instruction(inst_endfunc);
        } else {
            Instruction *inst = create_comment_instruction("# Warning: Redefinition of function %s", $2);
            add_instruction(inst);
        }
        free($2);
        if ($4) free($4);
        $$ = NULL;
    }
;

expression:
    primary_expression                  { $$ = $1; }
  | expression PLUS expression         { 
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, $1, "+", $3));
        free($1); free($3);
        $$ = temp;
    }
  | expression MINUS expression        { 
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, $1, "-", $3));
        free($1); free($3);
        $$ = temp;
    }
  | expression MUL expression          { 
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, $1, "*", $3));
        free($1); free($3);
        $$ = temp;
    }
  | expression DIV expression          { 
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, $1, "/", $3));
        free($1); free($3);
        $$ = temp;
    }
  | expression EQ expression           {
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, $1, "==", $3));
        free($1); free($3);
        $$ = temp;
    }
  | expression NEQ expression          {
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, $1, "!=", $3));
        free($1); free($3);
        $$ = temp;
    }
  | expression LT expression           {
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, $1, "<", $3));
        free($1); free($3);
        $$ = temp;
    }
  | expression GT expression           {
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, $1, ">", $3));
        free($1); free($3);
        $$ = temp;
    }
  | expression LE expression           {
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, $1, "<=", $3));
        free($1); free($3);
        $$ = temp;
    }
  | expression GE expression           {
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, $1, ">=", $3));
        free($1); free($3);
        $$ = temp;
    }
;

primary_expression:
    NUMBER
    {
        $$ = strdup($1);
        free($1);
    }
  | STRING
    {
        int len = strlen($1);
        char *quoted = malloc(len + 3);
        sprintf(quoted, "\"%s\"", $1);
        free($1);
        $$ = quoted;
    }
  | IDENTIFIER
    {
        if (!lookup_symbol($1)) {
            fprintf(stderr, "Warning: Undeclared variable '%s'\n", $1);
        }
        $$ = strdup($1);
        free($1);
    }
  | IDENTIFIER LPAREN arg_list RPAREN
    {
        char *code = malloc(strlen($1) + 20);
        sprintf(code, "call %s", $1);
        free($1);
        if ($3) free($3);
        $$ = code;
    }
  | expression DOT IDENTIFIER LPAREN arg_list RPAREN
    {
        char *code = malloc(strlen($1) + strlen($3) + 20);
        sprintf(code, "call_method %s.%s", $1, $3);
        free($1);
        free($3);
        if ($5) free($5);
        $$ = code;
    }
  | LPAREN expression RPAREN
    { 
        $$ = $2; 
    }
;

param_list:
    /* empty */
    {
        $$ = strdup("");
    }
  | IDENTIFIER
    {
        $$ = strdup($1);
        free($1);
    }
  | param_list COMMA IDENTIFIER
    {
        char *combined = malloc(strlen($1) + strlen($3) + 2);
        sprintf(combined, "%s,%s", $1, $3);
        free($1);
        free($3);
        $$ = combined;
    }
;

arg_list:
    /* empty */
    {
        $$ = strdup("");
    }
  | expression
    {
        $$ = strdup($1);
        free($1);
    }
  | arg_list COMMA expression
    {
        char *combined = malloc(strlen($1) + strlen($3) + 2);
        sprintf(combined, "%s,%s", $1, $3);
        free($1);
        free($3);
        $$ = combined;
    }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}