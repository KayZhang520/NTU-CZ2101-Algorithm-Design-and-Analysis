#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int** generateGraph(int size){
    int **arr = malloc(size * sizeof(int*));
    int i, j;
    for(i=0;i<size;i++){
        arr[i] = malloc(size * sizeof(int)); 
        for(j=0;j<size;j++){
            arr[i][j] = 1;            
        }
    }

    return arr;
}

int** generateGraph2(int size, int links){
    int **arr = malloc(size * sizeof(int*));
    int i, j;
    for(i=0;i<size;i++){
        arr[i] = malloc(size * sizeof(int)); 
        for(j=0;j<size;j++){
            if(j<links)arr[i][j] = 1;    
            else arr[i][j] = 0;        
        }
    }

    return arr;
}