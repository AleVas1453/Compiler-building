#include "instructions.h"

extern quad* quads; /* "quads"= o pinakas me ola ta quad */
extern unsigned total;     /* apothikeuei ton arithmo twn quads */
extern unsigned int currQuad; /* se kathe neo quad, kanw to currQuad++ kai dinei to current Quad */ 
extern symbol *hashT[SIZE];

incomplete_jump*    ij_head = (incomplete_jump*) 0;
unsigned            ij_total = 0;
int currprocessedquad = 0;  /* idio me currQuad */

typedef void (*generator_func_t)(quad*);

/* Pinakes pou apothikeuoun to input (analoga ton typo) */
/*oloi pinakes mas epistrefoun th thesi sthn opoia vrisketai
to antistoixo num, string klp */
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

instr_stack* instrFuncstart = NULL;

/*analogi ths expand twn quads */
void expand_instr(){
    assert(totalInstructions == currInstruction);
    instruction* p = (instruction*) malloc(NEW_SIZE);
    if (instructions){
        memcpy(p, instructions, CURR_SIZE);
        free(instructions);
    }
    instructions = p;
    totalInstructions += EXPAND_SIZE;
}

/*dimiourgia enos neou instruction */
void emit_instr(instruction t){
    if(currInstruction == totalInstructions){
        expand_instr();
    }
    
    instructions[currInstruction++] = t;
    /* Pairnei etoimo "t"(exei ginei oti xreiazetai stin generate()) */
}

/* "**":Pernaw tin dieuthinsi (epeidi evgaze seg) */
/* Kanei metatropi ta expr --> vmarg */
void make_operand (expr* e, vmarg** arg){
    /* An expr einai NULL tote NULL kai to vmarg kai epistrefw)*/
    if(e == NULL){
        (*arg)= NULL;
        return;
    }
    /* Anagkastiki desmeusi mnimis, epeidi evala ta vmarg arg ws deiktes stin struct instr */
    (*arg) = malloc(sizeof(vmarg));
    switch (e->type){
        case var_e:
        case tableitem_e:
        case arithexpr_e:
        case assignexpr_e: /* Extra periptwsi (Den ypirxe prin) */
        case boolexpr_e:
        case newtable_e: {
            assert(e->sym);
            (*arg)->val = e->sym->offset;

            switch (e->sym->space){
                case programvar:    (*arg)->type = global_a; break;
                case functionlocal: (*arg)->type = local_a;  break;
                case formalarg:     (*arg)->type = formal_a; break;
                default: assert(0);
            }
            break;/*from case newtable_e */
        }
        /*constants */
        case constbool_e: {
            (*arg)->val = e->boolConst;
            (*arg)->type = bool_a; 
            break;
        }
        case conststring_e: {
            (*arg)->val = consts_newstring(e->strConst); 
            (*arg)->type = string_a; 
            break;
        }
        case constnum_e: {
            (*arg)->val = consts_newnumber(e->numConst); 
            (*arg)->type = number_a; 
            break;
        }
        /* Functions */
        case programfunc_e: {
            (*arg)->type = userfunc_a;
            (*arg)->val = userfuncs_newfunc (e->sym);   
            break;
        }
        case libraryfunc_e: {
            (*arg)->type = libfunc_a;
            (*arg)->val = libfuncs_newused(e->sym->name);    
            break;
        }
        case nil_e: {
            (*arg)->type = nil_a;   
            break;

        }
        default: assert(0);
    }
}

/*dimiourgei neo numoperand me ananewmena val kai type
dinetai*/
void make_numberoperand (vmarg** arg, double val){
    *arg = malloc(sizeof(vmarg));
    (*arg)->val = consts_newnumber(val);    
    (*arg)->type = number_a;
}

/*dimiourgei neo booloperand me ananewmena val kai type
dinetai*/
void make_booloperand (vmarg** arg, unsigned val){
    *arg = malloc(sizeof(vmarg));
    (*arg)->val  = val;
    (*arg)->type = bool_a;
}

