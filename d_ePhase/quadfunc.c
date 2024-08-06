#ifndef QUADFUNC_H
#define QUADFUNC_H
#include "quadfunc.h"
#endif

quad* quads = (quad*)0; /* "quads"= o pinakas me ola ta quad */
unsigned total = 0;     /* apothikeuei ton arithmo twn quads */
unsigned int currQuad = 0; /* se kathe neo quad, kanw to currQuad++ kai dinei to current Quad */ 

int tempcounter = 0;
unsigned programVarOffset = 0;
unsigned functionLocalOffset = 0;
unsigned formalArgOffset = 0;
unsigned scopeSpaceCounter = 1;

/* kanei resize ton pinaka quads */
void expand(void){
	assert(total==currQuad);
	quad* p = (quad*) malloc(NEW_SIZE);
	if (quads){
		memcpy(p, quads, CURR_SIZE);
		free(quads);
	}
	quads = p;
	total += EXPAND_SIZE;
}

/*dimiourgia enos neou quad*/
void emit(iopcode op ,expr * arg1, expr * arg2, expr * result, int label, unsigned int line){
	if(currQuad == total){
		expand();
	}
			
	quad *p = quads + currQuad++;
	p->op = op;
	p->arg1 = arg1;
	p->arg2 = arg2;
	p->result = result;
	p->label = label;
	p->line = line;
}

/* Analoga to symbol_t epistrefw ton antistoixo typo */
expr* lvalue_expr(symbol* sym){
    assert(sym);
    expr* e = (expr*)malloc(sizeof(expr));
    memset(e,0,sizeof(expr));

    e->next = (expr*)0;
    e->sym=sym;

    switch(sym->type_C)
    {
        case var_s          :   e->type=var_e;
                                break;
        case programfunc_s  :   e->type=programfunc_e;
                                break;
        case libraryfunc_s  :   e->type=libraryfunc_e;
                                break;
        default             :   assert(0);
    }
    return e;
}

/* ftiaxni ena kainourgio expression kai setari ton tipo tou */
expr* newexpr(expr_t t){
    expr* e = (expr*)malloc(sizeof(expr));
    memset(e, 0, sizeof(expr));     
    e->type = t;
    return e;
}

/* ftiaxni ena kainourgio expression kai setari to strConst */
expr* newexpr_conststring(char* s){
    expr* e = newexpr(conststring_e);
    e->strConst = strdup(s);
    return e;
}

/* ftiaxni ena kainourgio expression kai setari to numConst*/
expr* newexpr_constnum(double i){
    struct expr* e = newexpr(constnum_e);
    e->numConst=i;
    return e;
}

/*  ftiaxni ena kainourgio expression kai setari to boolConst */
expr* newexpr_constbool(unsigned int b){
    struct expr* e = newexpr(constbool_e);
    e->boolConst = b;
    return e;

}

/*elegxos an einai tableitem. An einai to kanei emit me typo tablegetelem*/
expr* emit_iftableitem(expr* e){
    if(e->type != tableitem_e){
        return e;
    }else{
        expr* result = newexpr(var_e);
        result->sym = newtemp();
        emit(tablegetelem, e, e->index, result, 0, yylineno);
        return result;
    }
}

/*Thn kaloume opou theloume na ektypwsw ta orismata mias synartisis*/
expr* make_call(expr* lv, list_t* reversed_elist){

    expr* func = emit_iftableitem(lv);
    if(reversed_elist!=NULL){
        /*diatrexw olo ton pinaka mexri to teleftaio stoixeio*/
        while(reversed_elist->next!=NULL){
                reversed_elist=reversed_elist->next;                   
            }
        while(reversed_elist){
            /*prosthetw sta quads ta stoixeia me thn antistrofh seira*/
            emit(param, reversed_elist->arg, NULL, NULL, 0, yylineno);
            reversed_elist = reversed_elist->previous;
        }
    }
    emit(call, func, NULL, NULL, 0, yylineno);
    expr* result = newexpr(var_e);
    result->sym = newtemp();
    emit(getretval, NULL, NULL, result, 0, yylineno);
    return result;
}

/* Kali tin emit_iftableitem, dimiourgi ena neo expression kai setari to sym kai to index tou neou expression*/
expr* member_item(expr* lv, char* name){
    lv = emit_iftableitem(lv);
    expr* ti = newexpr(tableitem_e);
    ti->sym = lv->sym;
    ti->index=newexpr_conststring(name);
    return ti;
}

/*kommati tis checkarithm petaei to antistoixo error*/
void comperror(char* format){
    puts(format);
    exit(0);
}

