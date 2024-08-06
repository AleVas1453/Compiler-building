#include <stdio.h>
#include "dispatcher.h"

/* Dhmiourgia Virtual Machine */
/* Metaferw ola osa xreiazontai [apo ta proigoumena arxeia(dilwseis, arxikopoiiseis klp)], 
    wste na vlepw oti to avm.c me ta ola ta proigoumena arxeia, vgazoun  IDIO apotelesma 
    (stin prokeimeni periptwsi to printMyInstructions) */

int         magicnumber;
/*slide 17 dial13 oi pinakes twn statherwn orismatwn dimiourgountai kata to loading tou kwdika */
double*     numConsts;
unsigned    totalNumConsts = 0;
unsigned    currNumConst = 0;

char**      stringConsts;
unsigned    totalStringConsts = 0;
unsigned    currStringConst = 0;

char**      namedLibfuncs;
unsigned    totalNameLibfuncs = 0;
unsigned    currNameLibfunc = 0;

userfunc*   userFuncs;
unsigned    totalUserFuncs = 0;
unsigned    currUserFunc = 0;

instruction* instructions = (instruction*) 0;
unsigned currInstruction = 0;
unsigned int totalInstructions = 0;

avm_memcell ax, bx, cx;
avm_memcell retval;
unsigned top = AVM_STACKSIZE;
unsigned topsp = AVM_STACKSIZE;

avm_memcell stack[AVM_STACKSIZE];

extern char* typeStrings[];

extern unsigned char    executionFinished;
extern unsigned     pc;
extern unsigned     currLine;
extern unsigned         codeSize;
extern instruction*     code;
extern unsigned totalActuals;

typedef void (*execute_func_t)(instruction*);

/* Initialize the stack */
static void avm_initstack (void){
    unsigned i;
    for(i=0; i<AVM_STACKSIZE; i++)
    {
        AVM_WIPEOUT(stack[i]); stack[i].type = undef_m;
    }
}

/* afksani to refCounter */
void avm_tableincrefcounter (avm_table* t){
        ++t->refCounter;
}

/* diagrafi to refCounter */
void avm_tabledecrefcounter (avm_table* t){
    assert(t->refCounter > 0);
    if(!--t->refCounter)
        avm_tabledestroy(t);
}

/* Initialize a new table */
void avm_tablebucketsinit (avm_table_bucket** p){
    unsigned i;
    for (i=0; i<AVM_TABLE_HASHSIZE; ++i)
        p[i] = (avm_table_bucket*) 0;
}

/* Creates a new table */
avm_table* avm_tablenew (void){
    avm_table*t = (avm_table*) malloc(sizeof(avm_table));
    AVM_WIPEOUT(*t);

    t->refCounter = t->total = 0;
    avm_tablebucketsinit(t->numIndexed);
    avm_tablebucketsinit(t->strIndexed);
    return t;
}

/* To collections endiaferetai mono gia strings kai dynamikous pinakes,
opote opou tin kalw afora mono auta ta 2 */
memclear_func_t memclearFuncs[] = {
    0,              /* number */
    memclear_string,
    0,              /* bool */
    memclear_table,
    0,              /* userfunc */
    0,              /* libfunc */
    0,              /* nil */
    0               /* undef */
};

tostring_func_t tostringFuncs[]= {
    number_tostring,
    string_tostring,
    bool_tostring,
    table_tostring,
    userfunc_tostring,
    libfunc_tostring,
    nil_tostring,
    undef_tostring
};

/* katharismos all data of a cell */
void avm_memcellclear (avm_memcell* m){
    if (m->type != undef_m){
        memclear_func_t f = memclearFuncs[m->type];
        if (f)
            (*f)(m);
        
        m->type = undef_m;
    }
}

/* Ektypwnei ena minima (warning) */
void avm_warning (char* format, char* format2, char* format3){
    printf("%s",format);
}

void avm_assign (avm_memcell* lv, avm_memcell* rv){
    if(lv == rv)
        return;

    if(lv->type == table_m && rv->type == table_m && lv->data.tableVal == rv->data.tableVal)
        return;

    if(rv->type == undef_m)
        avm_warning("assigning from 'undef' content!", NULL, NULL);

    avm_memcellclear(lv);

    memcpy(lv,rv,sizeof(avm_memcell));

    if(lv->type == string_m)
        lv->data.strVal = strdup(rv->data.strVal);
    else
        if(lv->type == table_m)
            avm_tableincrefcounter(lv->data.tableVal);
}

/*tiponi to format san error */
/* Pairnw 3 orismata(logw execute_jeq) */
void avm_error(char* format, char* typeStrings1 ,char* typeStrings2){
    printf(format,typeStrings1,typeStrings2);
    exit(123);
}

