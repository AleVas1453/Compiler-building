#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 1024
#define HASH_MULTIPLIER 37

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


unsigned int hashfunction(const char *name){

	unsigned int i = 0;
	unsigned int uiHash = 0;

	while(name[i]!= '\0'){
			uiHash = uiHash * HASH_MULTIPLIER + name[i];
			i++;
	}
	return (uiHash % SIZE);

}


/* Dimiourgei ena symbol, an den yparxei idi */
void insert_symtab(const char *name, enum SymbolType type, unsigned int value, unsigned int scope, unsigned int line){ 

	unsigned int bucket = hashfunction(name) % SIZE;
	/* edw prepei na kanw elegxo gia to an to bucket xwraei sto size tou hashtable */
    SymbolTableEntry *symtab = malloc(sizeof(SymbolTableEntry));

	symtab->type= type;

	if(type == GLOBAL || type == LOCAL || type == FORMAL){
		Variable* newVar = malloc(sizeof(Variable));
		newVar->name = name; //edw prepei na diavasei to onoma tou input
		newVar->scope = scope;
		newVar->line = line;
		symtab->value.varVal = newVar;
	}else{
		Function* newFun = malloc(sizeof(Function));
		newFun->name = name;
		newFun->scope = scope;
		newFun->line = line;
		symtab->value.funcVal = newFun;
	}
	
	symtab->isActive = true;
	/* edw prepei na pigainei stin epomeni thesi tou symtab (symtab->next) */
}

void* lookup(SymbolTableEntry *symtab, const char *name, unsigned int scope){	
	

	/*BHMA : elegxos an to input einai apagorevmenh lexi*/
	if(strcmp("print", name)==0
				||  strcmp("input", name)==0 
				||  strcmp("objectmemberkeys", name)==0 
				||  strcmp("objecttotalmembers", name)==0 
				||  strcmp("objectcopy", name)==0 
				||  strcmp("totalarguments", name)==0 
				||  strcmp("argument", name)==0 
				||  strcmp("typeof", name)==0 
				||  strcmp("strtonum", name)==0 
				||  strcmp("sqrt", name)==0 
				||  strcmp("cos", name)==0 
				||  strcmp("sin", name)==0 ){
					printf("NOT ALLOWED: %s\n", name);
					/* exit; 'h break, gia na bgainei */
				}
	/*else if((strcmp(current_sym->type,type)==0) && (strcmp(symtab->name,name)==0) && (symtab->scope!=scope)){
		printf("Symbol already there!\n");
	}
	*/
}

/*Kanei hide mono oti vrisketai se block kedika ara afora functions mono*/

/*void hide(int scope){
    
	/*SymTabEntry *symtab = (struct SymTabEn*)malloc(sizeof(SymTabEn));

    SymbolTableEntry *prev;
	SymbolTableEntry *current;
			Variable* newVar = malloc(sizeof(Variable));

	SymbolTableEntry *symtab = malloc(sizeof(SymTabEntry));
    int index = hashfunction(symtab->value.varVal->name);
    
    prev = NULL;
    //current = symtab->name[index];
scope=5

an to scope = current scope

}scope--;
    if(strcmp(current->name, name)==0 && (current->scope==scope))
    {
		/*exw vrei afto pou thelw na afairesw/kanw hide 
		//symtab->name[index] = current->next;
		current->isActive = false;
		//edw na meiwthei to scope
		current->scope--;
    }
	/*se periptwsi pou den to vrei ti kanei? *
	else if(strcmp(current->name, name)!=0 && (current->scope!=scope)){
		printf("DOESN'T EXIST");
	}

	prev = current;
	current = current->next;


}*/

void hide(SymbolTableEntry *symtab, const char *name, unsigned int scope)
{
	/*Variable *var = (struct Variable*)malloc(sizeof(Variable));
	Function *fun = (struct Function*)malloc(sizeof(Function));
	*/

	SymbolTableEntry *prev;
	SymbolTableEntry *current;

	int index = hashfunction(name);

	prev = NULL;
	/*current = symtab->value.varVal->name;*/

	if(strcmp(current->value.varVal->name, name)==0 && (current->value.varVal->scope == scope) )
	{
		current->isActive = false;
		current->value.varVal->scope--;
	}
	if(strcmp(current->value.funcVal->name , name)==0 && (current->value.funcVal->scope == scope)){
		current->isActive =false;
		current->value.funcVal->scope--;
	}
	if(!strcmp(current->value.varVal->name, name)==0 && (current->value.varVal->scope!=scope)){
		printf("DOESN'T EXIST");
	}else if(!strcmp(current->value.funcVal->name, name)==0 && (current->value.funcVal->scope!=scope)){
		printf("DOESN'T EXIST");
	}
	
}
