compile:
	flex --outfile=scanner.c scanner.l
	gcc -g -o scanner scanner.c
	./scanner testcom.txt
clean:
	rm -rf  *.c
	rm scanner