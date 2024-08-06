%{
// Definitions of Macros/Functions/Variables 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "symtable.h"

#define EXPAND_SIZE 1024
#define CURR_SIZE (total*sizeof(quad))
#define NEW_SIZE (EXPAND_SIZE * sizeof(quad)+CURR_SIZE)

int scope = 0;
int metritis=0;
int tempcounter = 0;
int loopcounter = 0;
int infunctioncounter = 0;
int inloopcounter = 0;
void yyerror(const char* yaccProvidedMessage);
int yylex(void);

const char* getType(enum SymbolType type);

extern int yylineno;
extern char* yytext;
extern FILE* yyin;

/*---------- C Phase -------- */


typedef enum iopcode{
    assign,         add,            sub, 
    mul_1,          div_1,          mod, 
    uminus,         and,            or,
    not,            if_eq,          if_noteq, 
    if_lesseq,      if_greatereq,   if_less,
    if_greater,     call,           param,
    ret,            getretval,      funcstart,
    funcend,        tablecreate,    tablegetelem,
    tablesetelem,   jump
}iopcode;

typedef enum expr_t{

    var_e,          tableitem_e,
    programfunc_e,  libraryfunc_e,
    arithexpr_e,    boolexpr_e, 
    assignexpr_e,   newtable_e,
    constnum_e,     constbool_e,
    conststring_e,  nil_e
}expr_t;


typedef struct expr{
    expr_t          type;
    symbol*         sym;
    struct expr*    index;
    double          numConst;
    char*           strConst;
    unsigned char   boolConst;
    struct expr*    next;
}expr;

typedef struct quad{
    iopcode op;
    expr* result;
    expr* arg1;
    expr* arg2;
    unsigned label;
    unsigned line;
}quad;

typedef struct stmt_t{
    int breakList;
    int contList;
}stmt_t;

typedef struct list_t{
    expr* arg;     /* key */
    expr* value;
    struct list_t *next;
    struct list_t *previous;
}list_t;

typedef struct call_l{
    list_t*           elist;
    unsigned char   method;
    char*           name;
}call_l;

typedef struct for_t{
    int enter;
    int test;
}for_t;

typedef struct stack{
    int data;
    struct stack *next;
}stack;

stack* scopeoffsetstack = NULL; /* stack pou afora to offset */
stack* loopcounterstack = NULL; /* stack pou afora ton loopcounter, gia na elegxw an eimai se block kapoiou loop */

quad* quads = (quad*)0; /* "quads"= o pinakas me ola ta quad */
unsigned total = 0;     /* apothikeuei ton arithmo twn quads */
unsigned int currQuad = 0; /* se kathe neo quad, kanw to currQuad++ kai dinei to current Quad */ 

/* Prototypes synartisewn */
void emit(iopcode op ,expr * arg1, expr * arg2, expr * result, int label, unsigned int line);
void comperror(char* format);
void check_arith(expr* e,  char* context);
expr* newexpr(expr_t t);
expr* newexpr_conststring(char* s);
expr* newexpr_constnum(double i);
expr* newexpr_constbool(unsigned int b);
expr* emit_iftableitem(expr* e);
expr* make_call(expr* lv, list_t* reversed_elist);
expr* member_item(expr* lv, char*name);
unsigned nextquadlabel(void);
void patchlabel(unsigned quadNo, unsigned label);
char* newFunName(char *onoma, int d);
char* newtempname();
symbol* newtemp();
unsigned int istempname(char* s);
unsigned int istempexpr(expr* e);
void resettemp();
void resetformalargsoffset(void);
void resetfunctionlocaloffset(void);
scopespace_t currscopespace(void);
unsigned currscopeoffset (void);
void inccurrscopeoffset (void);
void restorecurrscopeoffset(unsigned n);
expr* lvalue_expr(symbol* sym);
void enterscopespace (void);
void existscopespace (void);
stmt_t* make_stmt(stmt_t* s);
int newlist(int i);
int mergelist(int l1, int l2);
void patchlist(int list, int label);
void push(stack **komvos, int i);
int pop(stack **komvos);
void print_exprType(expr* ex);
void* printmyQuad();
%}

 /* Dilwseis YACC */
 /* Symvola grammatikis */
%start program
 /* Anamenoume X conflicts apo tin grammatiki */
%expect 1 /* Edw 1, logw ifelsestm */

/* Den to pairnei opws to dinei sto front */
%define parse.error verbose // Parexei leptomeri eksigisi tou error
 /*%error-verbose */

 /* Union: periexei tous vasikous typous poy yparxei se mia glwssa */
%union {
    char* stringValue;
    int intValue;
    double doubValue;
    struct expr* exprValue;
    struct symbol* symValue;
    struct call_l* callValue;
    struct for_t* forValue;
    struct list_t* listValue;
    struct stmt_t* stmtValue;
}

