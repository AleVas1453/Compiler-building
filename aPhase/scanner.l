/* Tmina Orismwn */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int serial_num=1;
#define YY_DECL int alpha_yylex(void* yylval)
/* Ksexwrista macros gia kathe diaforetiki katigoria token */
#define tokenEOF 	            0
#define tokenIF	                1
#define tokenELSE	            2
#define tokenTHEN	            3
#define tokenWHILE	            4
#define tokenRETURN	            5
#define tokenFALSE	            6
#define tokenBREAK	            7
#define tokenCONTINUE	        8
#define tokenNOT	            9
#define tokenAND	            10
#define tokenOR	                11
#define tokenFUNCTION           12
#define tokenNIL	            13
#define tokenDIGIT              14
#define tokenLETTER             15
#define tokenIDENTIFIER         16
#define tokenINTEGER            17
#define tokenREAL               18
#define tokenDELIMITER          19
#define tokenWHITESPACE         20
#define tokenDIVISION           21
#define tokenNOTEQUAL           22
#define tokenLINECOMMENT        23
#define tokenLEFTBRACKET	    24 
#define	tokenRIGHTBRACKET	    25 
#define	tokenLEFTPARENTHESES	26 
#define tokenRIGHTPARENTHESES	27 
#define	tokenLEFTBRACES	        28 
#define tokenRIGHTBRACES	    29 
#define tokenCOLON	            30
#define tokenSEMICOLON	        31
#define tokenCOMMA	            32
#define tokenFULLSTOP	        33
#define tokenPLUS               34
#define tokenMINUS              35
#define tokenMULTIPLY           36
#define tokenPERCENT            37
#define tokenPLUSPLUS           38
#define tokenMINUSMINUS         39
#define tokenEQUAL              40
#define tokenGREATER            41
#define tokenLESS               42
#define tokenLESSEQUAL          43
#define tokenGREATEREQUAL       44
#define tokenEQUALEQUAL         45

struct alpha_token_t{
    int line;
    int token_num;
    char *token_name;
    char *token_type;
    char *token_content;
    struct alpha_token_t *next; 
};

/* Dilwsi Prototypes twn Synartisewn*/
void token_print(int token_name, char *token_type, char *token_content);

%}

/* Tmima Kanonwn */

/* Gia anagnwrisi MONO enos arxeiou kathe fora einai to noyywrap */
%option noyywrap
/* Opws ki an grapseis mia leksi(mikroi-megaloi xaraktires), tin diavazei to idio(Den einai case-sensitive) */
%option case-insensitive
/* enswmatwmeni metavliti apo to flex, otan synanta to ‘\n’. H metavliti auksanetai kata 1 */
%option yylineno

/* Orismos ypolektikou analyti (typos onoma: %x STRING) */
%x STRING
%x COMMENT 

IF		        if
ELSE			else
FOR				for
WHILE			while
BREAK			break
CONTINUE		continue
RETURN			return
TRUE			true
FALSE			false
NOT				not
AND				and
OR				or
FUNCTION		function
NIL				nil
IDENTIFIER      [a-zA-Z][a-zA-Z_0-9]* 
INTEGER	        [0-9]+ 
REAL		    [0-9]+\.[0-9]+
SIMPLESPACE		[\r \t\v]
NEWLINE			[\n]
MULTISPACE		{SIMPLESPACE}+
LEFTBRACES      (\{)
RIGHTBRACES     (\})
LEFTPARENTHESES (\()
RIGHTPARENTHESES (\))
LEFTBRACKET     (\[)
RIGHTBRACKET    (\])
COLON	        (\:)
SEMICOLON	    (\;)
COMMA	        (\,)
FULLSTOP	    (\.)
PLUS	        (\+)
MINUS	        (\-)
MULTIPLY	    (\*)
DIVISION	    (\/)
PERCENT		    (\%)
PLUSPLUS	    (\++)
MINUSMINUS	    (\--)
EQUAL		    (\=)
GREATER		    (\>)
LESS		    (\<)
LESSEQUAL	    (\<=)
GREATEREQUAL	(\>=)
EQUALEQUAL		(\==)
NOTEQUAL		(\!=)
LINECOMMENT	    "//".*
STRING			\"[^\n"]*\"
EOF			 	{return 0;}

/* Symvolo poy diaxwrizei ta epipeda */
%%

