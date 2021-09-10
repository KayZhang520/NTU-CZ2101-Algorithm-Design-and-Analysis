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