/* %token   <type>  onoma   arithmos(proeraitika)   "perigrafi"*/
%token <stringValue>            ID                  "id"
%token <intValue>               INT                 "int"
%token <doubValue>              DOUBLE              "double"
%token <stringValue>            STRING	                "string"
%token <stringValue>            IF	                "if"
%token <stringValue>            ELSE	            "else"
%token <stringValue>            THEN	            "then"
%token <stringValue>            FOR	                "for"
%token <stringValue>            WHILE	            "while"
%token <stringValue>            BREAK	            "break"
%token <stringValue>            CONTINUE	        "continue"
%token <stringValue>            RETURN	            "return"
%token <stringValue>            TRUE	            "true"
%token <stringValue>            FALSE	            "false"
%token <stringValue>            NOT	                "not"
%token <stringValue>            AND	                "and"
%token <stringValue>            OR	                "or"
%token <stringValue>            FUNCTION            "function"
%token <stringValue>            NIL	                "nil"  
%token <stringValue>            SIMPLESPACE	        "simplespace"  
%token <stringValue>            NEWLINE             "newline"
%token <stringValue>            MULTISPACE          "multispace"
%token <stringValue>            LINECOMMENT         "linecomment"
%token <stringValue>            LEFTBRACKET         "["
%token <stringValue>            RIGHTBRACKET        "]"
%token <stringValue>            LEFTPARENTHESES     "("
%token <stringValue>            RIGHTPARENTHESES    ")"
%token <stringValue>            LEFTBRACES	        "{"
%token <stringValue>            RIGHTBRACES	        "}"
%token <stringValue>            COLON	            ":"
%token <stringValue>            SEMICOLON	        ";"
%token <stringValue>            COMMA	            ","
%token <stringValue>            FULLSTOP	        "."
%token <stringValue>            DFULLSTOP	        ".."
%token <stringValue>            PLUS                "+"
%token <stringValue>            SUB                 "-"
%token <stringValue>            MULTIPLY            "*"
%token <stringValue>            DIVISION            "/"
%token <stringValue>            PERCENT             "%"
%token <stringValue>            PLUSPLUS            "++"
%token <stringValue>            MINUSMINUS          "--"
%token <stringValue>            EQUAL               "="
%token <stringValue>            NOTEQUAL            "!="
%token <stringValue>            GREATER             ">"
%token <stringValue>            LESS                "<"
%token <stringValue>            LESSEQUAL           "<="
%token <stringValue>            GREATEREQUAL        ">="
%token <stringValue>            EQUALEQUAL          "=="
%token <stringValue>            SCOPERESOLUTION     "::"
%token                          LOCAL

/* Dinw type kai sta mi termatika symvola */
%type <exprValue>   expr term assignexpr primary lvalue member 
%type <exprValue>   returnstmt
%type <exprValue>   call objectdef const
%type <stringValue> funcname
%type <symValue>    funcprefix funcdef
%type <intValue>    funcbody ifprefix elseprefix whilestart whilecond N M
%type <callValue>   callsuffix normcall methodcall
%type <forValue>    forprefix
%type <listValue>   elist indexed indexedelem
%type <stmtValue>   statement stmt block ifstmt forstmt whilestmt

%right      EQUAL
%left       OR
%left       AND
%nonassoc   EQUALEQUAL NOTEQUAL
%nonassoc   GREATER GREATEREQUAL LESS LESSEQUAL
%left       PLUS SUB
%left       MULTIPLY DIVISION PERCENT
%right      NOT PLUSPLUS MINUSMINUS UMINUS
%left       FULLSTOP DFULLSTOP
%left       LEFTBRACKET RIGHTBRACKET
%left       LEFTPARENTHESES RIGHTPARENTHESES

%%
program:    statement           {   printf("---STARTING---\n");   }
            ;

statement:  statement stmt      {   
                                    /* Enwnw tis 2 listes(statement, stmt) gia ta 2 xaraktiristika tous
                                        (breakList, contList) */
                                    $$->breakList = mergelist($1->breakList, $2->breakList); 
                                    $$->contList =  mergelist($1->contList,$2->contList);
                                }
            |                   {   
                                    $$ = make_stmt($$); /* Anagkastiki klisi tis make_stmt, alliws error */
                                }
            | error             {}
            ;



stmt:       expr SEMICOLON          {       
                                        $$ = make_stmt($$);
                                    }
            | ifstmt                {
                                        $$ = $1;
                                    } 
            | whilestmt             {
                                        $$ = $1;
                                    }
            | forstmt               {
                                        $$ = $1;
                                    }
            | returnstmt            {
                                        $$ = make_stmt($$);
                                    }
            | BREAK SEMICOLON       {   
                                        if(loopcounter == 0){
                                            fprintf(stderr,"You are not in loop\n");
                                            exit(1);
                                        }else{
                                            struct stmt_t *giatobreak = (stmt_t*)malloc(sizeof(stmt_t));
                                            $$ = make_stmt($$);
                                            giatobreak = $$;
                                            giatobreak->breakList = newlist(nextquadlabel());
                                            emit(jump, NULL, NULL, NULL, 0, yylineno);
                                        }
                                    }
            | CONTINUE SEMICOLON    {   if(loopcounter == 0){
                                            fprintf(stderr,"You are not in loop\n");
                                            exit(1);
                                        }else{
                                            struct stmt_t *giatocont = (stmt_t*)malloc(sizeof(stmt_t));
                                            $$ = make_stmt($$);
                                            giatocont = $$;
                                            giatocont->contList = newlist(nextquadlabel());
                                            emit(jump, NULL, NULL, NULL, 0, yylineno);
                                        }
                                    }
            | block                 {
                                        $$=$1;    
                                    }
            | funcdef               {
                                        $$ = make_stmt($$);
                                    }
            | SEMICOLON             { $$ = make_stmt($$);}
            ;

