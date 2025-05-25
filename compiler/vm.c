#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VARS 100
#define MAX_LINE 256
#define MAX_LABELS 100
#define MAX_STACK 100

typedef struct {
    char name[32];
    int value;
} Variable;

typedef struct {
    char label[32];
    long file_pos;
} Label;

Variable vars[MAX_VARS];
int var_count = 0;

Label labels[MAX_LABELS];
int label_count = 0;

long call_stack[MAX_STACK];
int call_top = -1;

FILE *source;

int label_counter = 0;

char* new_label() {
    static char buf[32];
    snprintf(buf, sizeof(buf), "L%d", label_count++);
    return buf;
}
void trim(char *str) {
    // Trim leading spaces
    while (isspace(*str)) str++;

    // Copy to buffer
    char *end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) *end-- = '\0';
}


int get_var_index(const char *name) {
    char trimmed[32];
    strncpy(trimmed, name, 31);
    trimmed[31] = '\0';
    trim(trimmed);

    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, trimmed) == 0) return i;
    }
    return -1;
}


int get_var_value(const char *name) {
    int idx = get_var_index(name);
    // printf("[DEBUG] get_var_value(%s) = %s\n", name, idx >= 0 ? "FOUND" : "UNDEFINED");
    return idx >= 0 ? vars[idx].value : 0;
}


void set_var_value(const char *name, int val) {
    char trimmed[32];
    strncpy(trimmed, name, 31);
    trimmed[31] = '\0';
    trim(trimmed);

    int idx = get_var_index(trimmed);
    if (idx >= 0) {
        vars[idx].value = val;
    } else if (var_count < MAX_VARS) {
        strcpy(vars[var_count].name, trimmed);
        vars[var_count].value = val;
        var_count++;
    }
    // Optional debug
    // printf("[DEBUG] set_var_value(%s , %d)\n", trimmed, val);
}


int is_number(const char *s) {
    if (*s == '-' || *s == '+') s++;
    while (*s) if (!isdigit(*s++)) return 0;
    return 1;
}

// Expression evaluation
const char *expr_ptr;

void skip_spaces() {
    while (isspace(*expr_ptr)) expr_ptr++;
}

int parse_expr(void);  // forward declaration

int parse_factor() {
    skip_spaces();

    if (*expr_ptr == '(') {
        expr_ptr++;
        int val = parse_expr();
        skip_spaces();
        if (*expr_ptr == ')') expr_ptr++;
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
        while (isdigit(*expr_ptr)) val = val * 10 + (*expr_ptr++ - '0');
        return val * sign;
    }

    if (isalpha(*expr_ptr) || *expr_ptr == '_') {
        char name[64];
        int i = 0;
        while (isalnum(*expr_ptr) || *expr_ptr == '_') {
            if (i < 63) name[i++] = *expr_ptr;
            expr_ptr++;
        }
        name[i] = '\0';
        return sign * get_var_value(name);
    }

    printf("Error: unexpected character '%c'\n", *expr_ptr);
    exit(1);
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
            int d = parse_factor();
            if (d == 0) {
                printf("Error: divide by zero\n");
                exit(1);
            }
            val /= d;
        } else if (*expr_ptr == '%') {
            expr_ptr++;
            int d = parse_factor();
            if (d == 0) {
                printf("Error: modulo by zero\n");
                exit(1);
            }
            val %= d;
        } else break;
    }
    return val;
}

// Renamed from previous parse_expr, handles + and -
int parse_add_sub() {
    int val = parse_term();
    while (1) {
        skip_spaces();
        if (*expr_ptr == '+') {
            expr_ptr++;
            val += parse_term();
        } else if (*expr_ptr == '-') {
            expr_ptr++;
            val -= parse_term();
        } else break;
    }
    return val;
}

// New parse_expr with comparison operators support
int parse_expr() {
    int left = parse_add_sub();
    skip_spaces();

    if (strncmp(expr_ptr, "==", 2) == 0) {
        expr_ptr += 2;
        int right = parse_add_sub();
        return left == right;
    } else if (strncmp(expr_ptr, "!=", 2) == 0) {
        expr_ptr += 2;
        int right = parse_add_sub();
        return left != right;
    } else if (strncmp(expr_ptr, "<=", 2) == 0) {
        expr_ptr += 2;
        int right = parse_add_sub();
        return left <= right;
    } else if (strncmp(expr_ptr, ">=", 2) == 0) {
        expr_ptr += 2;
        int right = parse_add_sub();
        return left >= right;
    } else if (*expr_ptr == '<') {
        expr_ptr++;
        int right = parse_add_sub();
        return left < right;
    } else if (*expr_ptr == '>') {
        expr_ptr++;
        int right = parse_add_sub();
        return left > right;
    }

    return left;
}