/* type-->return value
dinetai*/
void make_retvaloperand (vmarg** arg){
    *arg = malloc(sizeof(vmarg));
    (*arg)->type = retval_a;
}

/* ---Expand - Dimiourgeia pinakwn--- */

/* Kanei expand ton pinaka numConsts */
void expand_const_num(){
    assert(totalNumConsts == currNumConst);
    double* p = (double*) malloc((EXPAND_SIZE + totalNumConsts) * sizeof(double));
    if (numConsts){
        memcpy(p, numConsts, totalNumConsts * sizeof(double));
        free(numConsts);
    }
    numConsts = p;
    totalNumConsts += EXPAND_SIZE;
}

/* Prosthetei ton arithmo pou erxetai(san arg) (KAI elegxei an yparxei idi, gia na min ton ksanavalei) */
/* Diladi prin epistrepsei tin thesi, koitaei mipws yparxei */
/* Apothikeysi numbers */
unsigned consts_newnumber (double n){
    if(currNumConst == totalNumConsts){
        expand_const_num();
    }

    int i;
    for(i=0; i<currNumConst; i++){
        /* An yparxei idi o arithmos, apla ton epistrefei. Den ton prosthetei ksana */
        if(numConsts[i] == n){
            return i;
        }
    }

    numConsts[currNumConst] = n;
    return currNumConst++; /* Epistrefei tin THESI ston pinaka pou vrethike to stoixeio */
}

/* Afksani to megethos tou pinaka pou apothikevonte ta userfuncs */
void expand_userfuncs(){
   assert(totalUserFuncs == currUserFunc);
    userfunc* p = (userfunc*) malloc((EXPAND_SIZE + totalUserFuncs) * sizeof(userfunc));
    if (userFuncs){
        memcpy(p, userFuncs, totalUserFuncs * sizeof(userfunc));
        free(userFuncs);
    }
    userFuncs = p;
    totalUserFuncs += EXPAND_SIZE;
}
/* Apothikeysi userfuncs */
unsigned userfuncs_newfunc (symbol* sym){
    if(currUserFunc == totalUserFuncs){
        expand_userfuncs();
    }

    int i;
    for(i=0; i<currUserFunc; i++){
        /* Pera apo to name, koitaw to address tis func, gia na epistrepsw tin swsti dieuthinsi
            (Apofeygw conflicts) */
        if(!strcmp(userFuncs[i].id,sym->name) && userFuncs[i].address == sym->taddress){
            return i;
        }
    }
    userFuncs[currUserFunc].id = sym->name;
    userFuncs[currUserFunc].address = sym->taddress;
    userFuncs[currUserFunc].localSize = sym->totalLocals;
    return currUserFunc++;
}

/* Afjani to megethos tou pinaka pou apothikevonte ta strings */
void expand_const_string(){
    assert(totalStringConsts == currStringConst);
    char** p = (char**) malloc((EXPAND_SIZE + totalStringConsts) * sizeof(char*));
    if (stringConsts){
        memcpy(p, stringConsts, totalStringConsts * sizeof(char*));
        free(stringConsts);
    }
    stringConsts = p;
    totalStringConsts += EXPAND_SIZE;
}
/* Apothikeysi strings */
unsigned consts_newstring (char* s){
    if(currStringConst == totalStringConsts)
    {
        expand_const_string();
    }

    int i;
    for(i=0; i<currStringConst; i++)
    {
        if(!strcmp(stringConsts[i],s))
        {
            return i;
        }
    }

    stringConsts[currStringConst] = strdup(s); /* xrisimopoiw strdup, epeidi to s einai string */
    return currStringConst++; 
    return 0;
}

/*expand ton pinaka twn library functions */
void expand_libfuncs(){
    assert(totalNameLibfuncs == currNameLibfunc);
    char** p = (char**) malloc((EXPAND_SIZE + totalNameLibfuncs) * sizeof(char*));
    if (namedLibfuncs){
        memcpy(p, namedLibfuncs, totalNameLibfuncs * sizeof(char*));
        free(namedLibfuncs);
    }
    namedLibfuncs = p;
    totalNameLibfuncs += EXPAND_SIZE;
}

