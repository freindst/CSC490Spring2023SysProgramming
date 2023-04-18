#include <stdio.h>
#include <pthread.h>

#define THREAD_MAX 3;

void * runCount(void * arg){
    for(int i = 1; i <= 100; i++){
        printf("thread %d is printing %d.\n", *(int *)arg, i);
    }
    return arg;
}

int main(){
    pthread_t threads[3];
    int i;
    for(i = 0; i < 3; i++){
        pthread_create(&threads[i], NULL, runCount, (void *) &i);
    }

    for(i = 0; i < 3; i++){
        pthread_join(threads[i], (void *)NULL);
    }

    return 0;
}