/*elegxos an to e exei kapoion apo tou dothentes typous*/
void check_arith(expr* e,  char* context){
    if(e->type == constbool_e ||
        e->type == conststring_e ||
        e->type == nil_e ||
        e->type == newtable_e ||
        e->type == programfunc_e ||
        e->type == libraryfunc_e ||
        e->type == boolexpr_e)
        {
            comperror(context);
       }
}

/* Epistrefi to currQuad */
unsigned nextquadlabel(void){
    return currQuad;            
}

/* */
void patchlabel(unsigned quadNo, unsigned label){
    assert(quadNo < currQuad && !quads[quadNo].label); 
    quads[quadNo].label = label; 
}

/* Dimiourgw function me onoma pou ksekinaei apo "$", afou o xristis den mporei na dimiourgisei 
    kamia metavliti/function me tetoio tropo (petyxainw apofygi collision) */
char* newFunName(char *onoma, int d){
    
    sprintf(onoma, "$f_%d", d);
    return onoma;
}

/*dimioyrgia new temporary metavlitis*/
symbol* newtemp() {

    char *name = malloc(20);
    newName(name, tempcounter++);
    struct symbol* sym = lookup(name, scope); /* lookup tou symbol table */
    /* kai ekxwrisi sto symtab an den yparxei */
    if (sym == NULL){
/* Ksexwrizw global me local temp variables, pou apothikevonte sto symtab*/
        if(scope == 0)
            sym = insert_symtab(name, GLOBAL, scope, yylineno);
        else                                                        
            sym = insert_symtab(name, LOCAAL, scope, yylineno);

        sym->space = currscopespace(); 
        sym->offset = currscopeoffset();  
        inccurrscopeoffset();
        return sym;
    }else{
        return sym;
    }
    return NULL;
}

/*slide37 dial10 gia kryfes metavlites*/
/* Xrisimopoieitai gia epanaxrisimopoiisi kryfis metavlitis */
unsigned int istempname(char* s)
{
    return *s == ' ';
}

unsigned int istempexpr(expr* e)
{
    return e->sym && istempname(e->sym->name);
}

/* Kanei to tempcounter 0 */
void resettemp() { 

    tempcounter = 0; 
}

/* Kanei to formalArgOffset 0 */
void resetformalargsoffset(void)
{
    formalArgOffset = 0;
}

/*kanei to functionLocalOffset 0 */
void resetfunctionlocaloffset(void){
    functionLocalOffset = 0;
}

scopespace_t currscopespace(void){
	if(scopeSpaceCounter == 1){ /* afora oles tis metavlites ,etkos apo tis 2 apo katw */
	   return programvar;
	}else if(scopeSpaceCounter % 2 == 0){ /* otan anoigei "(" mias synartisis, tote exw formal args (pollaplasio tou 2 PANTA) */
		return formalarg;
	}else{ /* edw scSpCounter !=1 && != %2, tote einai functionlocal*/
		return functionlocal;
	}
}

void restorecurrscopeoffset(unsigned n){
    switch(currscopespace()){
        case programvar     :   programVarOffset = n;
                                break;
        case functionlocal  :   functionLocalOffset = n;
                                break;
        case formalarg      :   formalArgOffset = n;
                                break;
        default             :   assert(0);
    }
}

unsigned currscopeoffset (void){
	switch (currscopespace()){

        case programvar     :   return programVarOffset;
        case functionlocal  :   return functionLocalOffset;
        case formalarg      :   return formalArgOffset;
        default             :   assert(0);
	}
}

/* gia kathe scopespace diatirw ksexwristo offset */
void inccurrscopeoffset (void){
	switch (currscopespace()){
        case programvar     :   ++programVarOffset; 
                                break;
        case functionlocal  :   ++functionLocalOffset; 
                                break;
        case formalarg      :   ++formalArgOffset; 
                                break;
        default             :   assert(0);
	}
}

/* Afjani to enterscopespace */
void enterscopespace (void){
	++scopeSpaceCounter;
}

/* Mioni to existscopespace */
void existscopespace (void){
	assert(scopeSpaceCounter>1); 
	--scopeSpaceCounter;
}

/* dimiourgi neo statment */
stmt_t* make_stmt(stmt_t* s){ 
    s = (stmt_t*)malloc(sizeof(stmt_t));
    s->breakList = s->contList =0;
    return s;
}

int newlist(int i){
    quads[i].label = 0;
    return i;
}

/* sinennosi dyo listwn / xrisimopoieitai gia synennosi break kai contlist */
int mergelist(int l1, int l2){
    if(!l1){
        return l2;
    }else if(!l2){
        return l1;
    }else{
        int i = l1;
        while(quads[i].label){
            i = quads[i].label;
        }
        quads[i].label = l2;
        return l1;
    }
    /*return 0;*/
}

void patchlist(int list, int label){
    while(list){
        int next = quads[list].label;
        quads[list].label = label;
        list = next;
    }
}