/* Apothikeysi libfuncs */
unsigned libfuncs_newused (char* s){
    /*xrisi ths expand se periptwsh pou exei ftasei to orio twn totalNameLibfuncs*/
    if(currNameLibfunc == totalNameLibfuncs)
    {
        expand_libfuncs();
    }

    int i;
    for(i=0; i<currNameLibfunc; i++)
    {
        if(!strcmp(namedLibfuncs[i],s))
        {
            return i;
        }
    }
    namedLibfuncs[currNameLibfunc] = strdup(s);
    return currNameLibfunc++; 
    return 0;
}
/* -------------------------------- */


/* Apothikeusi arithmou ths return address, gia tis jump */
void patch_incomplete_jumps(){    
    int i;
    incomplete_jump* x = ij_head;

    for(i=0; i < ij_total; i++){ /*for each incomplete jump do */
        /*dial14/slide 16 */
        if(x->iaddress == nextquadlabel()){
            instructions[x->instrNo].result->val = nextinstructionlabel();
        }else{
            instructions[x->instrNo].result->val = quads[x->iaddress].taddress;
        }
        x = x->next; /* prokeimenou na pigainw stin epomeni thesi, diaforetika pigainei kathe fora stin idia */
    }
}

/* Paragwgi instruction (afora oses entoles xrisimopoioun OLA ta operands) */
void generate (vmopcode op, quad* q){
    instruction t;
    t.opcode = op;
    make_operand(q->arg1, &t.arg1);
    make_operand(q->arg2, &t.arg2);
    make_operand(q->result, &t.result);
    q->taddress = nextinstructionlabel();     
    emit_instr(t);
}

/*pernane to antistoixo opcode analoga me thn arithmitiki praxi add, sub, mul klp */
void generate_ADD (quad* q) { generate(add_v, q); }
void generate_SUB (quad* q) { generate(sub_v, q); }
void generate_MUL (quad* q) { generate(mul_v, q); }
void generate_DIV (quad* q) { generate(div_v, q); }
void generate_MOD (quad* q) { generate(mod_v, q); }
void generate_NEWTABLE      (quad* q) { generate(newtable_v, q); }
void generate_TABLEGETELEM  (quad* q) { generate(tablegetelem_v, q); }
void generate_TABLESETELEM  (quad* q) { generate(tablesetelem_v, q); }
void generate_ASSIGN        (quad* q) { generate(assign_v, q); }
void generate_NOP           ()        { instruction t; t.opcode=nop_v; emit_instr(t); }

/* afora tis entoles sykrisis poy isws xreiastei i eisagwgi enos incomplete_jump */
void generate_relational (vmopcode op, quad* q){
    instruction t;
    t.opcode = op;
    make_operand(q->arg1, &t.arg1);
    make_operand(q->arg2, &t.arg2);
    t.result = malloc(sizeof(vmarg));
    t.result->type = label_a;
    if (q->label < currprocessedquad){     
        t.result->val = quads[q->label].taddress;
    }
    else{
    /* p.x. quads: 10 jump 30, enw instructions: 10 jump 40 */
    /* Epeidi den kserei eksarxis to jump pou tha antistoixithei sta instr, 
        to krataw se mia lista(to jump) */
        add_incomplete_jump(nextinstructionlabel(), q->label);
    } 
    q->taddress = nextinstructionlabel();
    emit_instr(t);
}

/*antistoixa aples me tis add, sub, mul klp */
void generate_JUMP          (quad* q) { generate_relational(jump_v, q); }
void generate_IF_EQ         (quad* q) { generate_relational(jeq_v, q); }
void generate_IF_NOTEQ      (quad* q) { generate_relational(jne_v, q); }
void generate_IF_GREATER    (quad* q) { generate_relational(jgt_v, q); }
void generate_IF_GREATEREQ  (quad* q) { generate_relational(jge_v, q); }
void generate_IF_LESS       (quad* q) { generate_relational(jlt_v, q); }
void generate_IF_LESSEQ     (quad* q) { generate_relational(jle_v, q); }