{IF}					{token_print(serial_num++, yytext, "KEYWORD");		}
{ELSE}					{token_print(serial_num++, yytext, "KEYWORD");		}
{FOR}					{token_print(serial_num++, yytext, "KEYWORD");		}
{WHILE}					{token_print(serial_num++, yytext, "KEYWORD");		}
{BREAK}					{token_print(serial_num++, yytext, "KEYWORD");		}
{CONTINUE}				{token_print(serial_num++, yytext, "KEYWORD");		}
{RETURN}				{token_print(serial_num++, yytext, "KEYWORD");		}
{TRUE}					{token_print(serial_num++, yytext, "KEYWORD");		}
{FALSE}					{token_print(serial_num++, yytext, "KEYWORD");		}
{NOT}					{token_print(serial_num++, yytext, "KEYWORD");		}
{AND}					{token_print(serial_num++, yytext, "KEYWORD");		}
{OR}					{token_print(serial_num++, yytext, "KEYWORD");		}
{FUNCTION}				{token_print(serial_num++, yytext, "KEYWORD");		}
{NIL}					{token_print(serial_num++, yytext, "KEYWORD");		}
{IDENTIFIER}  			{token_print(serial_num++, yytext, "IDENTIFIER");	}
{INTEGER}				{token_print(serial_num++, yytext, "INTEGER");		}
{REAL}					{token_print(serial_num++, yytext, "REAL");			}
{SIMPLESPACE}			{token_print(serial_num++, yytext, "SIMPLESPACE");	}
{NEWLINE}				{token_print(serial_num++, yytext, "NEWLINE");		}
{MULTISPACE}			{token_print(serial_num++, yytext, "MULTISPACE");	}
{LEFTBRACES}			{token_print(serial_num++, yytext, "PUNCTUATION");	}
{RIGHTBRACES}			{token_print(serial_num++, yytext, "PUNCTUATION");	}
{LEFTPARENTHESES}		{token_print(serial_num++, yytext, "PUNCTUATION");	}
{RIGHTPARENTHESES}		{token_print(serial_num++, yytext, "PUNCTUATION");	}
{LEFTBRACKET}			{token_print(serial_num++, yytext, "PUNCTUATION");	}
{RIGHTBRACKET}			{token_print(serial_num++, yytext, "PUNCTUATION");	}
{COLON}					{token_print(serial_num++, yytext, "PUNCTUATION");	}
{SEMICOLON}				{token_print(serial_num++, yytext, "PUNCTUATION");	}
{COMMA}					{token_print(serial_num++, yytext, "PUNCTUATION");	}
{FULLSTOP}				{token_print(serial_num++, yytext, "PUNCTUATION");	}
{PLUS}					{token_print(serial_num++, yytext, "OPERATOR");		}
{MINUS}					{token_print(serial_num++, yytext, "OPERATOR");		}
{MULTIPLY}				{token_print(serial_num++, yytext, "OPERATOR");		}
{DIVISION}				{token_print(serial_num++, yytext, "OPERATOR");		}
{PERCENT}				{token_print(serial_num++, yytext, "OPERATOR");		}
{PLUSPLUS}				{token_print(serial_num++, yytext, "OPERATOR");		}
{MINUSMINUS}			{token_print(serial_num++, yytext, "OPERATOR");		}
{EQUAL}					{token_print(serial_num++, yytext, "OPERATOR");		}
{GREATER}				{token_print(serial_num++, yytext, "OPERATOR");		}
{LESS}					{token_print(serial_num++, yytext, "OPERATOR");		}
{LESSEQUAL}				{token_print(serial_num++, yytext, "OPERATOR");		}
{GREATEREQUAL}			{token_print(serial_num++, yytext, "OPERATOR");		}
{EQUALEQUAL}			{token_print(serial_num++, yytext, "OPERATOR");		}
{NOTEQUAL}				{token_print(serial_num++, yytext, "OPERATOR");		}
{LINECOMMENT}			{token_print(serial_num++, yytext, "LINE_COMMENT");	}

<STRING>\"	{BEGIN(STRING);} 									/* Elegxei oti ksekinaei to string */
<STRING>\\. | [^”\\]{printf("Found word:%s \n", yytext);}		/* Diavazw opoiadipote leksi ksekinaei me katheto "\" kai meta exei opoiadipote gramma(anagnwrizei opoiodipote xaraktira typou \. \” \t \v \i \f 'h oti de thelw na einai)(yytext einai to teleytaio poy diavastike) */
<STRING>[\n | \r\n] {printf("New line found without \\ ");} /* 1i periptwsi pou petaei error */



"/*" {    
	int c, comm_count = 1;
	while ((c=input()) != 0){
		if(c == '/'){
			if((c=input())== '*'){
				comm_count++;
			}else{
				unput(c);
			}
		}else if(c == '*'){
			if((c = input()) == '/' ){
				comm_count--;
				if(comm_count>0){
					token_print(serial_num++, yytext, "NESTED_COMMENT");
				}else{
					token_print(serial_num++, yytext, "MULTI_COMMENT");
					break;
				}
			}else{
				unput(c);
			}
		}
	}

	if(c != '/'){
		fprintf(stderr, "ERROR: Can't catch multiline comment\n", yytext);
	}
}

.						{fprintf(stderr, "Cannot match character '%s' with any rule\n", yytext);			}
<<EOF>>					{ return 0;															}

%%

int main(int argc, char** argv){

    /* Diavazei to arxeio pros metafrasi */
	if(argc > 1){
		if(! (yyin = fopen(argv[1], "r"))) {
			fprintf(stderr, "CANNOT READ FILE: %s\n", argv[1]);
			return -1;
		}
	}
	else{					
		yyin = stdin;
	}

	alpha_yylex(NULL);
 
	return 0;
}

void token_print(int token_num, char *token_content, char *token_type){
	printf("%d : # %d\t\"%-10s\" %-15s\n" , yylineno, token_num, token_content, token_type);
}