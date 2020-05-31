main: main.o Single.o Multi.o
	gcc -o main main.o Single.o Multi.o -lm -lpthread 

main.o: main.c Single.h
	gcc -c main.c

Single.o: Single.c Single.h
	gcc -c Single.c

Multi.o: Multi.c Multi.h
	gcc -c Multi.c