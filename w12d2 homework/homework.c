#include <stdio.h>
#include <pthread.h>

#define THREAD_MAX 3

pthread_mutex_t mutex;

void * runCount(void * arg){
    pthread_mutex_lock(&mutex);
    for(int i = 1; i <= 100; i++){
        printf("thread %d is printing %d.\n", *(int *)arg, i);
    }
    pthread_mutex_unlock(&mutex);
    return arg;
}

int main(){
    pthread_mutex_init(&mutex, NULL);
    pthread_t threads[3];
    int i;
    for(i = 0; i < 3; i++){
        pthread_create(&threads[i], NULL, runCount, (void *) &i);
    }

    for(i = 0; i < 3; i++){
        pthread_join(threads[i], (void *)NULL);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}