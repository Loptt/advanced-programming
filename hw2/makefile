types: types.o clean_stdin.o
	gcc types.o clean_stdin.o -o types

types.o: types.c clean_stdin.h
	gcc -c types.c

clean_stdin.o: clean_stdin.c clean_stdin.h
	gcc -c clean_stdin.c