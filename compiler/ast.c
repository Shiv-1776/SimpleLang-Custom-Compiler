#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

int label_counter = 0;

char *new_label() {
    char buf[32];
    snprintf(buf, sizeof(buf), "L%d", label_counter++);
    return strdup(buf);  // ensure strdup is declared or include <string.h>
}

Instruction *create_label_instruction(const char *label_name) {
    Instruction *inst = malloc(sizeof(Instruction));
    inst->opcode = strdup("label");
    inst->arg1 = strdup(label_name);
    inst->arg2 = NULL;
    inst->arg3 = NULL;
    inst->next = NULL;
    return inst;
}

Instruction *create_goto_instruction(const char *label_name) {
    Instruction *inst = malloc(sizeof(Instruction));
    inst->opcode = strdup("goto");
    inst->arg1 = strdup(label_name);
    inst->arg2 = NULL;
    inst->arg3 = NULL;
    inst->next = NULL;
    return inst;
}

ASTNode *create_number_node(int value) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_NUMBER;
    node->number = value;
    return node;
}

ASTNode *create_identifier_node(char *name) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_IDENTIFIER;
    node->identifier = strdup(name);
    return node;
}

ASTNode *create_assignment_node(char *name, ASTNode *value) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_ASSIGN;
    node->assign.name = strdup(name);
    node->assign.value = value;
    return node;
}

ASTNode *create_print_node(ASTNode *expr) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_PRINT;
    node->print.expr = expr;
    return node;
}

ASTNode *create_if_node(ASTNode *cond, ASTNode *if_branch, ASTNode *else_branch) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_IF;
    node->if_stmt.cond = cond;
    node->if_stmt.if_branch = if_branch;
    node->if_stmt.else_branch = else_branch;
    return node;
}

ASTNode *create_block_node(ASTNode *statements) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_BLOCK;
    node->block.statements = statements;
    return node;
}

ASTNode *create_operation_node(ASTNode *left, ASTNode *right, char op) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_OP;
    node->op.left = left;
    node->op.right = right;
    node->op.op = op;
    return node;
}

ASTNode *create_program_node(ASTNode *statements) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_PROGRAM;
    node->program.statements = statements;
    return node;
}

ASTNode *create_statements_node(ASTNode *first, ASTNode *second) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = NODE_STATEMENTS;
    node->statements.first = first;
    node->statements.second = second;
    return node;
}

void generate_code(ASTNode *root) {
    printf("AST created. Add code generation here.\n");
}