/* **:pairnw dieuthinsi tou komvou */
/*push kai pop gia th stack 
push --> prosthiki stoixeioy sth lista*/
void push(stackkk **komvos, int i){

    struct stackkk *newlist = (stackkk*)malloc(sizeof(stackkk));
    newlist->next = *komvos;
    *komvos =newlist;

    newlist->data = i;

}

/*afairesi komvou gia th lista*/
int pop(stackkk **komvos){
    
    if(*komvos==NULL){
        exit(1);
    }else{
        struct stackkk *tmp = *komvos;
        int k = (*komvos)->data; /* apothikevw sto k ta data tou stoixeioy poy svinw */
        *komvos = (*komvos)->next;
        free(tmp);
        return k;
    }

}

/*epistrefei ton opcode gia kathe quad*/
void printmyOp(iopcode opcode){
    switch(opcode){
        
        case 0              : printf("assign");     return;
        case add            : printf("add");      return;
        case sub            : printf("sub");      return;
        case mul_1          : printf("mul");      return;
        case div_1          : printf("div");        return;
        case mod            : printf("mod");        return;
        case uminus         : printf("uminus");     return;
        case and            : printf("and");        return;
        case or             : printf("or");         return;
        case not            : printf("not");        return;
        case if_eq          : printf("if_eq");      return;
        case if_noteq       : printf("if_noteq");   return;
        case if_lesseq      : printf("if_lesseq");  return;
        case if_greatereq   : printf("if_greatereq"); return;
        case if_less        : printf("if_less");    return;
        case if_greater     : printf("if_greater"); return;
        case call           : printf("call");       return;
        case param          : printf("param");      return;
        case ret            : printf("ret");        return;
        case getretval      : printf("getretval");  return;
        case funcstart      : printf("funcstart");  return;
        case funcend        : printf("funcend");    return;
        case tablecreate    : printf("tablecreate");    return;
        case tablegetelem   : printf("tablegetelem");   return;
        case tablesetelem   : printf("tablesetelem");   return;
        case jump           : printf("jump");           return;
    }
}

/*ektypwnei to kathe expression poy einai apothikevmeno sto quad*/
void print_exprType(expr* e_type){

    /* Case keno */
    if(e_type == NULL){
        printf("\t");
        return;
    }

    switch(e_type->type){
        /* Case: ola ta arithmitika */
        case var_e:         printf("%s \t",e_type->sym->name);
                            return;
        case tableitem_e:   printf("%s \t",e_type->sym->name);
                            return;
        case programfunc_e: printf("%s \t",e_type->sym->name);
                            return;
        case libraryfunc_e: printf("%s \t",e_type->sym->name);
                            return;
        case arithexpr_e:   printf("%s \t",e_type->sym->name);
                            return;
        case boolexpr_e:    printf("%s \t",e_type->sym->name);
                            return;
        case assignexpr_e:  printf("%s \t",e_type->sym->name);
                            return;
        case newtable_e:    printf("%s \t",e_type->sym->name);
                            return;
        /* Cases: ola ta alla */
        case constnum_e :   printf("%f \t", e_type->numConst);
                            return;   /* Xreiazontai ta returns?? */
        case constbool_e :  if(e_type->boolConst == 0){
                                printf("false\t");
                            }else{
                                printf("true\t");
                            }
                            return;
        case conststring_e :printf("'%s'\t",e_type->strConst);
                            return;
        case nil_e :        printf("nil\t");
        }
}

/*ektypwsh twn quads*/
void* printmyQuad(){
    struct quad* myQuad; /*kanw enan pointer sto struct gia na mporw na toy valw nea stoixeia*/
    myQuad = quads; /*epeidi eipame oti to quads einai o pinakas*/
    int i;

    printf("Currquad = %d\n\n", currQuad);
    printf("\n-----------------------------------------------------------------\n");
    printf("\nquad#%10s%15s%10s%10s%10s\n","opcode","result","arg1","arg2","label");
    for(i=0; i<currQuad; i++){

        printf("%d:\t", i);
        printmyOp(quads[i].op);
        printf("\t");
        print_exprType(quads[i].result);
        print_exprType(quads[i].arg1);
        print_exprType(quads[i].arg2);
        /* oles oi cmp, ektos jump, den pigainoun pote sto 0 */
        /* koitazw poia entoli exw kai ystera krinw an tha ektypwsw 'h oxi to label */
        if(quads[i].op == jump){            /* MONO i jump mporei na paei se label 0 */
            printf("%d",quads[i].label);    /* ektypwnei to currLabel */
        }else if(quads[i].label != 0){
            printf("%d",quads[i].label);
        }
        printf("\n");
    }
    return NULL;
}