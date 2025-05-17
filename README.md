# SimpleLang Compiler:
  SimpleLang is a bespoke C++-derived programming language specifically tailored for simplicity and educational use. The project includes a complete compiler     
  pipeline, with the graphical user interface written in Python.

# Features: 
- Personalized syntax of language with `.sp` extension
- Lexico analysis through **Flex**
- Yacc (Bison) Parsing
- AST building
- Intermediate Code Generation (ICG)
- Symbol Table Generation
- Virtual Machine to run ICG
- Python graphical user interface with two outputs: Program Output and Three Address Code

# Project Structure:
  SimpleLang/
  ├── compiler/
  │ └── ast.c / ast.h
  │ └── icg.c / icg.h
  Symbol table.c and symbol table.h.
  │ └── vm.c ← Virtual Machine
  │ └── parser.y ← Bison parser
  │ └── lexer.l ← Flex lexer
  │ └── main.c
  │ └── output.icg ← Intermediate Code
  │ ├── output.ir ← Intermediate Representation
  │ └── symbol_table.txt ← Generated during compilation
  The ultimate compiler executable is symbolized by simpleLang.exe.
  │. ├──. vm.exe ← VM Executable
  │ ├── gui.py ← GUI for Python
  │ └── build.bat ← Build script option
  ├── example/
  │ └── hello.sp ← SimpleLang sample code

# How to Do a Run:
  1. Build the Compiler
   • cd compiler
   • flex lexer.l
   • bison -d parser.y
   • gcc *.c -o simpleLang.exe
   • gcc vm.c -o vm.exe
   • Or use the provided build.bat (if available).

  2. Test a .sp File
   • ./simpleLang.exe ./example/hello.sp
   • ./vm.exe output.icg
  
  3. Begin GUI
   • python gui.py
   • GUI will display:
     ◦ Compiler and Virtual Machine Output
     ◦ Right: Symbol Table contents

# Example Code (hello.sp)
def greet() {
    print("Hello from SimpleLang!")
}

a = 10
b = 20
c = a + b
d=b-a
print(c)
print(d)
greet()

# Requirements:
 • C Compiler (GCC)
 • Python 3 Flex and Bison Windows OS (modify paths to Linux) 
 
 
 # Author:
   • Developed by Shiv Swaroop Sabharwal.
   • Email Address: ahivswaroopsabharwal@gmail.com