/* Metatropi 'not' se 4 entoles */
void generate_NOT (quad* q){
    q->taddress = nextinstructionlabel();       
    instruction t;
    /*ginetai me jeq, assign, jump, assign */
    t.opcode = jeq_v;
    make_operand(q->arg1, &t.arg1);
    make_booloperand(&t.arg2, false);
    t.result = malloc(sizeof(vmarg));
    t.result->type = label_a;
    t.result->val = nextinstructionlabel()+3;
    emit_instr(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, false);
    // reset_operand(t.arg2); /* Anti gia autin, kaname to apo katw */
    t.arg2 = NULL;
    make_operand(q->result, &t.result);
    emit_instr(t);

    t.opcode = jump_v;
    t.arg1 = NULL;
    t.arg2 = NULL;
    t.result = malloc(sizeof(vmarg)); /* Proekypse malloC gia to result, logw ** stin make_oper */
    t.result->type = label_a;
    t.result->val = nextinstructionlabel()+2;
    emit_instr(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, true);
    t.arg2 = NULL;
    make_operand(q->result, &t.result);
    emit_instr(t);
}

/* Metatropi 'or' se 5 entoles */
void generate_OR (quad* q) {
    q->taddress = nextinstructionlabel();         
    instruction t;

    t.opcode = jeq_v;
    make_operand(q->arg1, &t.arg1);
    make_booloperand(&t.arg2, true);
    t.result = malloc(sizeof(vmarg));
    t.result->type = label_a;
    t.result->val = nextinstructionlabel()+4;
    emit_instr(t);

    make_operand(q->arg2, &t.arg1);
    t.result = malloc(sizeof(vmarg));
    t.result->val = nextinstructionlabel()+3;
    emit_instr(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, false);
    t.arg2 = NULL;
    make_operand(q->result, &t.result);
    emit_instr(t);

    t.opcode = jump_v;
    t.arg1 = NULL;
    t.arg2 = NULL;
    t.result = malloc(sizeof(vmarg));
    t.result->type = label_a;
    t.result->val = nextinstructionlabel()+2;
    emit_instr(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, true);
    t.arg2 = NULL;
    make_operand(q->result, &t.result);
    emit_instr(t);
}

/* Metatropi 'and' se 5 entoles */
void generate_AND (quad* q){
    q->taddress = nextinstructionlabel();         
    instruction t;

    t.opcode = jeq_v;
    make_operand(q->arg1, &t.arg1);
    make_booloperand(&t.arg2, false);
    t.result = malloc(sizeof(vmarg));
    t.result->type = label_a;
    t.result->val = nextinstructionlabel()+4;
    emit_instr(t);

    make_operand(q->arg2, &t.arg1);
    t.result = malloc(sizeof(vmarg));
    t.result->val = nextinstructionlabel()+3;
    emit_instr(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, true);
    t.arg2 = NULL;
    make_operand(q->result, &t.result);
    emit_instr(t);

    t.opcode = jump_v;
    t.arg1 = NULL;
    t.arg2 = NULL;
    t.result = malloc(sizeof(vmarg));
    t.result->type = label_a;
    t.result->val = nextinstructionlabel()+2;
    emit_instr(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, false);
    t.arg2 = NULL;
    make_operand(q->result, &t.result);
    emit_instr(t);
}

/* Metatropi '-', se 'pol/mo me -1' */
void generate_UMINUS(quad* q){
    q->taddress = nextinstructionlabel();         
    instruction t;
    t.opcode = mul_v;
    make_operand(q->arg1, &t.arg1);
    make_numberoperand(&t.arg2,-1); /*sto ena arg apothikeusame mono to -1
                                    kai gia opcode pirame mul */
    make_operand(q->result, &t.result);
    emit_instr(t);
}


