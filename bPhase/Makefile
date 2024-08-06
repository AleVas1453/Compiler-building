compile:
		bison --defines --output=parser.c parser.y
		flex --outfile=scanner.c scanner_B.l
		gcc -o calc scanner.c parser.c symtable.c
		./calc 
		
clean:
		rm -rf parser2.c
		rm -rf scanner.c
		rm -rf parser.h	
		rm calc