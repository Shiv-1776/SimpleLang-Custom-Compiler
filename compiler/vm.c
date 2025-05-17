#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VARS 100
#define MAX_LINE 256

typedef struct {
    char name[32];
    int value;
} Variable;

int parse_expr(void);  // Forward declaration

Variable vars[MAX_VARS];
int var_count = 0;

int get_var_index(const char *name) {
    for (int i = 0; i < var_count; i++)
        if (strcmp(vars[i].name, name) == 0) return i;
    return -1;
}

int get_var_value(const char *name) {
    int idx = get_var_index(name);
    return idx >= 0 ? vars[idx].value : 0;
}

void set_var_value(const char *name, int val) {
    int idx = get_var_index(name);
    if (idx >= 0)
        vars[idx].value = val;
    else if (var_count < MAX_VARS) {
        strcpy(vars[var_count].name, name);
        vars[var_count].value = val;
        var_count++;
    }
}

const char *expr_ptr;

void skip_spaces() {
    while (isspace(*expr_ptr)) expr_ptr++;
}

int parse_factor() {
    skip_spaces();

    if (*expr_ptr == '(') {
        expr_ptr++; // consume '('
        int val = parse_expr();
        skip_spaces();
        if (*expr_ptr == ')') {
            expr_ptr++; // consume ')'
        } else {
            printf("Error: missing closing parenthesis\n");
            exit(1);
        }
        return val;
    }

    int sign = 1;
    if (*expr_ptr == '-') {
        sign = -1;
        expr_ptr++;
        skip_spaces();
    }

    if (isdigit(*expr_ptr)) {
        int val = 0;
        while (isdigit(*expr_ptr)) {
            val = val * 10 + (*expr_ptr - '0');
            expr_ptr++;
        }
        return val * sign;
    }

    if (isalpha(*expr_ptr) || *expr_ptr == '_') {
        char varname[64];
        int i = 0;
        while (isalnum(*expr_ptr) || *expr_ptr == '_') {
            if (i < 63) varname[i++] = *expr_ptr;
            expr_ptr++;
        }
        varname[i] = '\0';
        return sign * get_var_value(varname);
    }

    printf("Error: unexpected character '%c'\n", *expr_ptr);
    exit(1);
    return 0;
}

int parse_term() {
    int val = parse_factor();
    while (1) {
        skip_spaces();
        if (*expr_ptr == '*') {
            expr_ptr++;
            val *= parse_factor();
        } else if (*expr_ptr == '/') {
            expr_ptr++;
            int divisor = parse_factor();
            if (divisor == 0) {
                printf("Error: division by zero\n");
                exit(1);
            }
            val /= divisor;
        } else if (*expr_ptr == '%') {
            expr_ptr++;
            int divisor = parse_factor();
            if (divisor == 0) {
                printf("Error: modulo by zero\n");
                exit(1);
            }
            val %= divisor;
        } else {
            break;
        }
    }
    return val;
}

int parse_expr() {
    int val = parse_term();
    while (1) {
        skip_spaces();
        if (*expr_ptr == '+') {
            expr_ptr++;
            val += parse_term();
        } else if (*expr_ptr == '-') {
            expr_ptr++;
            val -= parse_term();
        } else {
            break;
        }
    }
    return val;
}

int eval_expr(const char *expr) {
    expr_ptr = expr;
    int val = parse_expr();
    skip_spaces();
    if (*expr_ptr != '\0') {
        printf("Error: unexpected characters at end of expression\n");
        exit(1);
    }
    return val;
}

int is_number(const char *s) {
    if (*s == '-' || *s == '+') s++;
    while (*s) if (!isdigit(*s++)) return 0;
    return 1;
}

void handle_print(const char *arg) {
    while (*arg == ' ') arg++;
    int len = strlen(arg);
    while (len > 0 && (arg[len - 1] == '\n' || arg[len - 1] == ' ')) len--;

    char trimmed[256];
    strncpy(trimmed, arg, len);
    trimmed[len] = '\0';

    // If it's a quoted string, print as-is
    if (trimmed[0] == '"' && trimmed[len - 1] == '"') {
        trimmed[len - 1] = '\0';     // remove closing quote
        printf("%s\n", trimmed + 1); // skip opening quote
        return;
    }

    // If it contains an arithmetic operator, evaluate it
    if (strpbrk(trimmed, "+-*/%")) {
        printf("%d\n", eval_expr(trimmed));
        return;
    }

    // If it's just a number, print it
    if (is_number(trimmed)) {
        printf("%d\n", atoi(trimmed));
        return;
    }

    // Otherwise, treat as variable
    printf("%d\n", get_var_value(trimmed));
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <icg_file>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("Cannot open file");
        return 1;
    }

    char line[MAX_LINE];
    int in_func = 0;

    while (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\r\n")] = '\0';
        if (strlen(line) == 0) continue;

        if (strncmp(line, "function ", 9) == 0) {
            in_func = 1;
            continue;
        } else if (strncmp(line, "endfunction", 11) == 0) {
            in_func = 0;
            continue;
        } else if (in_func) {
            continue; // skip function body
        }

        if (strncmp(line, "print ", 6) == 0) {
            handle_print(line + 6);
            continue;
        }

        if (strchr(line, '=')) {
            char *eq = strchr(line, '=');
            *eq = '\0';
            char *var = line;
            char *expr = eq + 1;

            while (*var == ' ') var++;
            while (*expr == ' ') expr++;
            char *endvar = var + strlen(var) - 1;
            while (endvar > var && *endvar == ' ') *endvar-- = '\0';
            char *endexpr = expr + strlen(expr) - 1;
            while (endexpr > expr && *endexpr == ' ') *endexpr-- = '\0';

            int val = eval_expr(expr);
            set_var_value(var, val);
            continue;
        }

        if (strncmp(line, "call ", 5) == 0) {
            printf("Function call: %s\n", line + 5);
            continue;
        }

        printf("Unknown instruction: %s\n", line);
    }

    fclose(f);
    return 0;
}