void generate_PARAM(quad* q){
    q->taddress = nextinstructionlabel();         
    instruction t;
    t.opcode = pusharg_v;
    make_operand(q->arg1, &t.arg1);
    t.arg2 = NULL;
    t.result = NULL;
    emit_instr(t);
}

/* klisi synartisis */
void generate_CALL(quad* q){
    q->taddress = nextinstructionlabel();         
    instruction t;
    t.opcode = call_v;
    make_operand(q->arg1, &t.arg1);
    t.arg2 = NULL;
    t.result = NULL;
    emit_instr(t);
}

/*afora thn epistrefomeni timi synartisis */
void generate_GETRETVAL(quad* q){
    q->taddress = nextinstructionlabel();         
    instruction t;
    t.opcode = assign_v;
    make_operand(q->result, &t.result);
    make_retvaloperand(&t.arg1);
    t.arg2 = NULL;
    emit_instr(t);
}

/* afora tin arxi tou body mias sinartisis otan afti dilonete*/
void generate_FUNCSTART(quad* q){

    symbol* f;
    f = q->arg1->sym;                               
    f->taddress = nextinstructionlabel()+1;
    q->taddress = nextinstructionlabel()+1;
    ipush(&instrFuncstart,f);

    instruction t;
    
    /* krataw to tadress ths jump */
    set_func_jump(f,nextinstructionlabel());

    /* afora jump pou den exei ginei akoma patched */
    t.opcode = jump_v;
    t.arg1 = NULL;
    t.arg2 = NULL;
    t.result = malloc(sizeof(vmarg));
    t.result->type = label_a;
    emit_instr(t); 

    t.opcode = funcenter_v;
    t.arg1 = NULL;
    t.arg2 = NULL;
    make_operand(q->arg1, &t.result);
    emit_instr(t);
}

/* ftiaxni ena return statement gia mia sinartisi (an yparxei) */
void generate_RETURN(quad* q){
    symbol* f;
    q->taddress = nextinstructionlabel();             
    instruction t;
    /* 1)assign tou apotelesmatos ston retval */
    t.opcode = assign_v;
    make_retvaloperand(&t.result);
    make_operand(q->arg1, &t.arg1);
    t.arg2 = NULL;
    emit_instr(t);

    f = itop(&instrFuncstart);                               
    append(&f->returnList,nextinstructionlabel());      
    /* 2)metavasi sto telos tis synartisis */
    t.opcode = jump_v;
    t.arg1 = NULL;
    t.arg2 = NULL;
    t.result = malloc(sizeof(vmarg));
    t.result->type = label_a;
    emit_instr(t); /* Edw ousiastika pairnw to nextInstLabel tis append gia na kserw pou tha kanw patch*/
}

/* afora pou telionei to body mias sinartisis otan dilonete */
void generate_FUNCEND(quad* q){
    symbol* f = ipop(&instrFuncstart);                                       
    backpatch(&f->returnList, nextinstructionlabel()); 

    /* Edw kanei tin epistrofi tou label (sto opoio tha paei to jump (jump "label")) */
    func_jump_backpatch(f,nextinstructionlabel()+1);

    q->taddress = nextinstructionlabel();                     
    instruction t;
    t.opcode = funcexit_v;
    make_operand(q->arg1, &t.result);
    t.arg1 = NULL;
    t.arg2 = NULL;
    emit_instr(t);
}

/* *IDIA H SEIRA*, me ta opcodes twn quads */
generator_func_t generators[] = {

    generate_ASSIGN,
    generate_ADD,
    generate_SUB,
    generate_MUL,
    generate_DIV,
    generate_MOD,
    generate_UMINUS,
    generate_AND, 
    generate_OR, 
    generate_NOT,
    generate_IF_EQ,
    generate_IF_NOTEQ,
    generate_IF_LESSEQ,
    generate_IF_GREATEREQ,
    generate_IF_LESS,
    generate_IF_GREATER,
    generate_CALL,
    generate_PARAM,
    generate_RETURN,
    generate_GETRETVAL,
    generate_FUNCSTART,
    generate_FUNCEND,
    generate_NEWTABLE,
    generate_TABLEGETELEM,
    generate_TABLESETELEM,
    generate_JUMP
};

