#include "dispatcher.h"

#define AVM_ENDING_PC codeSize

char* typeStrings[] = {
	"number",
	"string",
	"bool",
	"table",
	"userfunc",
	"libfunc",
	"nil",
	"undef"
};

typedef void (*execute_func_t)(instruction*);

unsigned char 	executionFinished = 0;
unsigned		pc = 0;
unsigned		currLine = 0;
unsigned 		codeSize = 0;
instruction* 	code = (instruction*) 0;
unsigned totalActuals;

execute_func_t executeFuncs[]={
	execute_assign,
	execute_add,
	execute_sub,
	execute_mul,
	execute_div,
	execute_mod,
    execute_uminus,
    execute_and,
	execute_or,
	execute_not,
	execute_jeq,
	execute_jne,
	execute_jle,
	execute_jge,
	execute_jlt,
	execute_jgt,
	execute_call,
	execute_pusharg,
	execute_funcenter,
	execute_funcexit,
	execute_newtable,
	execute_tablegetelem,
	execute_tablesetelem,
	execute_nop,
    execute_jump
};

/*ylopoihsh arithmitikwn entolwn */
double add_impl (double x, double y) { return x+y; }
double sub_impl (double x, double y) { return x-y; }
double mul_impl (double x, double y) { return x*y; }
double div_impl (double x, double y) { return x/y; }
double mod_impl (double x, double y) {
return ((unsigned) x) % ((unsigned) y);}

/* Dispatcher just for arithmetic functions. */
arithmetic_func_t arithmeticFuncs [] = {
	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl
};

void execute_assign (instruction* instr){
	/* den thelw "&"instr->result(diladi dieythinsi), pairnw opws einai tin timi */
	 avm_memcell* lv = avm_translate_operand(instr->result, (avm_memcell*) 0);
	 avm_memcell* rv = avm_translate_operand(instr->arg1, &ax);

	assert(lv && (&stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv == &retval));
	assert(rv);
	avm_assign(lv,rv);
}

