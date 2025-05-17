#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

#define TABLE_SIZE 128

static Symbol *table[TABLE_SIZE];

unsigned int hash(const char *str) {
    unsigned int hash = 0;
    while (*str)
        hash = (hash << 2) ^ *str++;
    return hash % TABLE_SIZE;
}

void init_symbol_table() {
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = NULL;
}

void free_symbol_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Symbol *sym = table[i];
        while (sym) {
            Symbol *tmp = sym;
            sym = sym->next;
            free(tmp->name);
            free(tmp);
        }
    }
}

int insert_symbol(const char *name, SymbolType type) {
    if (lookup_symbol(name)) return 0;

    unsigned int idx = hash(name);
    Symbol *sym = (Symbol *)malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->type = type;
    sym->next = table[idx];
    table[idx] = sym;
    return 1;
}

int lookup_symbol(const char *name) {
    unsigned int idx = hash(name);
    Symbol *sym = table[idx];
    while (sym) {
        if (strcmp(sym->name, name) == 0)
            return 1;
        sym = sym->next;
    }
    return 0;
}

void print_symbols() {
    printf("Symbol Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Symbol *sym = table[i];
        while (sym) {
            const char *type_str = sym->type == VAR ? "VAR" :
                                   sym->type == FUNC ? "FUNC" : "CLASS";
            printf("  %s : %s\n", sym->name, type_str);
            sym = sym->next;
        }
    }
}
