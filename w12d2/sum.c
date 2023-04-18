#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum = 0;
int counter = 0;
int * array;

void * summing(void * arg){
    int a = *(int *)arg;
    sum = sum + a;
    return NULL;
}

//this is not a safe method
void * summing_n(void * arg){
    for(int i = counter; i < 100; i=i+3){
        sum = sum + array[i];
    }
    counter++;
    return NULL;
}

int n = 0;

//but it is still not 100% safe
void * summing_1(void * arg){
    sum = sum + array[n];
    n++;
    //long processing code
    return NULL;
}

int main(){
    pthread_t t_id[4]; //thread 1, thread 2, thread 3
    array = malloc(sizeof(int) * 100);
    for(int i = 0; i < 100; i++){
        array[i] = i + 1;
    }
    //global variable n
    //1, 2, 3, 4, 5, 6, 7, 8, 9
    //thread 1: 1,     4,     7. 1
    //thread 2:  ,2,    ,5,    8, 2
    //thread 3: ,,,3,   ,,6   ,,9, 3
    
    for(int i = 1; i <= 100; i++){
        pthread_create(&t_id[i % 4], NULL, summing_1, (void *)NULL);
        //pthread_join(t_id[i % 3], NULL);
    }
    for(int i = 0; i < 4; i++){
        pthread_join(t_id[i], NULL);
    }
    printf("%d", sum);
    return 0;
}

/*
for(int i = 0; i < 3; i++){
        pthread_create(&t_id[i % 3], NULL, summing_n, (void *)NULL);
    }
    for(int i = 0; i < 3; i++){
        pthread_join(t_id[i], NULL);
    }
*/