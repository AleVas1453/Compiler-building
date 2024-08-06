#ifndef QUADFUNC_H
#define QUADFUNC_H
#include "quadfunc.h"
#endif

/*xrisimopoioume epithema _v gia apofigi sygkroysis me ta opcodes ths triths fashs */
typedef enum vmopcode{
    assign_v,         add_v,            sub_v, 
    mul_v,            div_v,            mod_v, 
    uminus_v,         and_v,            or_v,
    not_v,            jeq_v,            jne_v, 
    jle_v,            jge_v,            jlt_v,
    jgt_v,            call_v,           pusharg_v,
    funcenter_v,      funcexit_v,       newtable_v,
    tablegetelem_v,   tablesetelem_v,   nop_v,
    jump_v

}vmopcode;


typedef enum vmarg_t {

    label_a     = 0,
    global_a    = 1,
    formal_a    = 2,
    local_a     = 3,
    number_a    = 4,
    string_a    = 5,
    bool_a      = 6,
    nil_a       = 7,
    userfunc_a  = 8,
    libfunc_a   = 9,
    retval_a    = 10

}vmarg_t;

typedef struct vmarg{

    vmarg_t type;
    unsigned val;

}vmarg;

/*antistoixia me ta quads , oi instructions exoun 4 pedia */
typedef struct instruction{
    vmopcode    opcode;
    vmarg*       result;
    vmarg*       arg1;
    vmarg*       arg2;
    unsigned    srcLine;
}instruction;

typedef struct userfunc{

    unsigned    address;
    unsigned    localSize;
    char*       id;

}userfunc;

typedef struct incomplete_jump{

    unsigned            instrNo;    /* taddress tou inc_jump */
    unsigned            iaddress;   /* iaddress tou quad, pou einai to target se endiameso code */
    struct incomplete_jump*    next;

}incomplete_jump;

typedef struct instr_stack{
    symbol* data;
    struct instr_stack *next;
}instr_stack;

/* Functions */

void expand_instr();
void emit_instr(instruction t);
void make_operand (expr* e, vmarg** arg);
void make_numberoperand (vmarg** arg, double val);
void make_booloperand (vmarg** arg, unsigned val);
void make_retvaloperand (vmarg** arg);
unsigned consts_newnumber (double n);
unsigned consts_newstring (char* s);
unsigned userfuncs_newfunc (symbol* sym);
unsigned libfuncs_newused (char* s);
void patch_incomplete_jumps();
void generate (vmopcode op, quad* q) ;

void generate_ADD (quad* q);
void generate_SUB (quad* q);
void generate_MUL (quad* q);
void generate_DIV (quad* q);
void generate_MOD (quad* q);
void generate_NEWTABLE (quad* q);
void generate_TABLEGETELEM (quad* q);
void generate_TABLESETELEM (quad* q);
void generate_ASSIGN (quad* q);
void generate_NOP ();

void generate_relational (vmopcode op, quad* q);

void generate_JUMP (quad* q);
void generate_IF_EQ (quad* q);
void generate_IF_NOTEQ(quad* q);
void generate_IF_GREATER (quad* q);
void generate_IF_GREATEREQ(quad* q);
void generate_IF_LESS (quad* q);
void generate_IF_LESSEQ (quad* q);
void generate_NOT (quad* q);
void generate_OR (quad* q);
void generate_PARAM(quad* q);
void generate_CALL(quad* q);
void generate_GETRETVAL(quad* q);
void generate_FUNCSTART(quad* q);
void generate_RETURN(quad* q);
void generate_FUNCEND(quad* q);
void generate_code();

void append(returnList** list, unsigned label);
void set_func_jump(symbol* function, int address);
void func_jump_backpatch(symbol* function, int label);
void add_incomplete_jump (unsigned instrNo, unsigned iaddress);
void backpatch(returnList** list, unsigned label);
symbol* itop(instr_stack **komvos);
void ipush(instr_stack **komvos, symbol* i);
symbol* ipop(instr_stack **komvos);
unsigned nextinstructionlabel();

void printfUserFunc (userfunc f);
void printmyOp_instr(vmopcode opcode);
void print_vmarg(vmarg* e_type);
void printmyInstructions ();
void binaryFile_Creation();