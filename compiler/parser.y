%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "icg.h"

extern FILE *icg_file;

// We use icg.c's temp/label generators
char* new_temp() { return generate_temp(); }
char* new_label() { return generate_label(); }

extern int yylex(void);
extern int yylineno;
void yyerror(const char *s);
%}

%union {
    int    num;
    char  *str;
}

%token <num>   NUMBER
%token <str>   STRING IDENTIFIER

%token         CLASS DEF PRINT RETURN NEW IF ELSE WHILE
%token         EQ NEQ LE GE LT GT ASSIGN
%token         PLUS MINUS MUL DIV DOT
%token         LPAREN RPAREN LBRACE RBRACE COMMA NEWLINE

%left          PLUS MINUS
%left          MUL DIV
%nonassoc      LOWER_THAN_ELSE
%nonassoc      ELSE

%type <str>    expression
%type <str> statement assignment print_stmt return_stmt if_stmt while_stmt class_def func_def

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
    | statements NEWLINE
    | statements statement
    | statements statement NEWLINE
;

statement:
    assignment
  | print_stmt
  | return_stmt
  | if_stmt
  | while_stmt
  | class_def
  | func_def
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

/* Improved label management for if and if-else */
if_stmt:
    IF LPAREN expression RPAREN LBRACE statements RBRACE %prec LOWER_THAN_ELSE
    {
        char *label_end = new_label();

        Instruction *inst_if_false = create_if_false_goto_instruction($3, label_end);
        add_instruction(inst_if_false);

        // The statements inside { } already added instructions

        Instruction *inst_label_end = create_label_instruction(label_end);
        add_instruction(inst_label_end);

        free($3);
        free(label_end);
        $$ = NULL;
    }
  | IF LPAREN expression RPAREN LBRACE statements RBRACE ELSE LBRACE statements RBRACE
    {
        char *label_else = new_label();
        char *label_end = new_label();

        Instruction *inst_if_false = create_if_false_goto_instruction($3, label_else);
        add_instruction(inst_if_false);

        Instruction *inst_goto_end = create_goto_instruction(label_end);
        add_instruction(inst_goto_end);

        Instruction *inst_label_else = create_label_instruction(label_else);
        add_instruction(inst_label_else);

        // The else statements already added instructions

        Instruction *inst_label_end = create_label_instruction(label_end);
        add_instruction(inst_label_end);

        free($3);
        free(label_else);
        free(label_end);
        $$ = NULL;
    }
;

while_stmt:
    WHILE LPAREN expression RPAREN LBRACE statements RBRACE
    {
        char *label_start = new_label();
        char *label_end = new_label();

        Instruction *inst_label_start = create_label_instruction(label_start);
        add_instruction(inst_label_start);

        Instruction *inst_if_false = create_if_false_goto_instruction($3, label_end);
        add_instruction(inst_if_false);

        // loop body statements already added

        Instruction *inst_goto_start = create_goto_instruction(label_start);
        add_instruction(inst_goto_start);

        Instruction *inst_label_end = create_label_instruction(label_end);
        add_instruction(inst_label_end);

        free($3);
        free(label_start);
        free(label_end);
        $$ = NULL;
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

            // function body already generated

            Instruction *inst_endfunc = create_endfunction_instruction();
            add_instruction(inst_endfunc);
        } else {
            Instruction *inst = create_comment_instruction("# Warning: Redefinition of function %s", $2);
            add_instruction(inst);
        }
        free($2);
        $$ = NULL;
    }
;

expression:
    STRING
    {
        // Add quotes around the string literal
        int len = strlen($1);
        char *quoted = malloc(len + 3); // 2 quotes + \0
        sprintf(quoted, "\"%s\"", $1);
        free($1);
        $$ = quoted;
    }

  | NUMBER
    {
        char buf[32];
        snprintf(buf, sizeof(buf), "%d", $1);
        $$ = strdup(buf);
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
        // call function, ignoring args for now
        char *code = malloc(strlen($1) + 20);
        sprintf(code, "call %s", $1);
        $$ = code;
        free($1);
    }
  | expression DOT IDENTIFIER LPAREN arg_list RPAREN
    {
        char *code = malloc(strlen($1) + strlen($3) + 20);
        sprintf(code, "call_method %s.%s", $1, $3);
        free($1);
        free($3);
        $$ = code;
    }
  | expression PLUS expression {
        char *temp = new_temp();
        Instruction *inst = create_binop_instruction(temp, $1, "+", $3);
        add_instruction(inst);
        free($1);
        free($3);
        $$ = temp;
    }
  | expression MINUS expression {
        char *temp = new_temp();
        Instruction *inst = create_binop_instruction(temp, $1, "-", $3);
        add_instruction(inst);
        free($1);
        free($3);
        $$ = temp;
    }
  | expression MUL expression {
        char *temp = new_temp();
        Instruction *inst = create_binop_instruction(temp, $1, "*", $3);
        add_instruction(inst);
        free($1);
        free($3);
        $$ = temp;
    }
  | expression DIV expression {
        char *temp = new_temp();
        Instruction *inst = create_binop_instruction(temp, $1, "/", $3);
        add_instruction(inst);
        free($1);
        free($3);
        $$ = temp;
    }
  | LPAREN expression RPAREN
    {
        $$ = $2;
    }
;

param_list:
    /* empty */
  | IDENTIFIER
  | param_list COMMA IDENTIFIER
;

arg_list:
    /* empty */
  | expression
  | arg_list COMMA expression
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parse error on line %d: %s\n", yylineno, s);
}
