#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#include "icg.h"

FILE *icg_file = NULL;
extern int yyparse(void);
extern FILE *yyin;

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source.sp>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("fopen");
        return 1;
    }

    icg_file = fopen("output.icg", "w");
    if (!icg_file) {
        perror("fopen");
        return 1;
    }

    init_symbol_table();
    yyparse();

    // Optimization and final ICG output
    optimize_instructions(); // Apply constant folding and simplifications
    write_instructions_to_file(icg_file);

    print_symbols();
    free_symbol_table();

    fclose(yyin);
    fclose(icg_file);
    return 0;
}
