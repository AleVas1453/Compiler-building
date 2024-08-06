#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>


#define SIZE 1024
extern int scope;

enum SymbolType{
	GLOBAL, LOCAAL, FORMAL, USERFUNC, LIBFUNC
};

typedef enum scopespace_t
{
	programvar,functionlocal,formalarg
}scopespace_t;

typedef enum symbol_t 
{
	var_s, programfunc_s, libraryfunc_s
}symbol_t;

typedef struct returnList{
    unsigned data; /* to taddress twn jump, pou paragoun oi return */
	struct returnList* next;
	struct returnList* prev;
}returnList;


typedef struct symbol{
	bool isActive;
    enum SymbolType type;
	symbol_t type_C;
	char* name;
	scopespace_t space;
	unsigned iaddress;		/* Ta iaddress/totalLocals einai orismata tou: */
	unsigned taddress;
	unsigned totalLocals;	/* funcprefix(typou symbol),ara mpainoun sto struct tou symbol */
	unsigned offset;
	unsigned scope;
	unsigned line;
	struct returnList* returnList; /* Prostethike gia 5i phase(to zitoun oi append/backpatch()) */
	
	unsigned fun_jump;		/* to taddress tou jump, prin to funcstart */
    struct symbol *next;
}symbol;


unsigned int hashfunction(const char *name);
void* insert_symtab(const char *name, enum SymbolType type, unsigned int scope, unsigned int line);
void* lookup(const char *name, unsigned int scope);
unsigned char lookup_libfunc(const char *name, unsigned int scope);
void hide(unsigned int scope);
void print_s();
const char* getType(enum SymbolType type);
void init_lib_func();
char* newName(char *onoma, int d);
char* lookupOffset(unsigned offset, enum SymbolType type);