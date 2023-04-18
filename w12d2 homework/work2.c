#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 20
int a[MAX];

void display(){
    for(int i = 0; i < 20; i++){
        printf("%d, ", a[i]);
    }
    printf("\n");
}

void merge(int low, int mid, int high){
    printf("array from %d to % d, middle is %d\n", low, high, mid);
    int leftSize = mid - low + 1;
    int rightSize = high - mid;
    int * left = malloc(sizeof(int) * leftSize);
    int * right = malloc(sizeof(int) * rightSize);
    int i, j;
    for (i = 0; i < leftSize; i++){
        left[i] = a[i + low];
    }
    for (j = 0; j < rightSize; j++){
        right[j] = a[j + mid + 1];
    }

    int k = low;
    i = j = 0;
    while (i < leftSize && j < rightSize){
        if (left[i] < right[j]){
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < leftSize){
        a[k] = left[i];
        k++;
        i++;
    }
    while (j < rightSize){
        a[k] = right[j];
        k++;
        j++;
    }
    free(left);
    free(right);
    display();
}

void merge_sort(int low, int high)
{
    // calculating mid point of array
    int mid = low + (high - low) / 2;
    if (low < high) {
 
        // calling first half
        merge_sort(low, mid);
 
        // calling second half
        merge_sort(mid + 1, high);
 
        // merging the two halves
        merge(low, mid, high);
    }
}

int main(){
    for(int i = 0; i < 20; i++){
        a[i] = 20 - i;
    }
    merge_sort(0, 19);
    display();

    return 0;
}