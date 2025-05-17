#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef enum { VAR, FUNC, CLASS_SYM } SymbolType;

typedef struct Symbol {
    char *name;
    SymbolType type;
    struct Symbol *next;
} Symbol;

void init_symbol_table();
void free_symbol_table();
int insert_symbol(const char *name, SymbolType type);
int lookup_symbol(const char *name);
void print_symbols();

#endif