/*afora tis arithmitikes ekfraseis */
void execute_arithmetic (instruction* instr){
	avm_memcell* lv = avm_translate_operand (instr->result, (avm_memcell*) 0);
	avm_memcell* rv1 = avm_translate_operand (instr->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand (instr->arg2, &bx);

	assert (lv && ((&stack[AVM_STACKSIZE-1] >= lv) && (lv > &stack[top]) || (lv == &retval)));
	assert (rv1 && rv2);

	if (rv1->type != number_m || rv2->type != number_m) {
		avm_error("not a number in arithmetic!\n","DEN KSERW","DEN KSERWW");
		exit(1);
		executionFinished = 1;
	}
	else {
		arithmetic_func_t op = arithmeticFuncs[instr->opcode - add_v];
		avm_memcellclear (lv);
		lv->type = number_m;
		
		if((instr->opcode == div_v || instr->opcode == mod_v) && rv2->data.numVal==0){
			avm_error("number zero in mod div!\n","DEN KSERW","DEN KSERWW");
			executionFinished = 1;
			exit(0);
		}else{

			lv->data.numVal = (*op) (rv1->data. numVal, rv2->data. numVal);
		}
	}
}

/*metatropes tobool gia na mporoyn na ginoun oi sygkriseis */
unsigned char number_tobool (avm_memcell* m) { return m->data. numVal != 0; }
unsigned char string_tobool (avm_memcell* m) { return m->data.strVal [0] != 0; }
unsigned char bool_tobool (avm_memcell* m) { return m->data. boolVal; }
unsigned char table_tobool (avm_memcell* m) { return 1; } /*panta true*/
unsigned char userfunc_tobool (avm_memcell* m) { return 1; }
unsigned char libfunc_tobool (avm_memcell* m) { return 1; }
unsigned char nil_tobool (avm_memcell* m) { return 0; }
unsigned char undef_tobool (avm_memcell* m) {assert (0); return 0; }

tobool_func_t toboolFuncs [] = {
	number_tobool,
	string_tobool,
	bool_tobool,
	table_tobool,
	userfunc_tobool,
	libfunc_tobool,
	nil_tobool,
	undef_tobool
};

unsigned char avm_tobool (avm_memcell* m) {
	assert (m->type >= 0 && m->type < undef_m);
	return (toboolFuncs [m->type]) (m);
}

/*if equal dinetai */
void execute_jeq (instruction* instr) {
    
	assert (instr->result->type == label_a);
	avm_memcell* rv1 = avm_translate_operand(instr->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(instr->arg2, &bx);

	unsigned char result = 0;

	/*sygkrisi typwn twn rv1 rv2 kai elegxos gia isotites */
	if (rv1->type == undef_m || rv2->type == undef_m){
		avm_error("undef' involved in equality!\n","DEN KSERW","DEN KSERWW");
	}else if (rv1->type == bool_m || rv2->type == bool_m){
		result = (avm_tobool(rv1) == avm_tobool (rv2));
	}else if (rv1->type == nil_m || rv2->type == nil_m){
		result = rv1->type == nil_m && rv2->type == nil_m;
	}else if (rv1->type != rv2->type){
		avm_error("%s ==%s is illegal!",
			typeStrings[rv1->type],
			typeStrings[rv2->type]);
	}else{
		/*Equality check with dispatching*/
		/*Εδώ συμπληρώστε την υλοποίηση. Αρκεί να κάνετε dispatching ως προς τον τύπο του rv1*/
		
		if(rv1->type == number_m)
		{
			if(rv1->data.numVal == rv2->data.numVal){
				result= 1;
			}else{
				result= 0;
			}
		}
		else if(rv1->type == string_m){
			if(strcmp(rv1->data.strVal, rv2->data.strVal) == 0){
				result= 1;
			}else{
				result= 0;
			}
		}
		else if(rv1->type == userfunc_m){
			// printf("RV11 == %d\n",rv1->data.funcVal);
			// printf("RV222 == %d\n",rv2->data.funcVal);
			if(rv1->data.funcVal == rv2->data.funcVal){
				result= 1;
			}else{
				result= 0;
			}
		}
		else if(rv1->type == libfunc_m){

			if(strcmp(rv1->data.libfunc_Val, rv2->data.libfunc_Val) == 0){
				result= 1;
			}else{
				result= 0;
			}
		}
	}

	if (!executionFinished && result){
	    pc = instr->result->val;
    }
}

/* paromoia me thn jeq me thn moni diafora
oti xrisimopoieitai to symvolo anisotitas */
void execute_jne(instruction* instr) {
    
	assert (instr->result->type == label_a);
	avm_memcell* rv1 = avm_translate_operand(instr->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(instr->arg2, &bx);

	unsigned char result = 0;
	
	if (rv1->type == undef_m || rv2->type == undef_m){

		avm_error("undef' involved in equality!","DEN KSERW","DEN KSERWW");
		
	}else if (rv1->type == bool_m || rv2->type == bool_m){
		result = (avm_tobool(rv1) != avm_tobool (rv2));
	}else if (rv1->type == nil_m || rv2->type == nil_m){
		result = rv1->type != nil_m || rv2->type != nil_m;
	}else if (rv1->type != rv2->type){
		avm_error("%s != %s is illegal!",
			typeStrings[rv1->type],
			typeStrings[rv2->type]);
	}else{
		if(rv1->type == number_m)
		{
			if(rv1->data.numVal != rv2->data.numVal){
				result= 1;
			}else{
				result= 0;
			}
		}
		else if(rv1->type == string_m){
			if(strcmp(rv1->data.strVal, rv2->data.strVal) != 0){
				result= 1;
			}else{
				result= 0;
			}
		}
		else if(rv1->type == userfunc_m){
			if(rv1->data.funcVal != rv2->data.funcVal){
				result= 1;
			}else{
				result= 0;
			}
		}
		else if(rv1->type == libfunc_m){

			if(strcmp(rv1->data.libfunc_Val, rv2->data.libfunc_Val) != 0){
				
				result= 1;
			}else{
				result= 0;
			}
		}
		
	}

	if (!executionFinished && result){
	    pc = instr->result->val;
    }
}

/* Oi entoles pou exon sygkrisi JGE,JGT,JLE,JLT aforoun MONO arithmous */

/* To 2o meros, vasei twn dialexewn, ilopoihthike opws h execute arithmetic 
(oson afora ton TYPO)*/
void execute_jle (instruction* t){
	
	assert (t->result->type == label_a);
	avm_memcell* rv1 = avm_translate_operand(t->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(t->arg2, &bx);

	unsigned char result = 0;

	if (rv1->type != number_m || rv2->type != number_m) {
		avm_error("not a number in arithmetic!","DEN KSERW","DEN KSERWW");
		executionFinished = 1;
	}else {
		/*edw ginetai o elegxos gia less equal */
		if(rv1->data.numVal <= rv2->data.numVal){
			result= 1;
		}else{
			result= 0;
		}
	}

	if (!executionFinished && result){
	    pc = t->result->val;
    }
}

/* To 2o meros, vasei twn dialexewn, ilopoihthike opws h execute arithmetic 
(oson afora ton TYPO)*/
void execute_jge (instruction* t){
	
	assert (t->result->type == label_a);
	avm_memcell* rv1 = avm_translate_operand(t->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(t->arg2, &bx);

	unsigned char result = 0;

	if (rv1->type != number_m || rv2->type != number_m) {
		avm_error("not a number in arithmetic!","DEN KSERW","DEN KSERWW");
		executionFinished = 1;
	}else {
		/*edw ginetai o elegxos gia greater equal */
		if(rv1->data.numVal >= rv2->data.numVal){
			result= 1;
		}else{
			result= 0;
		}
	}

	if (!executionFinished && result){
	    pc = t->result->val;
    }
}

/*vasei twn dialexewn ilopoihthike opws h execute arithmetic*/
void execute_jlt (instruction* t){
	
	assert (t->result->type == label_a);
	avm_memcell* rv1 = avm_translate_operand(t->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(t->arg2, &bx);

	unsigned char result = 0;

	if (rv1->type != number_m || rv2->type != number_m) {
		avm_error("not a number in arithmetic!","DEN KSERW","DEN KSERWW");
		executionFinished = 1;
	}else {
		/*edw ginetai o elegxos gia less than */
		if(rv1->data.numVal < rv2->data.numVal){
			result= 1;
		}else{
			result= 0;
		}
	}

	if (!executionFinished && result){
	    pc = t->result->val;
    }
}

/*vasei twn dialexewn ilopoihthike opws h execute arithmetic*/
void execute_jgt (instruction* t){
	
	assert (t->result->type == label_a);
	avm_memcell* rv1 = avm_translate_operand(t->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(t->arg2, &bx);

	unsigned char result = 0;

	if (rv1->type != number_m || rv2->type != number_m) {
		avm_error("not a number in arithmetic!","DEN KSERW","DEN KSERWW");
		executionFinished = 1;
	}else {
		/*edw ginetai o elegxos gia greater than*/
		if(rv1->data.numVal > rv2->data.numVal){
			result= 1;
		}else{
			result= 0;
		}
	}

	if (!executionFinished && result){
	    pc = t->result->val;
    }
}

/*paragwgi calls */
void execute_call (instruction* instr){
	avm_memcell* func = avm_translate_operand(instr->arg1, &ax);
	assert(func);
	switch(func->type){

		case userfunc_m:{
			avm_callsaveenvironment();
			pc = func->data.funcVal;
			assert(pc < AVM_ENDING_PC);
			assert(code[pc].opcode == funcenter_v);
			break;
		}
		case string_m: 	avm_calllibfunc(func->data.strVal); break;
		case libfunc_m: avm_calllibfunc(func->data.libfunc_Val); break;
		// case table_m: 	avm_calllibfunc(func->data.tableVal); break;

		default: {
			char* s = avm_tostring(func);
			avm_error("call: cannot bind '%s' to function!\n",s ,NULL);
			free(s);
			executionFinished = 1;
		}
	}
}

/*calling functions slide 26 */
void execute_pusharg (instruction* instr){
	avm_memcell* arg = avm_translate_operand(instr->arg1, &ax);
	assert(arg);
	/* This is actually stack[top] = arg, but we have to use avm_assign*/
	avm_assign(&stack[top], arg);
	++totalActuals;
	avm_dec_top();
}

/* Pairnw ton pinaka gia na ton xrisimopoiisw stin avm_getfuncinfo */
extern userfunc* userFuncs;

userfunc* avm_getfuncinfo(unsigned pc){
	return &userFuncs[code[pc].result->val];
}

/*slide 23 calling functions */
void execute_funcenter (instruction* instr){
	avm_memcell* func = avm_translate_operand(instr->result, &ax);
	assert(func);
	assert(pc == func->data.funcVal);

	totalActuals = 0;
	userfunc* funcInfo = avm_getfuncinfo(pc);
	topsp = top;
	top = top - funcInfo->localSize;
}

/*slide 23
epanafora tou proigoumenou perivallontos kai epistrofi apo thn klisi
& katharismos tou activation record */
void execute_funcexit (instruction* unused){
	unsigned oldTop = top;
	top = avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
	pc = avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
	topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);

	while(++oldTop <= top)
		avm_memcellclear(&stack[oldTop]);
}

void execute_newtable (instruction* instr){

	avm_memcell* lv = avm_translate_operand(instr->arg1, (avm_memcell*) 0);
	assert(lv && (&stack[AVM_STACKSIZE-1] >= lv && &stack[top] || lv == &retval));

	avm_memcellclear(lv);

	lv->type = table_m;
	lv->data.tableVal = avm_tablenew();
	avm_tableincrefcounter(lv->data.tableVal);/*afxisi metriti anaforwn
												kathws arxika o metritis einai 0 */
}

void execute_tablegetelem (instruction* instr){

	avm_memcell* lv = avm_translate_operand(instr->result, (avm_memcell*) 0);
	avm_memcell* t = avm_translate_operand(instr->arg1, (avm_memcell*) 0);
	avm_memcell* i = avm_translate_operand(instr->arg2, &ax);

	assert(lv && &stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv == &retval);
	assert(t && &stack[AVM_STACKSIZE-1] >= t && t > &stack[top]);
	assert(i);

	avm_memcellclear(lv);
	lv->type =nil_m;

	if(t->type != table_m){
		avm_error("illegal1 use of type %s as table!\n", typeStrings[t->type], NULL);
	}else{
		avm_memcell* content = avm_tablegetelem(t->data.tableVal,i);
		if(content)
			avm_assign(lv,content);
		else{
			/*se periptwsi poy to kleidi den yparxei
			h den ypostirizetai kleidi sygkekrimenoy typou */
			char* ts = avm_tostring(t);
			char* is = avm_tostring(i);
			avm_warning("%s[%s] not found!",ts,is);
			free(ts);
			free(is);
		}
	}
}

/*h ylopoihsh vasizetai sthn avm_tablesetelem */
void execute_tablesetelem(instruction* instr){
	avm_memcell* t = avm_translate_operand(instr->arg1, (avm_memcell*)0);
	avm_memcell* i = avm_translate_operand(instr->result, &ax);
	avm_memcell* c = avm_translate_operand(instr->arg2, &bx);

	assert(t && &stack[AVM_STACKSIZE-1] >= t && t > &stack[top]);
	assert(i && c);

	if(t->type != table_m)
		avm_error("illegal2 use of type %s as table!\n",typeStrings[t->type], NULL);
	else
		avm_tablesetelem(t->data.tableVal, i, c);
}

/* no operation */
void execute_nop (instruction* t){
	printf("Execute NOP\n");
}

void execute_uminus (instruction* t){}
void execute_and (instruction* t){}
void execute_or (instruction* t){}
void execute_not (instruction* t){}

/* To pc pairnei tin timi tou apotelesmatos tou instr pou pigainei to jump */
void execute_jump (instruction* t){
	
	if (!executionFinished){
	    pc = t->result->val;
    }
}

/* vasei toy dispatcher executeFuncs pou exei ta opcodes twn execute, tha epilexei
 thn antistoixi execute */
void execute_cycle (void){
	if (executionFinished)
		return;
	else
		if(pc == AVM_ENDING_PC){
			executionFinished = 1;
			exit(0);
			return;
		}
		else{
			assert(pc < AVM_ENDING_PC);
			instruction* instr = code + pc;
			assert(
				instr->opcode >= 0 &&
				instr->opcode <= AVM_MAX_INSTRUCTIONS
				);

			if(instr->srcLine)
				currLine = instr->srcLine;
			unsigned oldPC = pc;
			(*executeFuncs[instr->opcode])(instr);
/* To pc tha allazei logw jump, call, return apo call, alliws pame stin epomeni entoli */
			if(pc == oldPC)
				++pc;
		}
}

