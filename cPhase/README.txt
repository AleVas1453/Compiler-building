README

csd3612	Alexandros Vasilakis 
csd3841 Myrtw Sampani
csd4147 Pavlos Papachrysanthou

Ginetai compile kanonika.
Mporeite na treksete ta arxeia me tis entoles:

		bison --defines --output=parser.c parser.y
		flex --outfile=scanner.c scannerB.l
		gcc -o calc scanner.c parser.c symtable.c
		./calc test.txt

(Anti gia test.txt, mporei na mpei opoiodipote test.
	P.x. ta test pou eixan dothei stin phaseB
	./calc phase2_tests/Working/ "testname"
)


Ston fakelo yparxoun ta test ths PhaseB, ta opoia kai treksame gia na testaroume
ton kwdika mas

H teleutaia (extra) entoli stin ektypwsi twn quads dimiourgeitai gia na kratisei
(apothikeusei) to apotelesma. An den to kratisw, tote tha perniountai lathos dedomena.
(diladi "Vlepei" me auto ton tropo to simeio pou prepei na mpei(gia na parei ta dedomena pou apothikeutikan))

Se diafora simeia(afou vlepame oti emfanizotan bus error), katalavame oti xreiazotan malloc, prokeimenou na desmeuei mnimi(wste na min eisvalei se kommatia pou den tou itan epitrepta)

Diaforetika arkei na ektelesete tin entoli make, pou periexei tis 4 entoles pou 
uparxoun parapanw.

Exei ylopoiithei i Oliki apotimisi, enw
Den exei ylopoiithei i meriki apotimisi, ara kai ta trueList kai falseList.