/* Edw ginetai i antistoixisi twn opcodes */
void generate_code (){
    int i;
    for(i = 0; i < currQuad; ++i){
        (*generators[quads[i].op])(quads+i);
        currprocessedquad++;        /* afora to "process" quad (->stadiaka tha ftasei to akrives currQuad) */
    }
    patch_incomplete_jumps();
}

/* krataei (tin thesi pou vrisketai)to jump(ths funcstart)(ANA function) !pou den exei oloklirwthei! , 
    kai to kanei patch(me tin func_jump_backpatch) stin funcend */
void set_func_jump(symbol* function, int address){
    function->fun_jump = address;       /* fun_jump: to taddress tou jump, prin to funcstart */
}
/* Syndyastiki me tin set_func_jump */
/* Kanei patch to label, pou tha epistrepsei apo tin funcend */
/* Epistrefei sto jump ths funcstart kai ths leei se poio label tha paei
    (to opoio den to gnwrize, mexri na teleiwsei h func) */
void func_jump_backpatch(symbol* function, int label){
    instructions[function->fun_jump].result->val = label; 
}

/* KANEI TO 'SET' 
 Krataei oles tis jump (pou dimiourgithikan apo return) se mia lista,
 gia na kseroume pou tha pigenoun ektos sinartisis (sto funcend) */
void append(returnList** list, unsigned label){
    if(*list == NULL){
        *list = (returnList*)malloc(sizeof(returnList));
        (*list)->next = NULL;
        (*list)->prev = NULL;
        (*list)->data = label;
        return;
    }

    returnList* temp = *list;
    while(temp->next != NULL){
        temp = temp->next;
    }
    returnList* newnode = (returnList*)malloc(sizeof(returnList));
    newnode->data = label;
    newnode->next = NULL;
    newnode->prev = temp;
    temp->next = newnode;
}

/* Antistoixi ylopoiisi me append */
/* 1)Krataw tin thesi tou jump sta instr(antistoixei me tou quad)
   2)Krataw to label pou kanei jump sta instr(antistoixo me tou quad)  */
/* Prosthetei se mia lista kathe incomplete jump(gia ta instructions), mexri na
    vrei to label pou tha paei, afou oloklirwthei opoiadipote sygkrisi  */
void add_incomplete_jump (unsigned instrNo, unsigned iaddress){

    incomplete_jump* new_incJump; /* Den xreiazetai extra xwro */
    
    if(ij_head != NULL){
        new_incJump=ij_head;    /* Pigainw sto head */
        while(new_incJump->next!=NULL){
            new_incJump = new_incJump->next; /*diasxisi*/
        }
        incomplete_jump* temp = (incomplete_jump*)malloc(sizeof(incomplete_jump));
        temp->instrNo= instrNo;
        temp->iaddress = iaddress;
        temp->next = NULL;
        new_incJump->next = temp;
    }else{
        ij_head = (incomplete_jump*)malloc(sizeof(incomplete_jump));
        ij_head->next = NULL;
        ij_head->instrNo = instrNo;
        ij_head->iaddress = iaddress;
    }
    ij_total++;
}

/* Diatrexei oli tin lista(pou pire apo append) kai ftiaxnei to label pou tha paei */
void backpatch(returnList** list, unsigned label){
/* Afou oloklirwthoun oles oi "jump" tis list(pou dimiourgithikan apo ta return), 
    pigainoun sto label */
    returnList* temp = *list;
    while(temp != NULL)
    {
        instructions[temp->data].result->val = label;
        temp = temp->next;
    }
}

/* Epistrefei TOP stoixeio */
symbol* itop(instr_stack **komvos){
    struct instr_stack *tmp = *komvos;
    return tmp->data;
}

