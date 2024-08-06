#include "avm.h"

#define AVM_MAX_INSTRUCTIONS (unsigned) jump_v

#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic



void execute_assign (instruction* t);
void execute_add (instruction* t);
void execute_sub (instruction* t);
void execute_mul (instruction* t);
void execute_div (instruction* t);
void execute_mod (instruction* t);
void execute_uminus (instruction* t);
void execute_and (instruction* t);
void execute_or (instruction* t);
void execute_not (instruction* t);
void execute_jeq (instruction* t); /*YPARXEI TO SWMA */
void execute_jne (instruction* t); /*YLOPOIITHIKE IDIA ME THN JEQ */
void execute_jle (instruction* t);
void execute_jge (instruction* t);
void execute_jlt (instruction* t);
void execute_jgt (instruction* t);
void execute_call (instruction* t);
void execute_pusharg (instruction* t);
void execute_funcenter (instruction* t);
void execute_funcexit (instruction* t);
void execute_newtable (instruction* t);
void execute_tablegetelem (instruction* t);
void execute_tablesetelem (instruction* t);
void execute_nop (instruction* t);
void execute_jump (instruction* t);

extern avm_memcell stack[AVM_STACKSIZE];
extern struct avm_memcell ax, bx, cx;
extern struct avm_memcell retval;
extern unsigned top, topsp;

/*Functions*/
void execute_assign (instruction* instr);
void execute_arithmetic (instruction* instr);

unsigned char number_tobool (avm_memcell* m);
unsigned char string_tobool (avm_memcell* m);
unsigned char bool_tobool (avm_memcell* m);
unsigned char table_tobool (avm_memcell* m);
unsigned char userfunc_tobool (avm_memcell* m);
unsigned char libfunc_tobool (avm_memcell* m);
unsigned char nil_tobool (avm_memcell* m);
unsigned char undef_tobool (avm_memcell* m);
unsigned char avm_tobool (avm_memcell* m);

void execute_cycle (void);