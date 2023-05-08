#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t mutex;

void * doSomething(void * arg){
    unsigned long i = 0;
    //thread 0 lock the critical section here, then no other 
    //threads are allowed to execute. They have to wait.
    pthread_mutex_lock(&mutex); 
    int local_id; // new, per-thread variable                                    
    counter += 1;
    local_id = counter; // make a local copy of counter for this thread                                
    
    printf("  Job %d started\n", counter);
    for(i=0; i<(0xFFFFFFFF);i++);
    printf("  Job %d finished\n", counter);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(){
    pthread_mutex_init(&mutex, NULL);
    pthread_t pthreads[10];
    for(int i = 0; i < 10; i++){
        pthread_create(&pthreads[i], NULL, doSomething, NULL);
    }
    for(int i = 0; i < 10; i++){
        pthread_join(pthreads[i], NULL);
    }
    printf("%d\n", counter);
    pthread_mutex_destroy(&mutex);
    return 0;
}