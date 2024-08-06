csd3612 Alexadros Vasilakis
csd3841 Myrtw Sampani
csd4147 Pavlos Papaxrysanthou


H askhsh den einai apolyta oloklirwmeni.
Yparxei ena error(unrecognized rule), to opoio mallon afora ton tropo
pou eisagoume ena String.

Gia na treksei i askisi, arkei na kanate tis entoles poy yparxoun sto Makefile
	flex --outfile=scanner.c scanner.l
	gcc -o scanner scanner.c

Me to na min exei ginei debug to programma me tin entoli flex, den exei paraxthei 
antistoixo ".c" arxeio.


%{
C Code
%}

Flex Code 

Flex macros										/* front1 sel.20 */
%%  <--Diaxwristis Epipedwn

RegEx		{ Ektelesimo Kommati(se C language)}

"IF"		{ printf("Found IF\n");		return 1;}
[a-zA-z]*	{ printf("Found word\n");	return 3;}