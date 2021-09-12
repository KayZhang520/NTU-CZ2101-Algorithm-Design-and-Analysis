#include <stdio.h>
#include <stdlib.h>

#include "utilities.c"
#include "dijkstra.c"


int main(){
    int size, links;
    printf("Enter size of array: \n");
    scanf("%i", &size);
    printf("Enter links per node: \n");
    scanf("%i", &links);
    int** graph = generateGraph2(size, links);
    for(int x=0;x<10;x++){
    clock_t t = clock();
    dijkstra(graph, 0, size);
    t = clock()-t;
    printf("time taken %f\n", (double)t);
    }
}