/*  */
char* avm_tostring (avm_memcell* m){
    assert(m->type >= 0 && m->type <= undef_m);
    return (*tostringFuncs[m->type])(m);
}

typedef void (*library_func_t)(void);

unsigned avm_totalactuals(void){
    return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

/* koitaei na dei an einai number */
unsigned avm_get_envvalue (unsigned i){
    // assert(stack[i].type == number_m);
    unsigned val = (unsigned) stack[i].data.numVal;
    assert(stack[i].data.numVal == ((double)val));
    return val;
}

avm_memcell* avm_getactual (unsigned i){
    assert(i < avm_totalactuals());
    return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}

void libfunc_print (void){
    unsigned n = avm_totalactuals();
    unsigned i;
    for(i=0; i<n; ++i){
        char* s =avm_tostring(avm_getactual(i));
        //puts(s);
        printf("%s",s);
       // free(s);
    }
}

/*slide 32
epitrepei runtime type identification/ elegxei
akoma kai undefined vars*/
void libfunc_typeof (void){

    unsigned n = avm_totalactuals();

    if(n != 1)
    /*an mia synart vivliothikis xreiazetai sygkekrimeno arithmo
    apo arguments ylopoiei eswt th logiki elegxou k petaei runtime error*/
        fprintf(stderr, "one argument (not %d) expected in typeof! ", n);
    else{
        /*That is how a library returns a result.
        It has to only set the 'retval' register */
        avm_memcellclear(&retval); /*cleans it up */
        retval.type = string_m;
        retval.data.strVal = strdup(typeStrings[avm_getactual(0)->type]);
    }
}

void libfunc_totalarguments (void){
    /*Get topsp of previous activation record*/

    unsigned p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
    avm_memcellclear(&retval);

    if(!p_topsp){
        /*If 0, no previous activation record */
        avm_error("'totalarguments' called outside a function!", NULL, NULL);
        retval.type = nil_m;
    }else{
        /*Extract the number of actual arguments for the previous activation record*/
        retval.type = number_m;
        retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
    }
}

void libfunc_argument(void){
    
    unsigned p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET );
    avm_memcellclear(&retval);

    if(!p_topsp){
        /*If 0, no previous activation record */
        avm_error("'argument' called outside a function!\n", NULL, NULL);
        retval.type = nil_m;
    }else{
        //elegxos oti pairnei ena actual
        int actuals = avm_totalactuals();
        if(actuals != 1 ){
            avm_error("'argument' param get error\n", NULL, NULL);
            retval.type = nil_m;
        }else{
            //elegxos oti to actual einai number
            avm_memcell * cell = &stack[topsp + AVM_NUMACTUALS_OFFSET + 0 + 1];
            if(cell->type!= number_m){
                avm_error("'argument' param type error\n", NULL, NULL);
                retval.type = nil_m;
            }else{
                double offs = stack[topsp + AVM_NUMACTUALS_OFFSET + 0 + 1].data.numVal;//to argument tis libfunc argument
                int p_actuals = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);//posa actual arguments exei o caller
                if((offs < p_actuals) && (offs >= 0)){
                    if(stack[p_topsp + AVM_NUMACTUALS_OFFSET + (int)offs + 1].type==string_m){
                        retval.type = string_m;
                        retval.data.strVal = strdup(stack[p_topsp + AVM_NUMACTUALS_OFFSET + (int)offs + 1].data.strVal);
                    }else if(stack[p_topsp + AVM_NUMACTUALS_OFFSET + (int)offs + 1].type==number_m){
                        retval.type = number_m;
                        retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET + (int)offs + 1);
                    }
                }else{
                    avm_error("'argument' out of bounds\n", NULL, NULL);
                    retval.type = nil_m;
                }
            }
        }

        
    }    
    
}

// unsigned char libfunc_tobool (avm_memcell* m) { return 1; }
//epistrefei enan function pointer pou antistixei sto id
library_func_t avm_getlibraryfunc(char* id){
    if(strcmp(id, "print") == 0){
        return libfunc_print ;
    }
    if(strcmp(id, "typeof") == 0){
        return libfunc_typeof;
    }
    if(strcmp(id, "totalarguments") == 0){
        return libfunc_totalarguments;
    }
    if(strcmp(id, "argument") == 0){
        return libfunc_argument;
    }        
    return NULL;
}


