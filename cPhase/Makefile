compile:
		bison --defines --output=parser.c parser.y
		flex --outfile=scanner.c scannerB.l
		gcc -o calc scanner.c parser.c symtable.c
		./calc test.txt
		
clean:
		rm -rf parser.c
		rm -rf scanner.c
		rm -rf parser.h	
		rm calc