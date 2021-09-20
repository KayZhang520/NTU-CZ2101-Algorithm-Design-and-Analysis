import java.util.*;
import java.lang.*;
import java.io.*;

class MST {
	// Number of vertices in the graph
	private static final int V = 5;

	// returns index of nearest vertex not in MST
	int minKey(int key[], Boolean mstSet[])
	{
		int min = Integer.MAX_VALUE, min_index = -1;
		for (int v = 0; v < V; v++)
			if (mstSet[v] == false && key[v] < min) {
				min = key[v];
				min_index = v;
			}
		return min_index;
	}

	// prints MST
	void printMST(int parent[], int graph[][])
	{
		System.out.println("Edge \tWeight");
		for (int i = 1; i < V; i++)
			System.out.println(parent[i] + " - " + i + "\t" + graph[i][parent[i]]);
	}

	// Main MST finding algorithm
	void primMST(int graph[][])
	{
		int parent[] = new int[V]; //stores parent of each vertex, those not is MST is 0;
		int key[] = new int[V]; //distance to MST
		Boolean mstSet[] = new Boolean[V]; //array of boolean for isMST

		// Initialize all keys as INFINITE
		for (int i = 0; i < V; i++){
			key[i] = Integer.MAX_VALUE;
			mstSet[i] = false;
		}

		// Always include first 1st vertex in MST.
		key[0] = 0; // Make key 0 so that this vertex is
		// picked as first vertex
		parent[0] = -1; // First node is always root of MST

		// The MST will have V vertices
		for (int count = 0; count < V - 1; count++) {
			// Pick the minimum key vertex from the set of vertices
			// not yet included in MST
			int u = minKey(key, mstSet);

			// Add the picked vertex to the MST Set
			mstSet[u] = true;

			// Updating of adj vertices v when a vertex u is added to the matrix
			for (int v = 0; v < V; v++)

				// graph[u][v] is non zero only for adjacent vertices of m
				// mstSet[v] is false for vertices not yet included in MST
				// Update the key only if graph[u][v] is smaller than key[v]
				if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v]) {
					parent[v] = u;
					key[v] = graph[u][v];
				}
		}

		// print the constructed MST
		printMST(parent, graph);
	}

	public static void main(String[] args)
	{
		MST t = new MST();
		int graph[][] = new int[][] { { 0, 2, 0, 6, 0 },
									{ 2, 0, 3, 8, 5 },
									{ 0, 3, 0, 0, 7 },
									{ 6, 8, 0, 0, 9 },
									{ 0, 5, 7, 9, 0 } };

		// Print the solution
		t.primMST(graph);
	}
}
// This code is contributed by Aakash Hasija
