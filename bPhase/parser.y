%{
// Definitions of Macros/Functions/Variables 
#include <stdio.h>
#include "symtab.h"

int yyerror(const char* yaccProvidedMessage);
int yylex(void);
const char* getType(enum SymbolType type);
void print_syntax(const char *name, enum SymbolType type, unsigned int line, unsigned int scope);


extern int yylineno;
extern char* yytext;
extern FILE* yyin;

%}

 /* Dilwseis YACC */
 /* Symvola grammatikis */
%start program
 /* Anamenoume X conflicts apo tin grammatiki */
%expect 1 /* Edw 1, logw ifelsestm */

/* Den to pairnei opws to dinei sto front */
%define parse.error verbose // Parexei leptomeri eksigisi tou error
/* %error-verbose */

 /* Union: periexei tous vasikous typous poy yparxei se mia glwssa */
%union {
    char* stringValue;
    int intValue;
    double doubValue;
}
/* %token   <type>  onoma   arithmos(proeraitika)   "perigrafi"*/
%token <stringValue>            ID                  "id"
%token <intValue>               INT                 "int"
%token <doubValue>              DOUBLE              "double"
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
%token                          LOCALY


/* Dinw type kai sta mi termatika symvola */




%right      EQUAL
%left       OR
%left       AND
%nonassoc   EQUALEQUAL NOTEQUAL
%nonassoc   GREATER GREATEREQUAL LESS LESSEQUAL
%left       PLUS SUB
%left       MULTIPLY DIVISION PERCENT
%right      NOT PLUSPLUS MINUSMINUS UMINUS
%left       FULLSTOP COMMA DFULLSTOP
%left       LEFTBRACKET RIGHTBRACKET
%left       LEFTPARENTHESES RIGHTPARENTHESES

%%
program:    stmt 
            | stmt program
            ;

stmt:       expr SEMICOLON
            | ifstmt 
            | whilestmt 
            | forstmt
            | returnstmt
            | BREAK SEMICOLON
            | CONTINUE SEMICOLON
            | block
            | funcdef 
            ;


expr:       assignexpr
            | expr PLUS expr 
            | expr SUB expr
            | expr MULTIPLY expr
            | expr DIVISION expr
            | expr PERCENT expr
            | expr GREATER expr
            | expr GREATEREQUAL expr
            | expr LESS expr
            | expr LESSEQUAL expr
            | expr EQUALEQUAL expr
            | expr NOTEQUAL expr
            | expr AND expr
            | expr OR expr
            | term
            ;

term:       LEFTPARENTHESES expr RIGHTPARENTHESES 
            | SUB expr
            | NOT expr
            | PLUSPLUS lvalue
            | lvalue PLUSPLUS
            | MINUSMINUS lvalue
            | lvalue MINUSMINUS
            | primary
            ;
            
assignexpr: lvalue EQUAL expr 
            ;

primary:    lvalue
            | call
            | objectdef
            | LEFTPARENTHESES funcdef RIGHTPARENTHESES 
            | const
            ;

lvalue:     ID                      {insert_symtab($1, LOCAL, 0, scope, yylineno);
                                    print_syntax($1, LOCAL, yylineno, scope);}
            | LOCALY ID              {insert_symtab($2, LOCAL, 0, scope, yylineno);}
            | SCOPERESOLUTION ID    {insert_symtab($2, LOCAL, 0, scope, yylineno);} 
            | member
            ;
/*$$          $1      $2      $3*/
member:     lvalue FULLSTOP ID                      {insert_symtab($3, LOCAL, 0, scope, yylineno);}
            | lvalue LEFTBRACKET expr RIGHTBRACKET  
            | call FULLSTOP ID                      {insert_symtab($3, LOCAL, 0, scope, yylineno);}
            | call LEFTBRACKET expr RIGHTBRACKET
            ;

call:       call LEFTPARENTHESES elist RIGHTPARENTHESES
            | lvalue callsuffix
            | LEFTPARENTHESES funcdef RIGHTPARENTHESES LEFTPARENTHESES elist RIGHTPARENTHESES
            ;

callsuffix: normcall
            | methodcall 
            ;

normcall:   LEFTPARENTHESES elist {scope++;} RIGHTPARENTHESES   {scope--;} 
            ;

methodcall: DFULLSTOP ID LEFTPARENTHESES elist RIGHTPARENTHESES     {insert_symtab($1, LOCAL, 0, scope, yylineno);}
            ;

elist:      expr 
            | elist COMMA expr
            ;

objectdef:  LEFTBRACKET elist RIGHTBRACKET   
            |LEFTBRACKET indexed RIGHTBRACKET
            ;

indexed:    indexedelem
            | indexed COMMA indexedelem  
            ;

indexedelem:   LEFTBRACES expr COLON expr RIGHTBRACES 
                ;

block:      LEFTBRACES stmt RIGHTBRACES 
            ;

funcdef:    FUNCTION LEFTBRACKET ID RIGHTBRACKET LEFTPARENTHESES {scope++;} idlist RIGHTPARENTHESES block {scope--;}
            ;

const:      INT 
            | DOUBLE 
            | NIL 
            | TRUE | FALSE 
            ;

idlist:     ID
            | idlist COMMA ID
            ;

ifstmt:     IF LEFTPARENTHESES expr RIGHTPARENTHESES stmt
            |IF LEFTPARENTHESES expr RIGHTPARENTHESES stmt ELSE stmt 
            ;

whilestmt:  WHILE LEFTPARENTHESES expr RIGHTPARENTHESES stmt 
            ;

forstmt:    FOR LEFTPARENTHESES elist SEMICOLON expr SEMICOLON elist RIGHTPARENTHESES stmt 
            ;

returnstmt: RETURN SEMICOLON
            |RETURN expr SEMICOLON {scope--;}
            ;

%%


int yyerror(const char* yaccProvidedMessage){
    fprintf(stderr, "%s: at line %d, before token %s\n", yaccProvidedMessage, yylineno, yytext);
    fprintf(stderr, "INPUT NOT VALID\n");
    return 1;           /* Oxi aparaitito to return (To function mporei na einai void) */
}

const char* getType(enum SymbolType type) 
{
   switch (type) 
   {
      case GLOBAL: return "GLOBAL";
      case LOCAL: return "LOCAL";
      case FORMAL: return "FORMAL";
      case USERFUNC: return "USERFUNC";
      case LIBFUNC: return "LIBFUNC";
   }
}

void print_syntax(const char *name, enum SymbolType type, unsigned int line, unsigned int scope){
    printf(" \"%s\" \t [%s] (line %d) (scope %d) \n", name, getType(type), line, scope);

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

    yyparse();
    return 0;
}
