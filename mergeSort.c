#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int n, int mid, int m){
    //will be using temp arrays to sort the range to be merged
    int i, j, k;
    int x;
    int sizeL = mid-n+1;
    int sizeR = m-mid;
    int* L = malloc(sizeof(int)*sizeL);
    int* R = malloc(sizeof(int)*sizeR);

    //coping things over to the subarrays;
    for(x=0;x<sizeL;x++){
        L[x] = arr[n+x];
    }
    for(x=0;x<sizeR;x++){
        R[x] = arr[mid+1+x];
    }
    

    //use values in sub, and sort the main array arr.
    i=0; j=0; k=n;
    while(i<sizeL && j<sizeR){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    //complete sorting using 2 while loops to take care of leftover unsorted elements
    while(i<sizeL){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<sizeR){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int n, int m){
    if(n>=m)return;
    if(n<m){
        int mid = (n+m)/2;
        mergeSort(arr, n, mid);
        mergeSort(arr, mid+1, m);

        merge(arr, n, mid, m);
    }
}

int main(){
    int arr[7] = {2,1,9,6,5,4,3};
    int i;
    mergeSort(arr, 0, 6);
    for(i=0;i<7;i++){
        printf("%i\n",arr[i]);
    }
}