#include "instructions.h"
#include <string.h>

#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&(m), 0, sizeof(m))
#define AVM_TABLE_HASHSIZE 211
#define AVM_STACKENV_SIZE 4
#define AVM_ENDING_PC codeSize
#define AVM_NUMACTUALS_OFFSET 4
#define AVM_SAVEDPC_OFFSET 3
#define AVM_SAVEDTOP_OFFSET 2 
#define AVM_SAVEDTOPSP_OFFSET 1
typedef double (*arithmetic_func_t) (double x, double y);

typedef enum avm_memcell_t {

		number_m	=0,
		string_m 	=1,
		bool_m 		=2,
		table_m 	=3,
		userfunc_m 	=4,
		libfunc_m 	=5,
		nil_m 		=6,
		undef_m 	=7

}avm_memcell_t;

/*afto nomizw einai grammeno apo katw
den xreiazetai edw
struct avm_table;*/

typedef struct avm_memcell {

		avm_memcell_t type;
		union{

			double 			numVal;
			char* 			strVal;
			unsigned char 	boolVal;
			struct avm_table* 		tableVal;
			unsigned 		funcVal;
			char* 			libfunc_Val;
        }data;

}avm_memcell;


typedef struct avm_table_bucket {
	avm_memcell  		key;
	avm_memcell  		value;
	struct avm_table_bucket* 	next;
}avm_table_bucket;

typedef struct avm_table {
	unsigned 			refCounter;
	struct avm_table_bucket* 	strIndexed[AVM_TABLE_HASHSIZE];
	struct avm_table_bucket*  	numIndexed[AVM_TABLE_HASHSIZE];
	unsigned  			total;
}avm_table;

typedef void (*memclear_func_t)(avm_memcell*);

typedef void (*library_func_t)(void);
typedef char* (*tostring_func_t)(avm_memcell* kati);

/*tha afisw edw ola ta prototypes twn synartisewn */
// static void avm_initstack (void);
void avm_tableincrefcounter (avm_table* t); /*edw thelei struct h oxi? */
void avm_tabledecrefcounter (avm_table* t);
void avm_tablebucketsinit (avm_table_bucket** p);
avm_table* avm_tablenew (void);
void avm_memcellclear (avm_memcell* m);
void avm_warning (char* format, char* format2, char* format3);
void avm_assign (avm_memcell* lv, avm_memcell* rv);
void avm_tablebucketsdestroyed (avm_table_bucket** p);
void avm_tabledestroy (avm_table* t);
double 	  consts_getnumber  (unsigned index);
char*  	  consts_getstring  (unsigned index);
char*  	  libfuncs_getused  (unsigned index);
userfunc* userfuncs_getfunc (unsigned index);
avm_memcell* avm_translate_operand (vmarg* arg, avm_memcell* reg);
void memclear_string (avm_memcell* m);
void memclear_table(avm_memcell* m);

void avm_call_functor (avm_table* t);
void avm_dec_top(void);
void avm_push_envvalue (unsigned val);
void avm_callsaveenvironment (void);
unsigned avm_get_envvalue (unsigned i);
void avm_calllibfunc (char* id);
unsigned avm_totalactuals(void);
avm_memcell* avm_getactual (unsigned i);
void libfunc_print (void);
void avm_registerlibfunc (char* id, library_func_t addr);
char* avm_tostring (avm_memcell* m);
void libfunc_typeof (void);
void avm_initialize (void);
void libfunc_totalarguments (void);
void libfunc_argument(void);
void avm_error(char* format, char* typeStrings1 ,char* typeStrings2);
char* avm_tostring (avm_memcell*);
void avm_calllibfunc (char* funcName);
void avm_callsaveenvironment (void);
void avm_call_functor (avm_table* t);
userfunc* avm_getfuncinfo (unsigned address);
typedef char* (*tostring_func_t)(avm_memcell* kati);
typedef double (*arithmetic_func_t) (double x, double y);
typedef unsigned char (*tobool_func_t) (avm_memcell*);
char* number_tostring (avm_memcell* kati);
char* string_tostring (avm_memcell* kati);
char* bool_tostring (avm_memcell* kati);
char* table_tostring (avm_memcell* kati);
char* userfunc_tostring (avm_memcell* kati);
char* libfunc_tostring (avm_memcell* kati);
char* nil_tostring (avm_memcell* kati);
char* undef_tostring (avm_memcell* kati);
avm_memcell* avm_tablegetelem(avm_table* table, avm_memcell* index);
void avm_tablesetelem(avm_table* table, avm_memcell* index, avm_memcell* content);

struct avm_table* avm_tablenew (void);
void avm_tabledestroy (struct avm_table* t);