/* push kai pop synartiseis gia ta instruction antistoixa me ths triths fashs */
void ipush(instr_stack **komvos, symbol* i){

    struct instr_stack *newlist = (instr_stack*)malloc(sizeof(instr_stack));
    newlist->next = *komvos;
    *komvos =newlist;

    newlist->data = i;

}

symbol* ipop(instr_stack **komvos){
    
    if(*komvos==NULL){
        exit(1);
    }else{
        struct instr_stack *tmp = *komvos;
        symbol* k = (*komvos)->data; /* apothikevw sto k ta data tou stoixeioy poy svinw */
        *komvos = (*komvos)->next;
        free(tmp);
        return k;
    }
}

/* Epistrefi to currInstruction */
unsigned nextinstructionlabel(){
    return currInstruction;
}

/*epistrefei ton opcode gia kathe quad*/
void printmyOp_instr(vmopcode opcode){
    switch(opcode){
        
        case assign_v:          printf("assign");           return;
        case add_v:             printf("add");              return;
        case sub_v:             printf("sub");              return;
        case mul_v:             printf("mul");              return;
        case div_v:             printf("div");              return;
        case mod_v:             printf("mod");              return;
        case uminus_v:          printf("uminus");           return;
        case and_v:             printf("and");              return;
        case or_v:              printf("or");               return;
        case not_v:             printf("not");              return;
        case jeq_v:             printf("jeq");              return;
        case jne_v:             printf("jne");              return;
        case jle_v:             printf("jle");              return;
        case jge_v:             printf("jge");              return;
        case jlt_v:             printf("jlt");              return;
        case jgt_v:             printf("jgt");              return;
        case call_v:            printf("call");             return;
        case pusharg_v:         printf("pusharg");          return;
        case funcenter_v:       printf("funcenter");        return;
        case funcexit_v:        printf("funcexit");         return;
        case newtable_v:        printf("newtable");         return;
        case tablegetelem_v:    printf("tablegetelem");     return;
        case tablesetelem_v:    printf("tablesetelem");     return;
        case nop_v:             printf("nop");              return;
        case jump_v:            printf("jump");             return;
    }
}

/*ektypwnei to kathe expression poy einai apothikevmeno sto quad */
 void print_vmarg(vmarg* arg){

    if(arg == NULL){
        printf("\t");
        return;
    }

    switch(arg->type){
        
        case label_a:       printf("label: %d   \t", arg->val);
                            return;
        case global_a:      printf("global: %d  \t",arg->val);
                            return;
        case formal_a:      printf("formal: %d  \t",arg->val);
                            return;
        case local_a:       printf("local: %d   \t",arg->val);
                            return;
        case number_a :     printf("number:%d  %f \t",arg->val, numConsts[arg->val]);
                            return;
        case string_a:      printf("string:%d  %s \t",arg->val, stringConsts[arg->val]);
                            return;
        case bool_a:        printf("bool: %d\t", arg->val);
                            return;
        case userfunc_a:    printf("userfunc:%d  %s \t",arg->val, userFuncs[arg->val].id);
                            return;
        case libfunc_a :    printf("libfunc:%d  %s \t",arg->val, namedLibfuncs[arg->val]);
                            return;   
        case retval_a :     printf("retval_a \t");
                            return;
        case nil_a :        printf("nil\t");
        }
} 
/* Ektypwsi olwn tvn instructions (totalInstr>=totalQuads) */

void printmyInstructions (){
    int i;
 
    printf("\nCurrInstructions = %d\n\n", currInstruction);
    printf("\n-----------------------------------------------------------------\n");
    printf("\ninstruction#%10s%15s%10s%10s%10s\n","opcode","result","arg1","arg2","srcLine");
    for(i=0; i < currInstruction; i++){

        printf("%d:\t\t", i);
        printmyOp_instr(instructions[i].opcode);
        printf("\t\t");
        print_vmarg(instructions[i].result);
        print_vmarg(instructions[i].arg1);      
        print_vmarg(instructions[i].arg2);

        printf("\n");
    }
}

