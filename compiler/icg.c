#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "icg.h"
#ifdef _WIN32
#include <io.h>
#include <windows.h>
#endif

Instruction *head = NULL;
Instruction *tail = NULL;

static int temp_counter = 0;
static int label_counter = 0;

char* generate_temp() {
    char *temp = malloc(16);
    sprintf(temp, "t%d", temp_counter++);
    return temp;
}

char* generate_label() {
    char *label = malloc(16);
    sprintf(label, "L%d", label_counter++);
    return label;
}

void add_instruction(Instruction *inst) {
    inst->next = NULL;
    if (!head) {
        head = tail = inst;
    } else {
        tail->next = inst;
        tail = inst;
    }
}

Instruction* create_instruction(InstructionType type) {
    Instruction *inst = malloc(sizeof(Instruction));
    inst->type = type;
    inst->result = NULL;
    inst->arg1 = NULL;
    inst->arg2 = NULL;
    inst->op = NULL;
    inst->next = NULL;
    return inst;
}

Instruction* create_assign_instruction(const char *result, const char *arg1) {
    Instruction *inst = create_instruction(INST_ASSIGN);
    inst->result = strdup(result);
    inst->arg1 = strdup(arg1);
    return inst;
}

Instruction* create_binop_instruction(const char *result, const char *arg1, const char *op, const char *arg2) {
    Instruction *inst = create_instruction(INST_BINOP);
    inst->result = strdup(result);
    inst->arg1 = strdup(arg1);
    inst->op = strdup(op);
    inst->arg2 = strdup(arg2);
    return inst;
}

Instruction* create_print_instruction(const char *arg1) {
    Instruction *inst = create_instruction(INST_PRINT);
    inst->arg1 = strdup(arg1);
    return inst;
}

Instruction* create_return_instruction(const char *arg1) {
    Instruction *inst = create_instruction(INST_RETURN);
    inst->arg1 = strdup(arg1);
    return inst;
}

Instruction* create_if_false_goto_instruction(const char *arg1, const char *label) {
    Instruction *inst = create_instruction(INST_IF_FALSE_GOTO);
    inst->arg1 = strdup(arg1);
    inst->result = strdup(label);
    return inst;
}

Instruction* create_goto_instruction(const char *label) {
    Instruction *inst = create_instruction(INST_GOTO);
    inst->result = strdup(label);
    return inst;
}

Instruction* create_label_instruction(const char *label) {
    Instruction *inst = create_instruction(INST_LABEL);
    inst->result = strdup(label);
    return inst;
}

Instruction* create_function_instruction(const char *func_name) {
    Instruction *inst = create_instruction(INST_FUNCTION);
    inst->result = strdup(func_name);
    return inst;
}

Instruction* create_endfunction_instruction() {
    return create_instruction(INST_ENDFUNCTION);
}

Instruction* create_comment_instruction(const char *fmt, ...) {
    Instruction *inst = create_instruction(INST_COMMENT);

    va_list args;
    va_start(args, fmt);

    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    inst->result = strdup(buffer);
    return inst;
}

void optimize_instructions() {
    Instruction *curr = head, *prev = NULL;

    while (curr) {
        if (curr->type == INST_BINOP && curr->arg1 && curr->arg2 && curr->op) {
            char *endptr1, *endptr2;
            long val1 = strtol(curr->arg1, &endptr1, 10);
            long val2 = strtol(curr->arg2, &endptr2, 10);

            if (*endptr1 == '\0' && *endptr2 == '\0') {
                long result;
                if (strcmp(curr->op, "+") == 0) result = val1 + val2;
                else if (strcmp(curr->op, "-") == 0) result = val1 - val2;
                else if (strcmp(curr->op, "*") == 0) result = val1 * val2;
                else if (strcmp(curr->op, "/") == 0) result = val2 != 0 ? val1 / val2 : 0;
                else result = 0;

                Instruction *assign = create_assign_instruction(curr->result, "0");
                sprintf(assign->arg1, "%ld", result);

                assign->next = curr->next;
                if (prev) prev->next = assign;
                else head = assign;

                if (tail == curr) tail = assign;

                free(curr->arg1);
                free(curr->arg2);
                free(curr->op);
                free(curr->result);
                free(curr);

                curr = assign;
            }
        }
        prev = curr;
        curr = curr->next;
    }
}
Instruction* create_param_instruction(const char *arg1) {
    Instruction *inst = create_instruction(INST_ASSIGN); // Or a new type if you're handling PARAM differently
    inst->arg1 = strdup(arg1);
    return inst;
}


void write_instructions_to_file(FILE *file) {
    Instruction *curr = head;
    while (curr) {
        switch (curr->type) {
            case INST_ASSIGN:
                fprintf(file, "%s = %s\n", curr->result, curr->arg1);
                break;
            case INST_BINOP:
                fprintf(file, "%s = %s %s %s\n", curr->result, curr->arg1, curr->op, curr->arg2);
                break;
            case INST_PRINT:
                fprintf(file, "print %s\n", curr->arg1);
                break;
            case INST_RETURN:
                fprintf(file, "return %s\n", curr->arg1);
                break;
            case INST_IF_FALSE_GOTO:
                fprintf(file, "ifFalse %s goto %s\n", curr->arg1, curr->result);
                break;
            case INST_GOTO:
                fprintf(file, "goto %s\n", curr->result);
                break;
            case INST_LABEL:
                fprintf(file, "%s:\n", curr->result);
                break;
            case INST_FUNCTION:
                fprintf(file, "function %s:\n", curr->result);
                break;
            case INST_ENDFUNCTION:
                fprintf(file, "endfunction\n");
                break;
            case INST_COMMENT:
                fprintf(file, "%s\n", curr->result);
                break;
        }
        curr = curr->next;
    }
}
bool instructions_equal(Instruction *a, Instruction *b) {
    if (a->type != b->type) return false;

    #define STR_EQUAL(x,y) (((x) == NULL && (y) == NULL) || ((x) && (y) && strcmp(x,y) == 0))

    switch (a->type) {
        case INST_ASSIGN:
            return STR_EQUAL(a->result, b->result) && STR_EQUAL(a->arg1, b->arg1);
        case INST_BINOP:
            return STR_EQUAL(a->result, b->result) && STR_EQUAL(a->arg1, b->arg1)
                && STR_EQUAL(a->op, b->op) && STR_EQUAL(a->arg2, b->arg2);
        case INST_PRINT:
        case INST_RETURN:
            return STR_EQUAL(a->arg1, b->arg1);
        case INST_IF_FALSE_GOTO:
            return STR_EQUAL(a->arg1, b->arg1) && STR_EQUAL(a->result, b->result);
        case INST_GOTO:
        case INST_LABEL:
        case INST_FUNCTION:
            return STR_EQUAL(a->result, b->result);
        case INST_ENDFUNCTION:
            return true; // no fields to compare
        case INST_COMMENT:
            return STR_EQUAL(a->result, b->result);
        default:
            return false;
    }
    #undef STR_EQUAL
}

