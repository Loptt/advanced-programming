#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_THREADS 5

void *printHello (void *threadid){
    long tid;
    tid=(long)threadid;
    printf("Hello World! Itâ€™s me, thread #%ld!\n", tid);
    pthread_exit(NULL);
}

int main (int argc, char *argv[]) { 
    pthread_t threads[NUM_THREADS]; 
    int rc = 0; 
    long t = 0; 
    
    for (t = 0; t < NUM_THREADS; t++) { 
        printf("In main: creating thread %ld\n", t); 
        rc = pthread_create(threads + t, NULL, printHello, (void *) t); 
        if (rc) { 
            printf("ERROR; return code from pthread_create() is %d\n", rc); 
            exit(-1);
            
        } 
        
    } 
    pthread_exit(NULL);
}