expr:       assignexpr                  {       $$ = $1;
                                        }
            | expr PLUS expr            {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                $$ = newexpr(arithexpr_e); /* vazei ton antistoixo typo expr_t se kathe expr */
                                                $$->sym = newtemp();        /* Dinei onoma se kryfi var+elegxei an yparxei to expr sto symtable */
                                                emit(add, $1, $3, $$, 0, yylineno); /* Dimiourgei quad */
                                        } 
            | expr SUB expr             {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                $$ = newexpr(arithexpr_e);
                                                $$->sym = newtemp();
                                                emit(sub, $1, $3, $$, 0, yylineno); 
                                        }
            | expr MULTIPLY expr        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                $$ = newexpr(arithexpr_e);
                                                $$->sym = newtemp();
                                                emit(mul_1, $1, $3, $$, 0, yylineno);
                                        }
            | expr DIVISION expr        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                $$ = newexpr(arithexpr_e);
                                                $$->sym = newtemp();
                                                emit(div_1, $1, $3, $$, 0, yylineno);
                                        }
            | expr PERCENT expr         {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                $$ = newexpr(arithexpr_e);
                                                $$->sym = newtemp();
                                                emit(mod, $1, $3, $$, 0, yylineno);
                                        }
            | expr GREATER expr         {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                $$ = newexpr(boolexpr_e);
                                                $$->sym = newtemp();
                                                emit(if_greater, $1, $3, NULL, nextquadlabel()+3, yylineno);
                                                emit(assign, newexpr_constbool(0), NULL, $$, 0, yylineno);
                                                emit(jump, NULL, NULL, NULL,nextquadlabel()+2, yylineno);
                                                emit(assign, newexpr_constbool(1), NULL, $$, 0, yylineno);
                                        }
            | expr GREATEREQUAL expr    {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                $$ = newexpr(boolexpr_e);
                                                $$->sym = newtemp();
                                                emit(if_greatereq, $1, $3, NULL, nextquadlabel()+3, yylineno);
                                                emit(assign, newexpr_constbool(0), NULL, $$, 0, yylineno);
                                                emit(jump, NULL, NULL, NULL,nextquadlabel()+2, yylineno);
                                                emit(assign, newexpr_constbool(1), NULL, $$, 0, yylineno);
                                        }
            | expr LESS expr            {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                $$ = newexpr(boolexpr_e);
                                                $$->sym = newtemp();
                                                emit(if_less, $1, $3, NULL, nextquadlabel()+3, yylineno);
                                                emit(assign, newexpr_constbool(0), NULL, $$, 0, yylineno);
                                                emit(jump, NULL, NULL, NULL,nextquadlabel()+2, yylineno);
                                                emit(assign, newexpr_constbool(1), NULL, $$, 0, yylineno);
                                        }
            | expr LESSEQUAL expr       {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                $$ = newexpr(boolexpr_e);
                                                $$->sym = newtemp();
                                                emit(if_lesseq, $1, $3, NULL, nextquadlabel()+3, yylineno);
                                                emit(assign, newexpr_constbool(0), NULL, $$, 0, yylineno);
                                                emit(jump, NULL, NULL, NULL,nextquadlabel()+2, yylineno);
                                                emit(assign, newexpr_constbool(1), NULL, $$, 0, yylineno);
                                        }
            | expr EQUALEQUAL expr      {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                $$ = newexpr(boolexpr_e);
                                                $$->sym = newtemp();
                                                emit(if_eq, $1, $3, NULL, nextquadlabel()+3, yylineno);
                                                emit(assign, newexpr_constbool(0), NULL, $$, 0, yylineno);
                                                emit(jump, NULL, NULL, NULL,nextquadlabel()+2, yylineno);
                                                emit(assign, newexpr_constbool(1), NULL, $$, 0, yylineno);
                                        }
            | expr NOTEQUAL expr        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                $$ = newexpr(boolexpr_e);
                                                $$->sym = newtemp();
                                                emit(if_noteq, $1, $3, NULL, nextquadlabel()+3, yylineno);
                                                emit(assign, newexpr_constbool(0), NULL, $$, 0, yylineno);
                                                emit(jump, NULL, NULL, NULL,nextquadlabel()+2, yylineno);
                                                emit(assign, newexpr_constbool(1), NULL, $$, 0, yylineno);
                                        }
            | expr AND expr             {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                $$ = newexpr(boolexpr_e);
                                                $$->sym = newtemp();
                                                emit(and, $1, $3, $$, 0, yylineno);
                                        }
            | expr OR expr              {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                $$ = newexpr(boolexpr_e);
                                                $$->sym = newtemp();
                                                emit(or, $1, $3, $$, 0, yylineno);
                                        }
            | term                      {       $$=$1;
                                        }
            ;

