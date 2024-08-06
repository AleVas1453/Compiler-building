#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>

#define SIZE 1024
#define HASH_MULTIPLIER 37
int scope = 0;

enum SymbolType{
	GLOBAL, LOCAL, FORMAL, USERFUNC, LIBFUNC
};

typedef struct Variable{
	const char *type;		/* GLOBAL/FORMAL/LOCAL */
	const char *name;
	unsigned int scope;
	unsigned int line;
}Variable ;

typedef struct Function{
	const char *rettype;	/* USERFUNC/LIBFUNC */
	const char *name;
	unsigned int scope;
	unsigned int line;
}Function;

typedef struct SymbolTableEntry{
	bool isActive;
	union{
		Variable *varVal;
		Function *funcVal;
	}value;
	enum SymbolType type;

	struct SymbolTableEntry* next;

}SymbolTableEntry;

/* Dimiourgia neou object */
SymbolTableEntry *hashT[SIZE];

unsigned int hashfunction(const char *name);
void insert_symtab(char *name, enum SymbolType type, unsigned int value, unsigned int scope, unsigned int line);
void* lookup(SymbolTableEntry *symtab, const char *name, unsigned int scope);
void hide(SymbolTableEntry *symtab, const char *name, unsigned int scope);