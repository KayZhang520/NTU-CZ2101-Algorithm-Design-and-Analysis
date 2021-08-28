#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int n, int mid, int m, int* cmpCount){
    int i, j, k; int x;
    int sizeL = mid-n+1; int sizeR = m-mid;
    int* L = malloc(sizeof(int)*sizeL);
    int* R = malloc(sizeof(int)*sizeR);

    //L and R are temparary arrays to sort things out
    for(x=0;x<sizeL;x++)L[x] = arr[n+x];
    for(x=0;x<sizeR;x++)R[x] = arr[mid+1+x];

    
    //merge L and R into the main array
    i=0; j=0; k=n; //i j and k keeps track of index in L, R and main array respectively
    //sort until either of L and R is emptied
    while(i<sizeL && j<sizeR){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        (*cmpCount)++;
        k++; 
    }

    //complete sorting to take care of leftover 
    while(i<sizeL){
        arr[k] = L[i];
        i++;
        k++;
        (*cmpCount)++;
    }
    while(j<sizeR){
        arr[k] = R[j];
        j++;
        k++;
        (*cmpCount)++;
    }

    free(L);
    free(R);
}

void insertSort(int arr[], int n, int m, int* cmpCount){
    int size = m-n+1; int i;
    int key, j; //key tracks current index's value
    for (i = 0; i<size; i++) {
        key = arr[n+i];
        j = n+i - 1;
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= n && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*cmpCount)++;
        }
        arr[j + 1] = key;
    } 
}

//mergesort for a range of an array
void mergeInsertSort(int arr[], int n, int m, int threshold, int* cmpCount){
    if(n>=m)return; //if(range has 1 or less elements)
    if(n<m){
        int mid = (n+m)/2;
        mergeInsertSort(arr, n, mid, threshold, cmpCount);
        mergeInsertSort(arr, mid+1, m, threshold, cmpCount);

        if((m-n+1)>threshold)
            merge(arr, n, mid, m, cmpCount);
        else     
            insertSort(arr, n, m, cmpCount);
    }
} 

algorithmTester(int size, int threshold){
    int *cmpCount = malloc(sizeof(int));
    int* arr = malloc(sizeof(int)*size);
    int i;

    *cmpCount = 0;
    for(i=0;i<size;i++)arr[i]=1; //initialize array

    mergeInsertSort(arr, 0, size, threshold, cmpCount);
    printf("no. of comparisons: %i\n", *cmpCount);
    free(arr);
    free(cmpCount);
}

int main(){
    // int arr[7] = {2,1,9,6,5,4,3};
    // printf("no. of comparisons: %i\n", mergeInsertSort(arr, 0, 6, 2, cmpCount));
    // for(i=0;i<7;i++){
    //     printf("%i\n",arr[i]);
    // }
    int i;
    int n = 10000000;
    for(i=0;i<10;i++){
        int s = i;
        printf("S=%i:\n", s);
        clock_t t = clock();
        algorithmTester(n, s);
        t = clock() - t;
        printf("timeTaken: %f\n\n", ((double) t) / CLOCKS_PER_SEC);
    }
}