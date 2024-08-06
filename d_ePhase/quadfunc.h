#include "symtable.h"

#define EXPAND_SIZE 1024
#define CURR_SIZE (total*sizeof(quad))
#define NEW_SIZE (EXPAND_SIZE * sizeof(quad)+CURR_SIZE)

extern int yylineno;

/*opcode types */
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

/*enum types twn expr */
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

/*periexei ola ta pedia enos quad*/
typedef struct quad{
    iopcode op;
    expr* result;
    expr* arg1;
    expr* arg2;
    unsigned label;
    unsigned line;
    unsigned taddress;
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

/*stack pou afora thn trith phase */
typedef struct stackkk{
    int data;
    struct stackkk *next;
}stackkk;

/* Prototypes synartisewn */
void expand(void);
void emit(iopcode op ,expr * arg1, expr * arg2, expr * result, int label, unsigned int line);
expr* lvalue_expr(symbol* sym);
expr* newexpr(expr_t t);
expr* newexpr_conststring(char* s);
expr* newexpr_constnum(double i);
expr* newexpr_constbool(unsigned int b);
expr* emit_iftableitem(expr* e);
expr* make_call(expr* lv, list_t* reversed_elist);
expr* member_item(expr* lv, char* name);
void comperror(char* format);
void check_arith(expr* e,  char* context);
unsigned nextquadlabel(void);
void patchlabel(unsigned quadNo, unsigned label);
char* newFunName(char *onoma, int d);
symbol* newtemp();
unsigned int istempname(char* s);
unsigned int istempexpr(expr* e);
void resettemp();
void resetformalargsoffset(void);
void resetfunctionlocaloffset(void);
scopespace_t currscopespace(void);
void restorecurrscopeoffset(unsigned n);
unsigned currscopeoffset (void);
void inccurrscopeoffset (void);
void enterscopespace (void);
void existscopespace (void);
stmt_t* make_stmt(stmt_t* s);
int newlist(int i);
int mergelist(int l1, int l2);
void patchlist(int list, int label);
void push(stackkk **komvos, int i);
int pop(stackkk **komvos);
void printmyOp(iopcode opcode);
void print_exprType(expr* e_type);
void* printmyQuad();