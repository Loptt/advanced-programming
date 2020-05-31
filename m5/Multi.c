#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

#define AMOUNT_OF_RECTANGLES 5000000000
#define NUM_THREADS 8

double deltaX;
double accum = 0.0;

pthread_mutex_t lock; 

void* threadRoutine(void *p) {
	double x;
	double fdx;
	double localAccum=0.0;
	double *initialX = (double *) p;
	double finalX = (*initialX) + deltaX * (AMOUNT_OF_RECTANGLES/8);

	for (x = *initialX; x < finalX; x += deltaX) {
		fdx = 4.0/(1.0 + x * x);
		localAccum = localAccum + (fdx * deltaX);
	}

	pthread_mutex_lock(&lock); 

	accum+=localAccum;

	pthread_mutex_unlock(&lock); 
}

long double calculatePiMulti() {
	int i;
	struct timespec start, finish;
    double elapsed;

    int error;

    pthread_t tid[NUM_THREADS]; 
	double param[NUM_THREADS];

	deltaX = 1.0 / AMOUNT_OF_RECTANGLES;

    clock_gettime(CLOCK_MONOTONIC, &start);

    if (pthread_mutex_init(&lock, NULL) != 0) { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    } 
    
	for (i = 0; i < NUM_THREADS; i++) {
		param[i] = (1.0 / NUM_THREADS) * i;
		error = pthread_create(&(tid[i]), NULL, &threadRoutine, &param[i]); 
        if (error != 0) 
            printf("\nThread can't be created :[%s]", strerror(error)); 
	}

    for (i = 0; i < NUM_THREADS; i++) {
		pthread_join(tid[i], NULL); 
	}

    pthread_mutex_destroy(&lock); 

	clock_gettime(CLOCK_MONOTONIC, &finish);

    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    
    printf("Time for calculation: %lf\n", elapsed);

    return accum;
}