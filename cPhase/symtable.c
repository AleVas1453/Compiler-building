#include "symtable.h"



/* Dimiourgia neou object */
symbol *hashT[SIZE];

unsigned long hash_function(const char *name){

    unsigned long i=0;

    for(int j=0; name[j]; j++){
        i += name[j];
    }

    return i % SIZE;
}

void* insert_symtab(const char *name, enum SymbolType type, unsigned int scope, unsigned int line){

    symbol *symtab = (symbol*)malloc(sizeof(symbol));
	symtab->type= type;
    if(type==USERFUNC){
        symtab->type_C = programfunc_s;
    }else if(type == LIBFUNC){
        symtab->type_C = libraryfunc_s;
    }else{
        symtab->type_C = var_s;
    }

    /* Kalw hash_function kai mou dinei mia thesi gia na valw oti thelw */
    int index = hash_function(name);
            symtab->name = (char*)name; //edw prepei na diavasei to onoma tou input
            symtab->scope = scope;
            symtab->line = line;
    
	symtab->isActive = true;

    /* Gia apofygi collision, dimiourgw lista (next two lines are a stack) */
	symtab->next = hashT[index];    /* stin sygkekrimeno index pou pira prin, vazw ta stoixeia pou antistioixoun se ayti tin thesi */
    hashT[index] = symtab;          /* an den eixa collision tha arkouse mono auti i entoli(diladi otidipote mpainei stin prwti thesi) */
   return symtab;
}





void* lookup(const char *name, unsigned int scope){
    
    int index = hash_function(name);
    symbol *symtab = hashT[index];

    while(symtab!=NULL){
        if(symtab->isActive){
				if((strcmp(symtab->name,name)==0) && (symtab->scope == scope)){
					return symtab; 
				}else{
					symtab = symtab->next;
				}
        }else{
			symtab = symtab->next;
		}
    }
    return NULL;
}

unsigned char lookup_libfunc(const char *name, unsigned int scope){

    /* Elegxos an to input einai apagorevmenh lexi */
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
            return 1;
	}

    return 0;

}

void hide(unsigned int scope){
   
    int i;
    /* Se oles tis listes tou hashT kai psawxnw ola ta stoixeia gia to scope pou pairnw ws arg */
	for (i = 0; i < SIZE; i++){
    	symbol *symtab = hashT[i];
		while(symtab!=NULL){
				if(symtab->scope == scope){
					symtab->isActive = false;
				}
			symtab = symtab->next;
		} 
	}
}

void print_s(){
    int i;
    for ( i = 0; i < SIZE; i++){
        symbol *symtab = hashT[i];
        while(symtab!=NULL){
                        printf(" \"%s\" \t [%s] (line %d) (scope %d) \n", symtab->name, getType(symtab->type), symtab->line, symtab->scope);
            symtab = symtab->next;
        }
    }
}


const char* getType(enum SymbolType type) {
   switch (type) 
   {
      case 0 : return "global variable";
      case 1 : return "local variable";
      case 2 : return "formal argument";
      case 3 : return "user function";
      case 4 : return "library function";
	  default: return "Impossible to get here";
   }
}

void init_lib_func(){

    insert_symtab(strdup("print"), LIBFUNC, 0, 0);
    insert_symtab(strdup("input"), LIBFUNC, 0, 0);
    insert_symtab(strdup("objectmemberkeys"), LIBFUNC, 0, 0);
    insert_symtab(strdup("objecttotalmembers"), LIBFUNC, 0, 0);
    insert_symtab(strdup("objectcopy"), LIBFUNC, 0, 0);
    insert_symtab(strdup("totalarguments"), LIBFUNC, 0, 0);
    insert_symtab(strdup("argument"), LIBFUNC, 0, 0);
    insert_symtab(strdup("typeof"), LIBFUNC, 0, 0);
    insert_symtab(strdup("strtonum"), LIBFUNC, 0, 0);
    insert_symtab(strdup("sqrt"), LIBFUNC, 0, 0);
    insert_symtab(strdup("cos"), LIBFUNC, 0, 0);
    insert_symtab(strdup("sin"), LIBFUNC, 0, 0);
}


char* newName(char *onoma, int d){
    
    sprintf(onoma, "t_%d", d);
    return onoma;
}