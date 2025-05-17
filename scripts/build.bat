@echo off
echo Building SimpleLang...

REM Run from MSYS2 MinGW 64-bit shell for best results
bison -d compiler/parser.y
flex compiler/lexer.l
gcc -o simple compiler/main.c compiler/parser.tab.c compiler/lex.yy.c -lfl

echo Done! Run with: simple < examples\hello.sp
