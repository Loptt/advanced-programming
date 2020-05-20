practice16: Service.o Problem.o
	gcc -o practice16 Service.o Problem.o

Service.o: Service.c Problem.h
	gcc -c Service.c

Problem.o: Problem.c Problem.h
	gcc -c Problem.c

clean:
	rm -rf *.o practice16