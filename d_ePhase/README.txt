README

csd3612	Alexandros Vasilakis 
csd3841 Myrtw Sampani
csd4147 Pavlos Papachrysanthou

Mporeite na treksete ta arxeia me tis entoles:
		bison --defines --output=parser.c parser.y
		flex --outfile=scanner.c scannerB.l
		gcc -g -o calc scanner.c parser.c symtable.c quadfunc.c instructions.c
		gcc -g -o avm avm.c dispatcher.c
		./calc test.txt
		./avm

(Anti gia test.txt, mporei na mpei opoiodipote test, gia paradigma ta test pou eixan dothei stin phaseC)


1) Sto proto stadio (calc) to programa diavazei to input arxeio kai dimiourgei ta Quads apo tis entoles pou iparxoun.

2) Ystera kaleitai h generate_code, opou metatrepei ta Quads se Intrusctions.

3) Stin sunexeia kaleitai i binaryFile_Creation, opou grafei se ena binary arxeio ta Instructions pou dimiourgithikan.

4) Sto epomeno stadio (avm) kaleitai i read_binaryFile, opou diavazi to binary arxio apo to proigoumeno bima

5) Me tin execute_cycle analoga tin eisagwgi kanei to katallilo execute


To mono pou den exoume ulopoihsei logw xronou einai ta tables.