#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int FindFirstAvaiableSpot();
void * HoldTable(void * arg);
void displayTables();

#define size 10
sem_t reserve;

int counter = 0;
int arr[size];

//a new guest will come and hold one spot of all tables
void * HoldTable(void * arg){
    sem_wait(&reserve);
    int local_id;
    counter = counter + 1;
    local_id = counter;
    int spot = FindFirstAvaiableSpot();
    if (spot > -1){
        arr[spot] = local_id;
        displayTables();
    }
    sem_post(&reserve);
    arr[spot] = 0;
    displayTables();
    return NULL;
}

int FindFirstAvaiableSpot(){
    for(int i = 0; i < size; i++){
        if (arr[i] == 0){
            return i;
        }
    }
    return -1;
}

void displayTables(){
    //"0: 15, "
    /*char str[61];
    for(int i = 0; i < size; i++){
        str[i] = char(i);
    }*/
    for(int i = 0; i < size; i++)
        printf("%d: %d, ", i, arr[i]);
    printf("\n");
}

int main(){
    sem_init(&reserve, 0, size);
    for(int i = 0; i < size; i++){
        arr[i] = 0;
    }
    pthread_t threads[100];
    for(int i = 0; i < 100; i++){
        pthread_create(&threads[i], NULL, HoldTable, NULL);
    }
    for(int i = 0; i < 100; i++){
        pthread_join(threads[i], NULL);
    }
    displayTables();
    sem_destroy(&reserve);
    return 0;
}