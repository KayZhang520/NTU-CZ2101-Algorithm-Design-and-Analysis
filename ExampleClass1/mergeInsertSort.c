#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int n, int mid, int m, int* cmpCount){
    int midstart = mid + 1;
    int temp;

    while(n <= mid && midstart <= m) {
        (*cmpCount)++;
        if (arr[n] < arr[midstart]) { //1st element of 1st half smaller
            n++;
        } else if (arr[n] > arr[midstart]) { //1st element of 2nd half smaller
            temp = arr[midstart];
            for(int i = midstart; i>n; i--) {
                arr[i] = arr[i-1];
            }
            arr[n] = temp;
            n++;
            mid++;
            midstart++;
        } else { //1st element of both halfs are equal
            n++;
            for(int i = midstart; i>n; i--) { 
                arr[i] = arr[i-1];
            }
            arr[n] = arr[n-1];
            n++;
            mid++;
            midstart++;
        }
    }
}

void insertSort(int arr[], int n, int m, int* cmpCount){
        int temp; 
        for (int i = n; i<=m; i++) { //i starts at 1, the 2nd element
            for (int j = i; j>n; j--) {
                (*cmpCount)++;
                if (arr[j] < arr[j-1]) {
                    temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                } else break;
        }
    } 
}

//mergesort for a range of an array
void mergeInsertSort(int arr[], int n, int m, int threshold, int* cmpCount){
    if(n>=m)return; //if(range has 1 or less elements)
    if(n<m){
        if((m-n+1)>threshold) {
            int mid = (n+m)/2;
            mergeInsertSort(arr, n, mid, threshold, cmpCount);
            mergeInsertSort(arr, mid+1, m, threshold, cmpCount);
            merge(arr, n, mid, m, cmpCount);
        } else {
            insertSort(arr, n, m, cmpCount);
        }
    }
} 

void algorithmTester(int size,int S, FILE* fp){
    int* arr = malloc(sizeof(int)*size);
    int *cmpCount;
    *cmpCount = 0;

    clock_t t;
    t = clock();
    //-----------------------------------------
    mergeInsertSort(arr, 0, size-1, S, cmpCount);
    //-----------------------------------------
    t = t-clock();
    fprintf(fp, "%i,", *cmpCount);
    fprintf(fp, "%d\n", t);
    free(cmpCount);
}

int main(){
    FILE* fp;
    fp  = fopen ("data.csv", "w");
    //---------------------------------------
    int n, maxi;
    printf("Enter size of array: \n");
    scanf("%d", &n);
    printf("Enter maximim S value: \n");
    scanf("%d", &maxi);      

    algorithmTester(n, maxi, fp);
    //---------------------------------------
    fclose(fp);
}