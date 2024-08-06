%{
// Definitions of Macros/Functions/Variables 
#ifndef QUADFUNC_H
#define QUADFUNC_H
#include "quadfunc.h"
#endif
#include "instructions.h"

int scope = 0;
int metritis=0;
int loopcounter = 0;
int infunctioncounter = 0;

void yyerror(const char* yaccProvidedMessage);
int yylex(void);

extern int yylineno;
extern char* yytext;
extern FILE* yyin;

/*---------- C Phase -------- */
stackkk* scopeoffsetstack = NULL; /* stack pou afora to offset */
stackkk* loopcounterstack = NULL; /* stack pou afora ton loopcounter, gia na elegxw an eimai se block kapoiou loop */

%}

 /* Dilwseis YACC */
 /* Symvola grammatikis */
%start program
 /* Anamenoume X conflicts apo tin grammatiki */
%expect 1 /* Edw 1, logw ifelsestm */

/* Den to pairnei opws to dinei sto front */
%define parse.error verbose // Parexei leptomeri eksigisi tou error 
/*%error-verbose*/

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
    diladi ta break/cont you statement(ta opoia exoun ginei merged)) se kapoion allo kanona pou kalei to block.
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
                                        //insert_symtab($1, FORMAL, scope, yylineno);


                                        symbol* symtab=insert_symtab($1, FORMAL, scope, yylineno);
                                        symtab->space = currscopespace(); 
                                        symtab->offset = currscopeoffset(); 
                                        inccurrscopeoffset();
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
                                        //insert_symtab($3, FORMAL, scope, yylineno);
                                        symbol* symtab=insert_symtab($3, FORMAL, scope, yylineno);
                                        symtab->space = currscopespace(); 
                                        symtab->offset = currscopeoffset(); 
                                        inccurrscopeoffset();
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
                                                        $$ = make_stmt($$);
                                                        $$->contList = $2->contList;
                                                        $$->breakList = $2->breakList;
                                                        patchlabel($1, nextquadlabel());
                                                    }
            |ifprefix stmt elseprefix stmt          {
                                                        $$ = make_stmt($$);
/* An exw polla stmt, prepei na apothikeuw ola ta breakList/contList(ta idi yparxwn me ekeina kathe neou stmt) 
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
                                                    }
            ;

whilestart: WHILE                                   {  
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

    /* Quads */
    init_lib_func();
    yyparse();

   /* Instructions */
    //print_s();
    generate_code();

    /* print_s(); */
    printmyQuad();
    printf("\n\n-----------------------------------------------------------------");
    printf("\n-------------------------INSTRUCTIONS------------------------\n\n");
    printmyInstructions ();

    binaryFile_Creation();

    return 0;
}