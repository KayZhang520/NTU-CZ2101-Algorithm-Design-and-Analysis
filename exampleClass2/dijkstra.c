#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>


int minDistance(int dist[], bool isRelaxed[], int size)//this is a O(V) operation
{
    //finds the vertice with shortest path to root, returns its index
    int min = INT_MAX, min_index;

    for (int v = 0; v < size; v++)
        if (isRelaxed[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int size)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < size; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int** graph, int source, int size)
{
    int* dist = malloc(size*sizeof(int)); 
    bool* isRelaxed = malloc(size*sizeof(int)); //records whether each vertice is relaxed via a boolean

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < size; i++)
        dist[i] = INT_MAX, isRelaxed[i] = false;

    dist[source] = 0;//src is nearest to src

    // Find shortest path for all the n-1 vertices
    for (int count = 0; count < size - 1; count++)
    {
        int u = minDistance(dist, isRelaxed, size);//find vertice with shortest path that is unprocessed

        isRelaxed[u] = true;// Mark the picked vertex as processed

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < size; v++)
        /* all conditions for processing v with u:
            1. v is unprocessed
            2. u and v are directly connected
            3. path of root to u is NOT infinity
            4. path that uses u as midpt is shorter than root to v
        */
            if (!isRelaxed[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // printSolution(dist, size);
}

// int main()
// {
//     printf("Enter number of vertices: \n");
//     int size;
//     scanf("%i", &size);
//     int** graph = generateGraph(size);


//     clock_t t = clock();
//     dijkstra(graph, 0, size);
//     t = clock()-t;
//     printf("time taken %f\n", (double)t);
// }