term:       LEFTPARENTHESES expr RIGHTPARENTHESES   {
                                                $$ = $2;
                                                    }
            | SUB expr %prec UMINUS     {

                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol));
                                                check_arith($2,"Illegal expr used in uminus"); /*thelei mallon prwta na tsekarei ti eidous type einai*/
                                                $$ = newexpr(arithexpr_e);
                                                $$->sym = istempexpr($2)?$2->sym:newtemp();
                                                emit(uminus, $2, NULL, $$, 0,yylineno);
                                        }
            | NOT expr                  {
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol));
                                                $$ = newexpr(boolexpr_e);
                                                $$->sym = newtemp();
                                                emit(not, $2, NULL, $$, 0, yylineno); 
                                                // meriki apotimisi
                                                // emit(if_eq, $2, newexpr_constbool(1), NULL, nextquadlabel()+5, yylineno);
                                                // emit(jump, NULL, NULL, NULL,nextquadlabel()+2, yylineno);
                                                // emit(assign, newexpr_constbool(1), NULL, $$, 0, yylineno);
                                                // emit(jump, NULL, NULL, NULL,nextquadlabel()+3, yylineno);
                                                // emit(assign, newexpr_constbool(0), NULL, $$, 0, yylineno);
                                        }
            | PLUSPLUS lvalue           {
                                                check_arith($2,"Illegal expr used in ++lvalue");
                                                struct symbol *lvalue =(symbol*)malloc(sizeof(symbol));
                                                if($2->type == tableitem_e){    /* an einai stoixeio pinaka */
                                                    $$= emit_iftableitem($2);   /* tou allazw typo */
                                                    emit(add, $$, newexpr_constnum(1), $$, 0, yylineno);
                                                    emit(tablesetelem, $2, $2->index, $$, 0, yylineno);
                                                }else{
                                                    emit(add, $2, newexpr_constnum(1), $2, 0, yylineno);
                                                    $$ = newexpr(arithexpr_e); /* Xrisi neas krifis metavlitis, logw assignment */
                                                    $$->sym = newtemp();
                                                    emit(assign, $2, NULL, $$, 0, yylineno);
                                                }
                                        }
            | lvalue PLUSPLUS            {
                                                /*d10 slide33*/
                                                struct symbol *lvalue =(symbol*)malloc(sizeof(symbol));
                                                check_arith($1,"Illegal expr used in lvalue++");
                                                $$ = newexpr(var_e);
                                                $$->sym=newtemp();
                                                if($1->type == tableitem_e){
                                                    expr* val = emit_iftableitem($1);
                                                    emit(assign, val, NULL, $$, 0, yylineno);
                                                    emit(add, val, newexpr_constnum(1), val, 0, yylineno);
                                                    emit(tablesetelem, $1, $1->index, val, 0, yylineno);
                                                }else{
                                                    emit(assign, $1, NULL, $$, 0, yylineno);
                                                    emit(add, $1, newexpr_constnum(1), $1, 0, yylineno);
                                                }
                                        }
            | MINUSMINUS lvalue         {       check_arith($2,"Illegal expr used in --lvalue");
                                                struct symbol *lvalue =(symbol*)malloc(sizeof(symbol));
                                                if($2->type==tableitem_e){
                                                    $$= emit_iftableitem($2);
                                                    emit(sub, $$, newexpr_constnum(1), $$, 0, yylineno);
                                                    emit(tablesetelem, $2, $2->index, $$, 0, yylineno);
                                                }else{
                                                    emit(sub, $2, newexpr_constnum(1), $2, 0, yylineno);
                                                    $$ = newexpr(arithexpr_e);
                                                    $$->sym = newtemp();
                                                    emit(assign, $2, NULL, $$, 0, yylineno);
                                                }
                                        }
            | lvalue MINUSMINUS         {
                                                struct symbol *lvalue =(symbol*)malloc(sizeof(symbol));
                                                check_arith($1,"Illegal expr used in lvalue--");
                                                $$ = newexpr(var_e);
                                                $$->sym=newtemp();
                                                if($1->type==tableitem_e){
                                                    expr* val = emit_iftableitem($1);
                                                    emit(assign, val, NULL, $$, 0, yylineno);
                                                    emit(sub, val, newexpr_constnum(1), val, 0, yylineno);
                                                    emit(tablesetelem, $1, $1->index, val, 0, yylineno);
                                                }
                                                else{
                                                    emit(assign, $1, NULL, $$, 0, yylineno);
                                                    emit(sub, $1, newexpr_constnum(1), $1, 0, yylineno);
                                                }
                                        }
            | primary                   {
                                                $$ = $1;
                                        }
            ;
            
assignexpr: lvalue EQUAL expr           {       
                                                if($1->type == tableitem_e){
                                                    emit(tablesetelem, $1, $1->index, $3, 0, yylineno);
                                                    $$=emit_iftableitem($1);
                                                    $$->type=assignexpr_e;
                                                }else{
                                                    emit(assign, $3, NULL, $1, 0, yylineno);
                                                    $$ = newexpr(assignexpr_e);
                                                    $$->sym = newtemp();
                                                    emit(assign, $1, NULL, $$, 0, yylineno);
                                                }
                                        }
            ;

primary:    lvalue                      {
                                                $$ = emit_iftableitem($1);
                                        }
            | call                      {       /* Kalw olokliro ton termatiko kanona kai ektelw oti kanei */
                                                $$ = $1;
                                        }
            | objectdef                 {
                                                $$ = $1;
                                        }
            | LEFTPARENTHESES funcdef RIGHTPARENTHESES 
                                        {
                                                /*dialexi 10 slide 31*/
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol));
                                                $$ = newexpr(programfunc_e);
                                                $$->sym = $2;

                                        }
            | const                     {       $$=$1;
                                        }
            ;

