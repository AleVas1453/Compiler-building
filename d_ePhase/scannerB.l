/* Tmina Orismwn */
%{

	/*Na valw stin panw meria ena on/off mode gia na ektypwnei h oxi ta print tou ".l" */
	/*Kanei tin antistoixia mesa stin token_print function*/
#define PRINT 0 
#include "parser.h"	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int serial_num=1;

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


IF		        if
ELSE			else
THEN			then
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
LOCAL			local
NIL				nil
ID			    [a-zA-Z][a-zA-Z_0-9]* 
INT		        [0-9]+ 
DOUBLE		    [0-9]+\.[0-9]+
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
FULLSTOP	    "\."
DFULLSTOP	    ".."
PLUS	        (\+)
SUB		        (\-)
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
SCOPERESOLUTION	(\::)
LINECOMMENT	    "//".*
STRING			"\""


/* Symvolo poy diaxwrizei ta epipeda */
%%

{IF}					{ return IF;				}
{ELSE}					{ return ELSE;				}
{THEN}					{ return THEN;				}
{FOR}					{ return FOR;				}
{WHILE}					{ return WHILE;				}
{BREAK}					{ return BREAK;				}
{CONTINUE}				{ return CONTINUE;			}
{RETURN}				{ return RETURN;			}
{TRUE}					{ return TRUE;				}
{FALSE}					{ return FALSE;				}
{NOT}					{ return NOT;				}
{AND}					{ return AND;				}
{OR}					{ return OR;				}
{FUNCTION}				{ return FUNCTION;			}
{LOCAL}					{ return LOCAL;				}
{NIL}					{ return NIL;				}
{LEFTBRACES}			{ return LEFTBRACES;		}
{RIGHTBRACES}			{ return RIGHTBRACES;		}
{LEFTPARENTHESES}		{ return LEFTPARENTHESES;	}
{RIGHTPARENTHESES}		{ return RIGHTPARENTHESES;	}
{LEFTBRACKET}			{ return LEFTBRACKET;		}
{RIGHTBRACKET}			{ return RIGHTBRACKET;		}
{COLON}					{ return COLON;				}
{SEMICOLON}				{ return SEMICOLON;			}
{COMMA}					{ return COMMA;				}
{FULLSTOP}				{ return FULLSTOP;			}
{DFULLSTOP}				{ return DFULLSTOP;			}
{PLUS}					{ return PLUS;				}
{SUB}					{ return SUB;				}
{MULTIPLY}				{ return MULTIPLY;			}
{DIVISION}				{ return DIVISION;			}
{PERCENT}				{ return PERCENT;			}
{PLUSPLUS}				{ return PLUSPLUS;			}	
{MINUSMINUS}			{ return MINUSMINUS;		}
{EQUAL}					{ return EQUAL;				}
{GREATER}				{ return GREATER;			}
{LESS}					{ return LESS;				}
{LESSEQUAL}				{ return LESSEQUAL;			}
{GREATEREQUAL}			{ return GREATEREQUAL;		}
{EQUALEQUAL}			{ return EQUALEQUAL;		}
{NOTEQUAL}				{ return NOTEQUAL;			}
{SCOPERESOLUTION}		{ return SCOPERESOLUTION;	}
{LINECOMMENT}			{ /*return LINECOMMENT;	*/	}
{NEWLINE}				{ /*return NEWLINE;	*/		}


{ID}		  			{ yylval.stringValue = strdup(yytext); return ID;	}
{INT}					{ yylval.intValue = atoi(yytext); return INT;		}
{DOUBLE}				{ yylval.doubValue = atof(yytext); return DOUBLE;	}

"\"" {
	char box[10000];
	int c;
	int i=0;
	while((c=input()) != 0){
		if(c == '\\'){
			c = input();
			if(c == 'n'){
				box[i++] = '\n';
			}else if(c == 't'){
				box[i++] = '\t';
			}else if(c == 'r'){
				box[i++] = '\r';
			}else if(c == 'v'){
				box[i++] = '\v';
			}else if(c == '"'){
				box[i++] = c;
			}

			/* CAN"T RECOGNIZE THEM
			else if(c == '''){
				box[i++] = c;
			}else if(c == '\'){
				box[i++] = c;
			}
			*/

		}else if(c == '"'){
			break;
		}else{
			box[i++] = c;
		}			
	}
	
	if(c != '"'){
		fprintf(stderr, "\033[0;31mERROR: \033[0mString isn't completed\n");
	}

	/* xreiazetai elegxo gia to an "c = 0" ??? */

	box[i++] = '\0';

	yytext = strdup(box);

	yylval.stringValue = strdup(yytext); 
	
	return STRING;
}

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
		fprintf(stderr, "\033[0;31mERROR: \033[0mCan't catch multiline comment\n");
	}
}

[ \t\n]+				{}

{SIMPLESPACE}			{token_print(serial_num++, yytext, "SIMPLESPACE");					}
{MULTISPACE}			{token_print(serial_num++, yytext, "MULTISPACE");					}
.						{fprintf(stderr, "\033[0;31mERROR: \033[0mCannot match character '%s' with any rule\n", yytext);			}

%%

void token_print(int token_num, char *token_content, char *token_type){

	/* if (PRINT == 0) return; */
	printf("%d : # %d\t\"%-10s\" %-15s\n" , yylineno, token_num, token_content, token_type);
}