void avm_calllibfunc(char* id){
    library_func_t f = avm_getlibraryfunc(id);
    if(!f){
        avm_error("unsupported lib func '%s' called! ",id, id);
        executionFinished = 1;
    }
    else{
        /*Notice that enter function and exit function are called manually*/
        avm_callsaveenvironment();
        topsp = top;
        totalActuals = 0;       /*Enter function sequence. No stack locals*/
        (*f)();                 /*call library function*/
        if(!executionFinished)  /*An error may naturaly occur inside*/
            execute_funcexit((instruction*) 0); /*Return sequence*/
    }
}

/* elegxei an exei ginei overflow sto stack, alliws meiwnei to top kata ena*/
void avm_dec_top(void){
    if(!top){ 
        avm_error("stack overflow", NULL, NULL);
        executionFinished = 1;
    }
    else
        --top;
}

/* vazei sto current top type kai data */
void avm_push_envvalue (unsigned val){
    stack[top].type = number_m;
    stack[top].data.numVal = val;
    avm_dec_top();
}

/*sosimo perivalontos kai klisis */
void avm_callsaveenvironment (void){
    avm_push_envvalue(totalActuals);
    assert(code[pc].opcode == call_v);
    avm_push_envvalue(pc+1);
    avm_push_envvalue(top+totalActuals+2);
    avm_push_envvalue(topsp);
}

/* An exw table, to prosthetw stin current top thesi tis stack */
void avm_push_table_arg(avm_table* t){
    stack[top].type = table_m;
    avm_tableincrefcounter(stack[top].data.tableVal = t);
    ++totalActuals;
    avm_dec_top();
}

/* Klisi dictionary, otan ena key, exei value ena function */
void avm_call_functor (avm_table* t){
    cx.type = string_m;
    cx.data.strVal = "()";
    avm_memcell* f = avm_tablegetelem (t,&cx);
    if(!f)
        avm_error("in calling table: no '()' elemnt found! ", "DEN KSERW", "DEN KSERWW");
    else
        if(f->type == table_m)
            avm_call_functor(f->data.tableVal);
        else
            if(f->type == userfunc_a){
                avm_push_table_arg(t);
                avm_callsaveenvironment();
                pc = f->data.funcVal;
                assert(pc < AVM_ENDING_PC && code[pc].opcode == funcenter_v);
            }
            else
                avm_error("in calling table: illigal '()' element value! ", "DEN KSERW", "DEN KSERWW");
}

/* Diagrafi OLWN twn keliwn nimis pou eixan dimiourgeithei */
void avm_tablebucketsdestroyed (avm_table_bucket** p){
    unsigned i;
    for(i = 0; i < AVM_TABLE_HASHSIZE; ++i){
        ++p;                                    
        for(avm_table_bucket*b = *p; b;){
            avm_table_bucket* del = b;
            b = b->next;
            avm_memcellclear(&del->key);
            avm_memcellclear(&del->value);
            free(del);
        }
        p[i] = (avm_table_bucket*) 0;
    }
}

/*destroy table */
void avm_tabledestroy (avm_table* t){
    avm_tablebucketsdestroyed(t->strIndexed);
    avm_tablebucketsdestroyed(t->numIndexed);
    free(t);
}

/* Epistrefei to totalNo twn global vars, afou oloklirwthoun ola ta instructions
    (kathe metavliti tin pairnei apokleistika MIA fora) */
int totalGlobal_a(){
    int max = 0;
    int i;
    
    for(i=0; i< currInstruction; i++){
        instruction* instr = &instructions[i];
        if(instr->result != NULL && instr->result->type == global_a){
            if(instr->result->val > max){
                max = instr->result->val;
            }
        }
        if(instr->arg1 != NULL && instr->arg1->type == global_a){
            if(instr->arg1->val > max){
                max = instr->arg1->val;
            }
        }
        if(instr->arg2 != NULL && instr->arg2->type == global_a){
            if(instr->arg2->val > max){
                max = instr->arg2->val;
            }
        }
    }
    top=top-(max+1)-1;
    topsp = top;
    return max+1;

}

/*Metaftazei ta arg se avm_memcell (opos h make_operand) */
avm_memcell* avm_translate_operand (vmarg* arg, avm_memcell* reg){

    switch(arg->type){
        case global_a: return &stack[AVM_STACKSIZE-1-arg->val];
        case local_a:  return &stack[topsp-arg->val];
        case formal_a: return &stack[topsp+AVM_STACKENV_SIZE+1+arg->val];
        case retval_a: return &retval;
        case number_a: {
            reg->type = number_m;
            reg->data.numVal = consts_getnumber(arg->val);
            return reg;
        }
        case string_a: {
            reg->type = string_m;
            reg->data.strVal = strdup(consts_getstring(arg->val));
            return reg;
        }
        case bool_a: {
            reg->type = bool_m;
            reg->data.boolVal = arg->val;
            return reg;
        }
        case userfunc_a: {
            reg->type = userfunc_m;
            reg->data.funcVal = arg->val;
            reg->data.funcVal = userfuncs_getfunc(arg->val)->address;
            return reg;
        }
        case libfunc_a: {
            reg->type = libfunc_m;
            reg->data.libfunc_Val = libfuncs_getused(arg->val);
            return reg;
        }
        case nil_a: {
            reg->type = nil_m;
            return reg;

        }
        default: assert(0);
    }
}

