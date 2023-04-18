#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


//arr, low, mid, high
//lower: 7
//upper: 
//sorted: 1, 2, 3, 4, 5, 6, 7
void merge(int * arr, int low, int mid, int high){
    int * lower, * upper;
    lower = malloc(sizeof(int) * (mid - low + 1));
    upper = malloc(sizeof(int) * (high - mid));
    int j, k; //j is the counter for lower, and k is the counter for upper;
    int n = low;
    for(int j = 0; j < (mid - low + 1); j++){
        lower[j] = arr[n];
        n++;
    }
    for(int k = 0; k < high - mid; k++){
        upper[k] = arr[n];
        n++;
    }
    n = low;
    j = 0;
    k = 0;
    while(j < (mid - low + 1) && k < (high - mid)){
        if (lower[j] < upper[k]){
            arr[n] = lower[j];
            j++;
        } else {
            arr[n] = upper[k];
            k++;
        }
        n++;
    }
    while(j < mid - low + 1){
        arr[n] = lower[j];
        n++;
        j++;
    }
    while(k < high - mid){
        arr[n] = upper[k];
        n++;
        k++;
    }
}

//divide the array into two and recursively call merge_sort
void merge_sort(int * arr, int low, int high){
    if (low < high){
        int mid = (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        //merge sort arr1, arr2, arr3, arr4
        //merge join arr1 and arr2
        //merge join arr3, and arr4
        //merge join arr12 and arr34
        merge(arr, low, mid, high);
    }
}

int main(){
    //make your random array
    //merge sort
    //multithreading merge sort

    return 0;
}