lvalue:     ID                      
                                    {   struct symbol *symtab = (symbol*)malloc(sizeof(symbol)); /*new*/
                                        int i;
                                        for(i=scope; i>=0; i--){
                                            symtab = lookup($1,i); /* Anti gia counter, pairnei tin lookup kai tin elegxei */
                                            if(symtab != NULL){
                                                break;
                                            }
                                        }
                                        if(symtab == NULL){
                                            if(scope == 0){
                                                symtab=insert_symtab($1, GLOBAL, scope, yylineno);
                                                symtab->space = currscopespace(); 
                                                symtab->offset = currscopeoffset(); 
                                                inccurrscopeoffset();
                                            }else{
                                                symtab=insert_symtab($1, LOCAAL, scope, yylineno);
                                                symtab->space = currscopespace(); 
                                                symtab->offset = currscopeoffset(); 
                                                inccurrscopeoffset();
                                            }
                                        }
                                        $$=lvalue_expr(symtab);
                                    }
            | LOCAL ID             {    struct symbol *symtab = (symbol*)malloc(sizeof(symbol)); /*new*/
                                        void* kati;
                                        if(scope!=0 && lookup_libfunc($2, scope)){
                                            fprintf(stderr, "INPUT is lib func NOT VALID\n");
                                            exit(1);
                                        }
                                        kati = lookup($2, scope);
                                        if(kati == NULL){ // ==NULL -->Diladi den to exei vrei (alliws tha to eixe epistrepsei)
                                            if(scope !=0){
                                                symtab=insert_symtab($2, LOCAAL, scope, yylineno);
                                            }else{
                                                symtab=insert_symtab($2, GLOBAL, scope, yylineno);
                                                symtab->space = currscopespace();
                                                symtab->offset = currscopeoffset(); 
                                                inccurrscopeoffset(); 
                                            }
                                        }else if(lookup_libfunc($2, 0)==0){
                                            fprintf(stderr, "Local variable redefined in scope %d\n",scope);
                                            exit(1);
                                        }else{
                                            symtab=kati;
                                        }
                                        $$=lvalue_expr(symtab);
                                    }
            | SCOPERESOLUTION ID    {   struct symbol *symtab = (symbol*)malloc(sizeof(symbol)); 
                                        void* kati = lookup($2, 0);
                                        if(kati == NULL ){
                                            fprintf(stderr, "Didn't find in scope 0\n");
                                            exit(1);
                                        }else{
                                            symtab=kati;
                                            $$=lvalue_expr(symtab);
                                        }
                                    } 
            | member                {   $$=$1;
                                    }
            ;

member:     lvalue FULLSTOP ID                      {   
                                                        $$ = member_item($1, $3);
                                                   }
            | lvalue LEFTBRACKET expr RIGHTBRACKET  {
                                                        $1 = emit_iftableitem($1);  /* vazei to expression */
                                                        $$ = newexpr(tableitem_e);  /* vazei typo scopeoffset */
                                                        $$->sym = $1->sym;
                                                        $$->index = $3;
                                                    }
            | call FULLSTOP ID                      {   /*epeidi einai paromoios grammatikos kanonas
                                                        me to lvalue evala kai sto call to idio motivo*/
                                                        $$ = member_item($1, $3);
                                                    }
            | call LEFTBRACKET expr RIGHTBRACKET    {
                                                        $1= emit_iftableitem($1);
                                                        $$ = newexpr(tableitem_e);
                                                        $$->sym = $1->sym;
                                                        $$->index = $3;
                                                    }
            ;

call:       call LEFTPARENTHESES elist RIGHTPARENTHESES {
/* H ektypwsi twn orismatwn ginetai apo to telos->arxi p.x. f(a,b,c), ta quads ektypwnontai ws c meta b meta a.
Episis an exw nested func arg p.x. f(a, g(x,y,z), b,c) ta quads ektypwnontai ws z,y,x,(pou aforoun to elist)
(krataei (olo) to "g" se mia temp p.x.t_0) kai telos c, b, a. Ara--> c, b, t_0, a */
/* Anagkastika loipon i lista se auto to grammar rule einai local */    
                                                            $$ = make_call($1, $3); /* eksaitias twn parapanw to arg to onomazei reversed_list */
                                                        }
            | lvalue callsuffix                         {
                                                            $1 = emit_iftableitem($1);
                                                            if($2->method){
                                                                struct expr* t = $1;
                                                                $1 = emit_iftableitem(member_item(t,$2->name));
                                                                /* Pairnw mnimi, epeidi kanw eisagwgi ..Kanw neo komvo gia na mpei 1os */
                                                                struct list_t* newNode = (list_t*)malloc(sizeof(list_t)); 
                                                                
                                                                newNode->arg = t; 
                                                                newNode->previous = NULL;
                                                                newNode->next= $2->elist; /* vazw sto next ton twrino 1o komvo */
/* Eisagw ena neo stoixeio stin ARXI tis listas. Efoson to elist deixnei stin arxi tis listas, 
vazw to elist stin 2i thesi kai to neo stoixeio stin 1i thesi */
                                                                if($2->elist!=NULL){
                                                                    $2->elist->previous=newNode; /* vazw stin prev thesi tis idi yparxousa lista ton newNode */
                                                                }
                                                                $2->elist=newNode; /* 1os komvos ginetai o newNode */

                                                            }
                                                            $$ = make_call($1,$2->elist);
                                                        }
            | LEFTPARENTHESES funcdef RIGHTPARENTHESES LEFTPARENTHESES elist RIGHTPARENTHESES
                                                        {
                                                            struct expr* func = newexpr(programfunc_e);
                                                            func->sym=$2;
                                                            $$=make_call(func, $5); 
                                                        }
            ;

callsuffix: normcall        {   $$=$1;  }
            | methodcall    {   $$=$1;  }
            ;

