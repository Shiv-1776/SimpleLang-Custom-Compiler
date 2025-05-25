%{
#include "parser.tab.h"
#include <string.h>

int lineno = 1;

void yyerror(const char *s);
%}

%option noyywrap

DIGIT       [0-9]
ID          [a-zA-Z_][a-zA-Z0-9_]*
STRING      \"([^\\\"]|\\.)*\"     // Handles escape sequences
WHITESPACE  [ \t]+
NEWLINE     (\r\n|\r|\n)

%%

{WHITESPACE}     { /* skip spaces and tabs */ }
{NEWLINE}        { lineno++; return NEWLINE; }

"print"          { return PRINT; }
"return"         { return RETURN; }
"if"             { return IF; }
"else"           { return ELSE; }
"while"          { return WHILE; }
"class"          { return CLASS; }
"def"            { return DEF; }
"new"            { return NEW; }

"=="             { return EQ; }
"!="             { return NEQ; }
"<="             { return LE; }
">="             { return GE; }
"<"              { return LT; }
">"              { return GT; }
"="              { return ASSIGN; }

"+"              { return PLUS; }
"-"              { return MINUS; }
"*"              { return MUL; }
"/"              { return DIV; }
"."              { return DOT; }

"("              { return LPAREN; }
")"              { return RPAREN; }
"{"              { return LBRACE; }
"}"              { return RBRACE; }
","              { return COMMA; }

{DIGIT}+         {
                    yylval.str = strdup(yytext);
                    return NUMBER;
                }

\"([^\\\"]|\\.)*\"     {
    yylval.str = strdup(yytext + 1);
    yylval.str[strlen(yylval.str) - 1] = '\0';
    return STRING;
}


{ID}             {
                    // Check for reserved keywords already handled above
                    yylval.str = strdup(yytext);
                    return IDENTIFIER;
                }

.                { printf("Unknown character: %s\n", yytext); }

%%

