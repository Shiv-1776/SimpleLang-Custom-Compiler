#ifndef AST_H
#define AST_H

typedef struct ASTNode {
    enum { NODE_NUMBER, NODE_IDENTIFIER, NODE_ASSIGN, NODE_PRINT, NODE_IF, NODE_BLOCK, NODE_OP, NODE_PROGRAM, NODE_STATEMENTS } type;
    union {
        int number;
        char *identifier;
        struct {
            char *name;
            struct ASTNode *value;
        } assign;
        struct {
            struct ASTNode *expr;
        } print;
        struct {
            struct ASTNode *cond;
            struct ASTNode *if_branch;
            struct ASTNode *else_branch;
        } if_stmt;
        struct {
            struct ASTNode *statements;
        } block;
        struct {
            struct ASTNode *left;
            struct ASTNode *right;
            char op;
        } op;
        struct {
            struct ASTNode *statements;
        } program;
        struct {
            struct ASTNode *first;
            struct ASTNode *second;
        } statements;
    };
} ASTNode;

ASTNode *create_number_node(int value);
ASTNode *create_identifier_node(char *name);
ASTNode *create_assignment_node(char *name, ASTNode *value);
ASTNode *create_print_node(ASTNode *expr);
ASTNode *create_if_node(ASTNode *cond, ASTNode *if_branch, ASTNode *else_branch);
ASTNode *create_block_node(ASTNode *statements);
ASTNode *create_operation_node(ASTNode *left, ASTNode *right, char op);
ASTNode *create_program_node(ASTNode *statements);
ASTNode *create_statements_node(ASTNode *first, ASTNode *second);

void generate_code(ASTNode *root); // stub

void optimize_instructions(); // for constant folding

void add_instruction(Instruction *inst); // if used directly

#endif