int eval_expr(const char *expr) {
    expr_ptr = expr;
    int val = parse_expr();
    skip_spaces();
    if (*expr_ptr != '\0') {
        printf("Error: invalid characters at end of expression\n");
        exit(1);
    }
    return val;
}

void handle_print(const char *arg) {
    while (*arg == ' ') arg++;
    int len = strlen(arg);
    while (len > 0 && (arg[len - 1] == '\n' || arg[len - 1] == ' ')) len--;

    char trimmed[256];
    strncpy(trimmed, arg, len);
    trimmed[len] = '\0';

    if (trimmed[0] == '"' && trimmed[len - 1] == '"') {
        trimmed[len - 1] = '\0';
        printf("%s\n", trimmed + 1);
        return;
    }

    if (strpbrk(trimmed, "+-*/%")) {
        printf("%d\n", eval_expr(trimmed));
        return;
    }

    if (is_number(trimmed)) {
        printf("%d\n", atoi(trimmed));
        return;
    }

    printf("%d\n", get_var_value(trimmed));
}

void preprocess_labels(FILE *f) {
    char line[MAX_LINE];
    long pos;

    while ((pos = ftell(f)), fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\r\n")] = 0;
        if (strchr(line, ':')) {
            char *colon = strchr(line, ':');
            *colon = '\0';
            char *label_ptr = line;
            while (*label_ptr == ' ') label_ptr++;
            char *end = line + strlen(line) - 1;
            while (end > line && isspace(*end)) *end-- = '\0';

            printf("Found label '%s' at pos %ld\n", label_ptr, pos);

            if (label_count < MAX_LABELS) {
                strcpy(labels[label_count].label, label_ptr);
                labels[label_count].file_pos = pos;
                label_count++;
            }
        }
    }

    rewind(f);
}

long find_label_pos(const char *label) {
    for (int i = 0; i < label_count; i++)
        if (strcmp(labels[i].label, label) == 0)
            return labels[i].file_pos;
    return -1;
}

void push(long pos) {
    if (call_top < MAX_STACK - 1) {
        call_stack[++call_top] = pos;
    } else {
        printf("Error: call stack overflow\n");
        exit(1);
    }
}

long pop() {
    if (call_top >= 0) {
        return call_stack[call_top--];
    } else {
        printf("Error: call stack underflow\n");
        exit(1);
    }
}

void execute_line(char *line) {
    if (line[0] == '#' || strlen(line) == 0) return;

    if (strncmp(line, "print ", 6) == 0) {
        handle_print(line + 6);
    } else if (strchr(line, '=') != NULL) {
        char *eq = strchr(line, '=');
        *eq = '\0';
        char *var = line;
        char *expr = eq + 1;
        while (*var == ' ') var++;
        while (*expr == ' ') expr++;

        int val = eval_expr(expr);
        set_var_value(var, val);
    } else if (strncmp(line, "goto ", 5) == 0) {
        char *label = line + 5;
        while (*label == ' ') label++;
        long pos = find_label_pos(label);
        if (pos >= 0) fseek(source, pos, SEEK_SET);
        else printf("Label not found: %s\n", label);
    } else if (strncmp(line, "ifFalse ", 8) == 0) {
        char var[64], label[64];
        if (sscanf(line, "ifFalse %s goto %s", var, label) == 2) {
            if (!get_var_value(var)) {
                long pos = find_label_pos(label);
                if (pos >= 0) fseek(source, pos, SEEK_SET);
                else printf("Label not found: %s\n", label);
            }
        }
    } else if (strncmp(line, "call ", 5) == 0) {
        char *func = line + 5;
        while (*func == ' ') func++;
        long pos = find_label_pos(func);
        if (pos >= 0) {
            push(ftell(source));
            fseek(source, pos, SEEK_SET);
        } else {
            printf("Function label not found: %s\n", func);
        }
    } else if (strcmp(line, "ret") == 0) {
        long ret_pos = pop();
        fseek(source, ret_pos, SEEK_SET);
    } else if (strchr(line, ':')) {
        // label definition, skip
    } else {
        printf("Unknown instruction: %s\n", line);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <icg_file>\n", argv[0]);
        return 1;
    }

    source = fopen(argv[1], "r");
    if (!source) {
        perror("Cannot open file");
        return 1;
    }

    // Count total lines first
    int total_lines = 0;
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), source)) {
        total_lines++;
    }
    rewind(source);  // Reset to beginning

    preprocess_labels(source);  // Preprocess after rewind

    // Execute only first half
    int current_line = 0;
    while (fgets(line, sizeof(line), source)) {
        if (current_line >= total_lines / 2) break;

        line[strcspn(line, "\r\n")] = 0;
        execute_line(line);
        current_line++;
    }

    fclose(source);
    return 0;
}
