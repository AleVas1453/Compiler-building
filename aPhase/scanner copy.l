/* Tmina Orismwn */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YY_DECL int alpha_yylex(void* yyval)
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

struct token_collection{
    int line;
    int token_num;
    char *token_name;
    char *token_type;
    char *token_content;
    struct token_collection *next; 
};

/* Dilwsi Prototypes twn Synartisewn*/
void token_print(int token_name);
struct token *add_token(int line, char *token_name, char *token_type, char *token_content);
void errorFound(const char* error);

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


LETTER	        [a-zA-Z]
DIGIT		    [0-9]
IDENTIFIER      [a-zA-Z][a-zA-Z_0-9]* 
INTEGER	        [0-9]+ 
REAL		    [0-9]+\.[0-9]+
DELIMITER 		[\r\n \t\v]
WHITESPACE		{DELIMITER}+
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
KEYWORD	        if|else|for|while|break|continue|return|true|false|not|and|or|function|nil
LINECOMMENT	    "//".*
EOF			 	{return 0;}

/* Symvolo poy diaxwrizei ta epipeda */
%%

"IF" 		{  token_print( tokenIF);       		return tokenIF;         	}
"ELSE"		{  token_print(tokenELSE);      		return tokenELSE;       	}
"THEN"	    {  token_print(tokenTHEN);      		return tokenTHEN;       	}
"WHILE"	    {  token_print(tokenWHILE);     		return tokenWHILE;      	}
"RETURN"	{  token_print(tokenRETURN);    		return tokenRETURN;     	}
"BREAK"	    {  token_print(tokenBREAK);     		return tokenBREAK;      	}
"CONTINUE"	{  token_print(tokenCONTINUE);  		return tokenCONTINUE;   	}
"FALSE"	    {  token_print(tokenFALSE);     		return tokenFALSE;     	}
"NOT"		{  token_print(tokenNOT);     			return tokenNOT;        	}
"AND"		{  token_print(tokenAND);       		return tokenAND;        	}
"OR"		{  token_print(tokenOR);        		return tokenOR;         	}
"FUNCTION"	{  token_print(tokenFUNCTION);    		return tokenFUNCTION;     	}
"NIL"		{  token_print(tokenNIL);       		return tokenNIL;        	}
"{"			{  token_print(tokenLEFTBRACES);       	return tokenLEFTBRACES;     }
"}"			{  token_print(tokenRIGHTBRACES);       return tokenRIGHTBRACES;    }
"("			{  token_print(tokenLEFTPARENTHESES);   return tokenLEFTPARENTHESES; }
")"			{  token_print(tokenRIGHTPARENTHESES);  return tokenRIGHTPARENTHESES; }
"["			{  token_print(tokenLEFTBRACKET);       return tokenLEFTBRACKET;    }
"]"			{  token_print(tokenRIGHTBRACKET);      return tokenRIGHTBRACKET;   }
":"			{  token_print(tokenCOLON);       		return tokenCOLON;        	}
";"			{  token_print(tokenSEMICOLON);       	return tokenSEMICOLON;      }
","			{  token_print(tokenCOMMA);       		return tokenCOMMA;        	}
"."			{  token_print(tokenFULLSTOP);       	return tokenFULLSTOP;       }
"+"			{  token_print(tokenPLUS);       		return tokenPLUS;       	}
"-"			{  token_print(tokenMINUS);       		return tokenMINUS;    	    }
"*"			{  token_print(tokenMULTIPLY);       	return tokenMULTIPLY;       }
"/"			{  token_print(tokenDIVISION);       	return tokenDIVISION;       }
"%"			{  token_print(tokenPERCENT);       	return tokenPERCENT;        }
"++"		{  token_print(tokenPLUSPLUS);       	return tokenPLUSPLUS;       }
"--"		{  token_print(tokenMINUSMINUS);       	return tokenMINUSMINUS;     }
"="			{  token_print(tokenEQUAL);      		return tokenEQUAL;        	}
"<"			{  token_print(tokenLESS);       		return tokenLESS;        	}
">"			{  token_print(tokenGREATER);       	return tokenGREATER;		}
"<="		{  token_print(tokenLESSEQUAL);       	return tokenLESSEQUAL;		}
">="		{  token_print(tokenGREATEREQUAL);      return tokenGREATEREQUAL;	}
"=="		{  token_print(tokenEQUALEQUAL);       	return tokenEQUALEQUAL;     }
"!="		{  token_print(tokenNOTEQUAL);       	return tokenNOTEQUAL;       }
[0-9]		{  token_print(tokenDIGIT);         	return tokenDIGIT;      	}
{ }
{LETTER}      {token_print(tokenLETTER);        	return tokenLETTER;     	}
{IDENTIFIER}  {token_print(tokenIDENTIFIER);    	return tokenIDENTIFIER; 	}
{INTEGER}     {token_print(tokenINTEGER);       	return tokenINTEGER;    	}
{REAL}        {token_print(tokenREAL);          	return tokenREAL;       	}
{DELIMITER}   {token_print(tokenDELIMITER);     	return tokenDELIMITER;  	}
{WHITESPACE}  {token_print(tokenWHITESPACE);    	return tokenWHITESPACE; 	}
{LINECOMMENT} {token_print(tokenLINECOMMENT);   	return tokenLINECOMMENT;	}



<STRING>\"	{BEGIN(STRING);} 									/* Elegxei oti ksekinaei to string */

<STRING>\\. | [^"\\]{printf("Found word:%s \n", yytext);}		/* Diavazw opoiadipote leksi ksekinaei me katheto "\" kai meta exei opoiadipote gramma(anagnwrizei opoiodipote xaraktira typou \. \” \t \v \i \f 'h oti de thelw na einai)(yytext einai to teleytaio poy diavastike) */
<STRING>[\n | \r\n] {errorFound("New line found without \n ");} /* 1i periptwsi pou petaei error */
<STRING> EOF {printf("End of string without closing it.");}








int main(int argc, char** argv){

    token_collection *head = NULL;	
    head = (token_collection *)malloc(size of(token_collection));
    head -> next = NULL;

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

	alpha_yylex(head);
	token_print(head);
 
	return 0;
}



