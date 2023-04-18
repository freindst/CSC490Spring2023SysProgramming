#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *printOut(void * ptr){
    int64_t type = (int64_t) ptr;
    printf("This is a sub program: %lld.\n", type);
    return NULL;
}

void * increment(void * input){
    printf("%p", input);
    for(int i = 0; i < 100; i++){
        (*(int *)input)++;
    }
    return NULL;
}

int main(){
    pthread_t tid =  pthread_self();
    pthread_t tid2;
    int a = 0;
    int ret = pthread_create(&tid2, NULL, increment, (void *) &a);
    pthread_join(tid2, NULL);
    printf("The value here is: %d.\n", a);
    return 0;
}