avm_memcell* avm_tablegetelem(avm_table* table, avm_memcell* index){
    return NULL;
}

void avm_tablesetelem(avm_table* table, avm_memcell* index, avm_memcell* content){

}

/* Epistrofi stoixeio "i" tou pinaka numConsts*/
double    consts_getnumber  (unsigned i) {
    return numConsts[i];
}

/* Epistrofi stoixeio "i" tou pinaka stringConsts*/
char*     consts_getstring  (unsigned i){
    return stringConsts[i];
}

/* Epistrofi stoixeio "i" tou pinaka namedLibfuncs*/
char*     libfuncs_getused  (unsigned i){
    return namedLibfuncs[i];
}

/* Epistrofi stoixeio "i" tou pinaka userFuncs*/
userfunc* userfuncs_getfunc (unsigned i){
    return &userFuncs[i];
}


void memclear_string (avm_memcell* m){
    assert(m->data.strVal);
    free(m->data.strVal);
}
void memclear_table(avm_memcell* m){
    assert(m->data.tableVal);
    avm_tabledecrefcounter(m->data.tableVal);
}

/* Metatropi enos number se string */
char* number_tostring (avm_memcell* kati){
    /* Antistoixh ylopoisi me newName 3is phase */
    char *name = malloc(20);
    sprintf(name, "%f", kati->data.numVal);
    return name;
}

/* Pairnw to idia tin timi tou stoixeiou gia string
    (DEN kanw metatropi) */
char* string_tostring (avm_memcell* kati){
    return kati->data.strVal;
}

/*metatropi boolean se string*/
char* bool_tostring (avm_memcell* kati){
    if(kati->data.boolVal == 1){
        return "true";
    }
    if(kati->data.boolVal == 0){
        return "false";
    }
    return 0;
}

/*mh ylopoihmeno */
char* table_tostring (avm_memcell* kati){
    return 0;
}

/* to funcVal einai to taddress tis synartisis */
char* userfunc_tostring (avm_memcell* kati){
    userfunc *f = avm_getfuncinfo(kati->data.funcVal);
    return f->id;
}

/* Pairnw to idia tin timi tou stoixeiou gia lifunc
    (DEN kanw metatropi) */
char* libfunc_tostring (avm_memcell* kati){
    return kati->data.libfunc_Val;
}

/*NULL*/
char* nil_tostring (avm_memcell* kati){
    return "NULL";
}

/*An einai undefined epistrefei undel */
char* undef_tostring (avm_memcell* kati){
    return "UNDEF";
}

/*  Dial15/sel25
    Every library function is manually added in the VM library function
    resolution map */
void avm_registerlibfunc (char* id, library_func_t addr){

}

/* Arxikopoihsh stoivas kai orismos EIDIKWN library synartisewn */
void avm_initialize (void){

    avm_initstack();
    avm_registerlibfunc("print", libfunc_print);
    avm_registerlibfunc("typeof", libfunc_typeof);
    /*prosthesame kai gia tis ypoloipes library functions */
    avm_registerlibfunc("totalarguments", libfunc_totalarguments);
    avm_registerlibfunc("argument", libfunc_argument);
}