/*dimiourgia binary file tetartis fashs */
void binaryFile_Creation(){

    FILE *file;
    int i;

    if((file = fopen("binary.abc","wb")) == NULL){
        fprintf(stderr,"There is no space\n");
    }    

    // int magicnumber = 340200501;
    
    // fwrite(&magicnumber, sizeof(int), 1, file);

    /* Numbers total*/
    fwrite(&currNumConst, sizeof(currNumConst), 1, file); /* "1" einai lekseis ana ektypwsi */
    /* Numbers array*/
    for(i = 0 ; i<currNumConst; i++){
        fwrite(&numConsts[i], sizeof(numConsts), 1, file);
    }
    /* String total */
    fwrite(&currStringConst, sizeof(currStringConst), 1, file);
    /* String array */
    for(i = 0 ; i<currStringConst; i++){
        int size_str = strlen(stringConsts[i]); /* megethos string */
        fwrite(&size_str, sizeof(int), 1, file);/* Epeidi einai string, prepei na kserw ton arithmo twn xaraktirwn */
        fwrite(stringConsts[i], sizeof(char) * size_str , 1, file); /* xwris '*' giati einai pointer */
    }
    /* Library Functions total */
    fwrite(&currNameLibfunc, sizeof(currNameLibfunc), 1, file);
    /* Library Functions array */
    for(i = 0 ; i<currNameLibfunc; i++){
        int size_libfun = strlen(namedLibfuncs[i]);
        fwrite(&size_libfun, sizeof(int), 1, file);/* Epeidi einai string, prepei na kserw ton arithmo twn stoixeiwn */
        fwrite(namedLibfuncs[i], sizeof(char) * size_libfun , 1, file);
    }

    /* User Functions total */
    fwrite(&currUserFunc, sizeof(currUserFunc), 1, file);
    /* User Functions array */
    for(i = 0 ; i<currUserFunc; i++){
        int size_userfun = strlen(userFuncs[i].id);

        fwrite(&(userFuncs[i].address), sizeof(unsigned), 1, file);/* User Function address */
        fwrite(&userFuncs[i].localSize, sizeof(unsigned), 1, file);/* User Function localSize */
        fwrite(&size_userfun, sizeof(int), 1, file);/* Epeidi einai string, prepei na kserw ton arithmo twn stoixeiwn */
        fwrite(userFuncs[i].id, sizeof(char) * size_userfun, 1, file);/* User Function id */

    }
    /* Instructions total */
    fwrite(&currInstruction, sizeof(currInstruction), 1, file);
    /* Instructions array */
    /* Dimiourgw metavliti pou deixnei poioi operand einai 'energoi'
        (Dld an exoun parei ola ta operands(arg1,arg2,result) timi) */
    int flag; 
    for(i = 0; i<currInstruction; i++){
        fwrite(&instructions[i].opcode, sizeof(vmopcode), 1, file);
        /* Instruction operand*/
        if(instructions[i].arg1 != NULL){
            flag=1;
            fwrite(&flag, sizeof(int), 1, file);
            /* Instruction type */
            fwrite(&instructions[i].arg1->type ,sizeof(instructions[i].arg1->type), 1, file);
            /* Instruction value */
            fwrite(&instructions[i].arg1->val ,sizeof(unsigned), 1, file);
        }
        if(instructions[i].arg2 != NULL){
            flag=2;
            fwrite(&flag, sizeof(int), 1, file);
            fwrite(&instructions[i].arg2->type ,sizeof(instructions[i].arg2->type), 1, file);
            fwrite(&instructions[i].arg2->val ,sizeof(unsigned), 1, file);
        }        
        if(instructions[i].result != NULL){
            flag=3;
            fwrite(&flag, sizeof(int), 1, file);
            fwrite(&instructions[i].result->type ,sizeof(instructions[i].result->type), 1, file);
            fwrite(&instructions[i].result->val ,sizeof(unsigned), 1, file);
        }
        flag=4;     /* Me timi=4 deixnw oti exw oloklirwsei to KATHE instruction*/
        fwrite(&flag, sizeof(int), 1, file);
   }

    fclose(file);

}