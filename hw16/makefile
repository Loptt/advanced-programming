main: Service.o Problem.o
	gcc -o main Service.o Problem.o

Service.o: Service.c Problem.h
	gcc -c Service.c

Problem.o: Problem.c Problem.h
	gcc -c Problem.c