/*diavasma binaryfile */
void read__binaryFile(){

    int i;
    FILE *file;

    avm_initialize();

    if((file = fopen("binary.abc","rb")) == NULL){
        fprintf(stderr,"There is no such file\n");
    }    

    //fread(&magicnumber, sizeof(int), 1, file);
    //printf("MAGIC NUMBER = %d\n", magicnumber);

    /* Numbers total*/  
    fread(&currNumConst, sizeof(currNumConst), 1, file);
    /* Numbers array*/
    /* O numConsts pinakas einai DIAFORETIKOS apo auton tou instructions(gi auto malloc) */
    /* Xreiazomai desmeusi xwrou(= megethos pinaka) prin diavasw ta stoixeia tou pinaka */
    /* (tin idia douleia sta instruction, thn eixa kanei me tin expand_num()) */
    double x;
    numConsts = malloc(currNumConst * sizeof(double));
    for(i = 0 ; i < currNumConst ; i++){
        
        fread(&x, sizeof(double), 1, file);
        numConsts[i] = x;
    }
    

    /* String total */
    fread(&currStringConst, sizeof(currStringConst), 1, file);
    /* String array */
    stringConsts = malloc(sizeof(char*) * currStringConst);
    for (i = 0; i < currStringConst; i++) {
        int size_str; 
        
        /* Pairnw tin timi(tou size_str), pou mpike apo to fwrite */
        fread(&size_str, sizeof(int), 1, file); 
        size_str++; /* +1, gia na mpei kai to "/0"(end of string) */
        
        /* Gia KATHE string, desmeuw toso xwro oso to megethos tou */
        /* pairnw xwro gia n bytes (an strlen(size_str=4), egw pairnw 5 bytes) */
        stringConsts[i] = (char*)malloc(sizeof(char) * size_str);
        /* Diavazw n-1 bytes(edw 4, gia na min parw to '/0') */
        fread(stringConsts[i], sizeof(char) * (size_str-1), 1, file); /* "-1", logw "/0" */
        /* Vazw tin teleftaia thesi = 0(opou vrisketai to'/0'),
        gia na min tyxon mpoun skoupidia */
        stringConsts[i][size_str-1]=0;
        
    }

    /* Library Functions total */
    fread(&currNameLibfunc, sizeof(currNameLibfunc), 1, file);
    /* Library Functions array */
    namedLibfuncs = malloc(sizeof(char*) * currNameLibfunc);
    for (i = 0; i < currNameLibfunc; i++) {
        int size_libfun;

        fread(&size_libfun, sizeof(int), 1, file);
        size_libfun++;
        namedLibfuncs[i] = (char*)malloc(sizeof(char) * size_libfun);
        fread(namedLibfuncs[i], sizeof(char) * (size_libfun-1), 1, file);
        namedLibfuncs[i][size_libfun-1]=0;
        
    }
            
    /* User Functions total */
    fread(&currUserFunc, sizeof(currUserFunc), 1, file);
    /* User Functions array */
    userFuncs = malloc(sizeof(userfunc) * currUserFunc);
    for(i = 0 ; i < currUserFunc ; i++){
        int size_userfun;

        fread(&userFuncs[i].address, sizeof(unsigned), 1, file);
        fread(&userFuncs[i].localSize, sizeof(unsigned), 1, file);
        
        fread(&size_userfun, sizeof(int), 1, file);
        size_userfun++;
        userFuncs[i].id = malloc(sizeof(char) * size_userfun);
        fread(userFuncs[i].id, sizeof(char) * size_userfun -1, 1, file);
        userFuncs[i].id[size_userfun-1] = 0;
    }

    /* Instructions total */
    fread(&currInstruction, sizeof(currInstruction), 1, file);
    /* Instructions array */
    instructions = (instruction*)malloc(sizeof(instruction) * currInstruction);
    int flag;
    for(i = 0 ; i < currInstruction ; i++){
        fread(&instructions[i].opcode, sizeof(vmopcode), 1, file);
        instructions[i].arg1= NULL;
        instructions[i].arg2= NULL;
        instructions[i].result= NULL;

        fread(&flag, sizeof(int), 1, file);
        while(flag!=4){
            if(flag==1){
                instructions[i].arg1 = malloc(sizeof(vmarg));
                fread(&instructions[i].arg1->type, sizeof(instructions[i].arg1->type), 1, file);
                fread(&instructions[i].arg1->val, sizeof(unsigned), 1, file);
            }else if(flag==2){
                instructions[i].arg2 = malloc(sizeof(vmarg));
                fread(&instructions[i].arg2->type, sizeof(instructions[i].arg2->type), 1, file);
                fread(&instructions[i].arg2->val, sizeof(unsigned), 1, file);
            }else if(flag==3){
                instructions[i].result = malloc(sizeof(vmarg));
                fread(&instructions[i].result->type, sizeof(instructions[i].result->type), 1, file);
                fread(&instructions[i].result->val, sizeof(unsigned), 1, file);
            }
            fread(&flag, sizeof(int), 1, file);
        }
   }
}


/* Pairnw codeSize, oso to currInstruction(dld mexri opou exw ftasei) */
int setCodesize(void){
    codeSize = currInstruction;
    return codeSize;
}

/* Pairnw to sygkekrimeno instruction */
instruction* setCode(){
    code = instructions;
    return code;
}

int main(){

    read__binaryFile();


    setCodesize();
    setCode();

    printf("MAXXXXX = %d\n",totalGlobal_a());

    while(1){
        execute_cycle();
    }
  
}