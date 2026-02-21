#include<stdio.h>

void insertionSort(int *a, int n){
    int key, i, j;

    for(i = 1; i < n; i++){
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void printArray(int *a, int n){
    for(int i = 0; i < n; i ++){
            printf("%d ",a[i]);
    }
}

int main(){
    int arr[] = {5,7,2,4,6,1,3,0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array:\n");
    printArray(arr,n);
    insertionSort(arr,n);
    printf("\nSorted array:\n");
    printArray(arr,n);

    return 1;
}