normcall:   LEFTPARENTHESES elist RIGHTPARENTHESES      {   
                                                            struct call_l* newnormal = (call_l*)malloc(sizeof(call_l));
                                                            $$ = newnormal;
                                                            $$->elist = $2;
                                                            $$->method = 0;
                                                            $$->name = NULL;
                                                        }
            ;

methodcall: DFULLSTOP ID LEFTPARENTHESES elist RIGHTPARENTHESES     {   /* Desmeuw mnimi, wste na mporei na kanei tin ektypwsi  */
                                                                        struct call_l* newmethod = (call_l*)malloc(sizeof(call_l));
                                                                        $$ = newmethod; /* Pairnei to $$ tin mnimi */

                                                                        $$->elist = $4;
                                                                        $$->method = 1;
                                                                        $$->name = strdup($2); /* epistrefei pointer se auto pou kanei duplicate */
                                                                    }
            ;
/* Otan kalw mia synartisi */
elist:      expr 
                                                {
                                                    /* Dimiourgw lista gia ta stoixeia tou pinaka.
                                                       Antistoixia value me theseis pinaka */
                                                    struct list_t* mylist = (list_t*)malloc(sizeof(list_t));
                                                    mylist->previous = NULL;
                                                    mylist->next = NULL;
                                                    mylist->arg =$1;
                                                    $$ = mylist;

                                                }
            | elist COMMA expr                  {
                                                    struct list_t* mylist = (list_t*)malloc(sizeof(list_t));
                                                    struct list_t* node = (list_t*)malloc(sizeof(list_t)); 
                                                    /*Dimiourgw nea lista pou tha apothikeuei ola ta stoixeia. Autin tha diatreksw */
                                                    node = $$;

                                                    while(node->next!=NULL){
                                                        node=node->next;    /* Kanw next gia na paw ston last node,wste na kanw ekei tin eisagwgi */          
                                                    }
                                                    //node = last komvos tou node(list_t node);
                                                    //node->next=NULL
                                                    //mylist = newnode;
                                                    mylist->previous = node;
                                                    mylist->next = NULL;
                                                    mylist->arg = $3;
                                                    node->next = mylist;
                                                    /* To $$ to pira idi apo to expr(apo panw). Prosthesa to $3 se nea thesi tou node
                                                        Ara twra den xreiazetai na kanw $$ = $3 */
                                                }
            |                                   {
                                                    $$=NULL;
                                                }
            ;

objectdef:  LEFTBRACKET elist RIGHTBRACKET          {   
/* Edw ginetai dimiourgia pinaka p.x. x=[4,5,14,6], diladi
thesi 0 exei to 4, thesi 1->5 k.o.k.
tablegetelem 8 t_2 1, diavazetai ws: to 8 mpainei stin 1i thesi tou t_2*/
                                                        int i;
                                                        struct expr* t = newexpr(newtable_e);
                                                        t->sym = newtemp();
                                                        emit(tablecreate, t, NULL, NULL, 0, yylineno);
                                                        for(i=0; $2; $2 = $2->next){
                                                            emit(tablesetelem, t, newexpr_constnum(i++), $2->arg, 0, yylineno);
                                                        }
                                                        $$ = t;
                                                    }
            |LEFTBRACKET indexed RIGHTBRACKET       {   int i;
                                                        struct expr* t = newexpr(newtable_e);
                                                        t->sym = newtemp();
                                                        emit(tablecreate, t, NULL, NULL, 0, yylineno);
                                                        for(i=0; $2; $2 = $2->next){
                                                            emit(tablesetelem, t, $2->arg, $2->value, 0, yylineno);
                                                        }
                                                        $$ = t;}
            ;

indexed:    indexedelem                             {   $$ = $1;    }
            | indexed COMMA indexedelem             {
                                                    /* Afora tin periptwsi pou exw polla key-values se ena pinaka */
                                                    /* Dictionary creation: Kathe value exei to diko tou key --> x = [{"x":0},{"y":1}], 0=value, "x"=key */
                                                    struct list_t* mylist = (list_t*)malloc(sizeof(list_t));
                                                    struct list_t* node = (list_t*)malloc(sizeof(list_t));
                                                    node = $$;

                                                    while(node->next!=NULL){
                                                        node=node->next;                   
                                                    }
                                                    //  Skeptiko:
                                                    //  node = last;
                                                    //  node->next=NULL
                                                    //  mylist = newnode;
                                                    mylist->previous = node;
                                                    mylist->next = NULL;
                                                    mylist->arg = $3->arg;      /* key */
                                                    mylist->value = $3->value;  /* value */
                                                    node->next = mylist;
                                                    }
            ;

indexedelem:    LEFTBRACES expr COLON expr RIGHTBRACES 
                                                    {   /* Afora ton pinaka me ena key-value */
                                                        struct list_t* mylist = (list_t*)malloc(sizeof(list_t));
                                                        mylist->previous = NULL;
                                                        mylist->next = NULL;
                                                        mylist->arg =$2;
                                                        mylist->value= $4;
                                                        $$ = mylist;
                                                    } 
                ;


