#ifndef ICG_H
#define ICG_H

typedef enum {
    INST_ASSIGN,
    INST_BINOP,
    INST_PRINT,
    INST_RETURN,
    INST_IF_FALSE_GOTO,
    INST_GOTO,
    INST_LABEL,
    INST_FUNCTION,
    INST_ENDFUNCTION,
    INST_COMMENT
} InstructionType;

typedef struct Instruction {
    InstructionType type;
    char *result;
    char *arg1;
    char *op;
    char *arg2;
    struct Instruction *next;
} Instruction;

// Global instruction list
extern Instruction *head;
extern Instruction *tail;

// Function declarations
Instruction *create_instruction(InstructionType type);
Instruction *create_assign_instruction(const char *result, const char *arg1);
Instruction *create_binop_instruction(const char *result, const char *arg1, const char *op, const char *arg2);
Instruction *create_print_instruction(const char *arg1);
Instruction *create_return_instruction(const char *arg1);
Instruction *create_if_false_goto_instruction(const char *cond, const char *label);
Instruction *create_goto_instruction(const char *label);
Instruction *create_label_instruction(const char *label);
Instruction *create_function_instruction(const char *name);
Instruction *create_endfunction_instruction();
//Instruction *create_comment_instruction(const char *comment);

void append_instruction(Instruction *instr);
char *generate_temp();
char *generate_label();

void optimize_constant_folding();
void write_instructions_to_file(FILE *file);

void optimize_instructions(); // for constant folding
Instruction *create_comment_instruction(const char *fmt, ...);
void add_instruction(Instruction *instr);



#endif
