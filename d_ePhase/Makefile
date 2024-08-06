compile:
		bison --defines --output=parser.c parser.y
		flex --outfile=scanner.c scannerB.l
		gcc -g -o calc scanner.c parser.c symtable.c quadfunc.c instructions.c
		gcc -g -o avm avm.c dispatcher.c
		./calc test.txt
		./avm
		
clean:
		rm -rf parser.c
		rm -rf scanner.c
		rm -rf parser.h	
		rm calc
		rm avm
		rm binary.abc