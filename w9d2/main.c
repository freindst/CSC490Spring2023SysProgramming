#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    //1. use a hard
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sum = 0;
    int pid = fork();
    for(int i = 0; i < 10; i++){
        if (pid == 0){
            if (i % 2 == 0){
                int b;
                sum = sum + i;
            }
        } else {
            if (i % 2 != 0){
                sum += i;
            }
        }
    }
    int a;
    printf("%d\n", sum);
    printf("%p.\n", &a);
    return 0;
}