block:      LEFTBRACES {++scope;} statement RIGHTBRACES 
                                                    {   
/* Prokeimenou na metaferw ta break/continue pou yparxoun idi se ena block(
    diladi ta break/cont tou statement(ta opoia exoun ginei merged)) se kapoion allo kanona pou kalei to block.
    Diaforetika ta xanw, kai den kserw pou na kanw jump */                                                        
                                                        hide(scope--); 
                                                        $$ = make_stmt($$);     /* Midenizei ola ta break/cont pou yparxoun  */
                                                        $$->contList = $3->contList;
                                                        $$->breakList = $3->breakList;
                                                    }
         
            ;

funcname:   ID  {   
                    $$ = $1; 
                }
            |   {   char* onoma = malloc(10);
                
                    $$ = newFunName(onoma, metritis);
                    metritis++;
                } 
            ;

funcprefix: FUNCTION funcname   {   
                                    
                                    void* kati = lookup($2, scope);

                                    if(lookup_libfunc($2, scope)){
                                    fprintf(stderr, "INPUT is lib func NOT VALID\n");
                                        exit(1);
                                    }else if( kati != NULL ){
                                        fprintf(stderr, "Function redefined ERROR\n");
                                        exit(1);
                                    }else {
                                        $$ = insert_symtab($2, USERFUNC, scope, yylineno);
                                    }

                                    $$->iaddress = nextquadlabel(); /* iaddress idio typo me nextquadlabel()*/
                                    expr* f = (expr*)malloc(sizeof(expr));
                                    f->type = programfunc_e;        /* tou vazw ton typo gia func */
                                    f->sym = $$;                    /* sto symbol vazw ton grammar rule */
                                    emit(funcstart, f, NULL, NULL, 0, yylineno);
                                    /* kanw push to offset stin sto stack */
                                    push(&scopeoffsetstack, currscopeoffset()); /* "&": epeidi theloume tin dieuthinsi */
                                    enterscopespace();
                                    resetformalargsoffset();
                                }
            ;

funcargs:   LEFTPARENTHESES {scope++;} idlist RIGHTPARENTHESES 
                                {
                                    scope--;
                                    infunctioncounter++;
                                    enterscopespace();
                                    resetfunctionlocaloffset();
                                    /* kanw push ton loopcounter sto stack */
                                    push(&loopcounterstack, loopcounter);   /* "&": epeidi theloume tin dieuthinsi */
                                    loopcounter=0;
                                }
            ;

funcbody:   block               {
                                    $$ = currscopeoffset();
                                    existscopespace();
                                    infunctioncounter--;
                                    loopcounter = pop(&loopcounterstack);   /* "&": epeidi theloume tin dieuthinsi */
                                }

funcdef:   funcprefix funcargs funcbody
                                {
                                    existscopespace();
                                    $1->totalLocals = $3; /* totalLocals idio typo me funcbody */
                                    int offset = pop(&scopeoffsetstack);
                                    restorecurrscopeoffset(offset);
                                    $$ = $1;
                                    /* Dimiourgw tin stoiva gia na apothikeyei to scopeoffset */
                                    expr* ff = (expr*)malloc(sizeof(expr));
                                    ff->type = programfunc_e;
                                    ff->sym = $$;
                                    emit(funcend, ff, NULL, NULL, 0, yylineno);
                                }
            ;

const:      INT         {   $$ = newexpr_constnum((double)$1); 
                        }
            | DOUBLE    {   $$ = newexpr_constnum($1); 
                        }
            | STRING    {   $$ = newexpr_conststring($1);
                        }
            | NIL       {   /* Dimiourgia neou expr xwris symvola, me typo nil_e */
                            expr* nothing = (expr*)malloc(sizeof(expr));
                            nothing->type = nil_e;
                            $$ = nothing;
                        }
            | TRUE      {   $$ = newexpr_constbool((unsigned int)1);
                        }
            | FALSE     {   $$ = newexpr_constbool((unsigned int)0);
                        }      
            ;

/* formal arguments */
/* Otan dilwnw mia synartisi */

idlist:     ID                  {   void* kati = lookup($1, scope);
                                    
                                    if(lookup_libfunc($1, scope)){
                                        fprintf(stderr, "ERROR: arg is lib func NOT VALID\n");
                                        exit(1);
                                    }else if(kati != NULL){
                                        fprintf(stderr, "ERROR: formal arg redifined \n");
                                        exit(1);
                                    }else{
                                        insert_symtab($1, FORMAL, scope, yylineno);
                                    }
                                }
            | idlist COMMA ID   {   void* kati = lookup($3, scope);
                                    
                                    if(lookup_libfunc($3, scope)){
                                        fprintf(stderr, "arg is lib func NOT VALID\n");
                                        exit(1);
                                    }else if(kati != NULL){
                                        fprintf(stderr, "formal arg redifined ERROR\n");
                                        exit(1);
                                    }else{
                                        insert_symtab($3, FORMAL, scope, yylineno);
                                    } 
                                }
            | {}
            ;

ifprefix:   IF LEFTPARENTHESES expr RIGHTPARENTHESES{   
                                                        emit(if_eq, $3, newexpr_constbool(1), NULL, nextquadlabel()+2, yylineno);
                                                        $$ = nextquadlabel();    
                                                        emit(jump, NULL, NULL, NULL, 0, yylineno);
                                                    }
            ;
                                        
elseprefix: ELSE                                    {
                                                        $$ = nextquadlabel();    
                                                        emit(jump, NULL, NULL, NULL, 0, yylineno);
                                                    }
            ;

