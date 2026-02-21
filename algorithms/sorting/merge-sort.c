#include<stdio.h>

void merge(int *a, int p, int q, int r){

    int i = 0, j = 0, k = p;
    int nL = q - p + 1;
    int nR = r - q;
    int left[nL], right[nR];

    for(i=0;i<nL;i++)
        left[i] = a[p+i];

    for(j=0;j<nR;j++)
        right[j] = a[q+1+j];
    i = 0;
    j = 0;
    while(i < nL && j < nR){
        if(left[i] <= right[j]){
            a[k] = left[i];
            i++;
        }
        else{
            a[k] = right[j];
            j++;
        }
    k++;
    }

    while(i < nL){
        a[k] = left[i];
        i++;
        k++;
    }
    while(j < nR){
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int *a, int p, int r){
    int q;
    if(p>=r)
        return;
    q = (p + r) / 2;
    mergeSort(a,p,q);
    mergeSort(a,q+1,r);
    merge(a,p,q,r);
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
    mergeSort(arr,0,n);
    printf("\nSorted array:\n");
    printArray(arr,n);

    return 1;
}