ifstmt:     ifprefix stmt                           {   
/* An exw ena stmt, arkei na krataw tis breakList/contList pou emfanizontai ekei */
                                                        inloopcounter++;
                                                        $$ = make_stmt($$);
                                                        $$->contList = $2->contList;
                                                        $$->breakList = $2->breakList;
                                                        patchlabel($1, nextquadlabel());
                                                        inloopcounter--;
                                                    }
            |ifprefix stmt elseprefix stmt          {
                                                        inloopcounter++;
                                                        $$ = make_stmt($$);
/* An exw polla stmt, prepei na apothikeuw ola ta breakList/contList(dld ta idi yparxwn, me ekeina kathe neou stmt) 
--> meta ta kanw merge ola metaksu tous, gia na ta parei o grammar rule */
                                                        struct stmt_t *prwtoStmt =(stmt_t*)malloc(sizeof(stmt_t));
                                                        struct stmt_t *deuteroStmt =(stmt_t*)malloc(sizeof(stmt_t));
                                                        prwtoStmt->contList = $2->contList;
                                                        prwtoStmt->breakList = $2->breakList;
                                                        
                                                        deuteroStmt->contList = $4->contList;
                                                        deuteroStmt->breakList = $4->breakList;
                                                        $$->breakList = mergelist(prwtoStmt->breakList, deuteroStmt->breakList);
                                                        $$->contList =  mergelist(prwtoStmt->contList,deuteroStmt->contList);

                                                        patchlabel($1, $3+1);
                                                        patchlabel($3, nextquadlabel());
                                                        inloopcounter--;
                                                    }
            ;

whilestart: WHILE                                   {  
                                                        inloopcounter++; 
                                                        $$ = nextquadlabel();  
                                                    }

whilecond : LEFTPARENTHESES expr RIGHTPARENTHESES   {
                                                        emit(if_eq, $2, newexpr_constbool(1), NULL, nextquadlabel()+2, yylineno);
                                                        $$ = nextquadlabel();
                                                        emit(jump, NULL, NULL, NULL, 0, yylineno);
                                                        ++loopcounter;
                                                    }

whilestmt:  whilestart whilecond stmt               {   
                                                        $$ = make_stmt($$);
                                                        emit(jump, NULL, NULL, NULL, $1, yylineno);
                                                        patchlabel($2, nextquadlabel());
                                                        patchlist($3->breakList, nextquadlabel());
                                                        patchlist($3->contList, $1);
                                                        --loopcounter;
                                                        inloopcounter--;
                                                    }
            ;

N :         {   
                $$ = nextquadlabel();  
                emit(jump, NULL, NULL, NULL, 0, yylineno);
            }

M:          {   
                $$ = nextquadlabel();   
            }

forprefix:  FOR LEFTPARENTHESES elist SEMICOLON M expr SEMICOLON    { 
                                                                        inloopcounter++;
                                                                        ++loopcounter;
                                                                        /* Desmeusi xwrou logw eisagwgis */
                                                                        struct for_t* newFor = (for_t*)malloc(sizeof(for_t));
                                                                        newFor->test = $5;
                                                                        newFor->enter = nextquadlabel();
                                                                        emit(if_eq, $6, newexpr_constbool(1), NULL, 0, yylineno);
                                                                        $$=newFor;  }

forstmt:     forprefix N elist RIGHTPARENTHESES N stmt N            {   
                                                                        $$ = make_stmt($$);
                                                                        patchlabel($1->enter, $5 +1);
                                                                        patchlabel($2, nextquadlabel());
                                                                        patchlabel($5, $1->test);
                                                                        patchlabel($7, $2 +1);
                                                                        patchlist($6->breakList, nextquadlabel());
                                                                        patchlist($6->contList, $2+1);
                                                                        --loopcounter;
                                                                        inloopcounter--;
                                                                    }
            ;

returnstmt: RETURN SEMICOLON        {
                                        if(infunctioncounter > 0){
                                            emit(ret, NULL, NULL, NULL, 0, yylineno);   
                                        }else{
                                            printf("You are not inside a function\n");
                                            exit(1);
                                        }
                                    }
            |RETURN expr SEMICOLON  {
                                        if(infunctioncounter > 0){
                                            emit(ret, $2, NULL, NULL, 0, yylineno);   
                                        }else{
                                            printf("You are not inside a function\n");
                                            exit(1);
                                        }
                                    }
            ;

%%

/* ----------C_Phase------------- */

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
        sym = insert_symtab(name, LOCAAL, scope, yylineno);
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
void push(stack **komvos, int i){

    struct stack *newlist = (stack*)malloc(sizeof(stack));
    newlist->next = *komvos;
    *komvos =newlist;

    newlist->data = i;

}

/*afairesi komvou gia th lista*/
int pop(stack **komvos){
    
    if(*komvos==NULL){
        exit(1);
    }else{
        struct stack *tmp = *komvos;
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

void yyerror(const char* yaccProvidedMessage){
    fprintf(stderr, "%s: at line %d, before token %s\n", yaccProvidedMessage, yylineno, yytext);
    fprintf(stderr, "INPUT NOT VALID\n");
    exit(1);
}

int main(int argc, char **argv) {
    
    if(argc > 1){
        if(!(yyin = fopen(argv[1], "r"))) {
            fprintf(stderr, "Cannot read file: %s\n", argv[1]);
            return 1;
        }
    }else{
        yyin = stdin;
    }

    init_lib_func();
    yyparse();

    /* print_s(); */
    printmyQuad();

    return 0;
}