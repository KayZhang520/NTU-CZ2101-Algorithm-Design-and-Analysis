// Java program for Kruskal's algorithm
// find Minimum Spanning Tree of a given connected, undirected and weighted graph
import java.util.*;

class Graph {
	class Edge implements Comparable<Edge>//->this is a available interface in java.lang package
	{
		int src, dest, weight;
		// Comparator function used for sorting edges based on their weight
		public int compareTo(Edge compareEdge)
		{
			return this.weight - compareEdge.weight;
		}
	};

	// A class to represent a subset for union-find
	class subset
	{
		int parent, rank;
	};

	int V, E; // V-> no. of vertices & E->no.of edges
	Edge edge[]; // collection of all edges

	// Creates a graph with V vertices and E edges
	Graph(int v, int e)
	{
		V = v;
		E = e;
		edge = new Edge[E];
		for (int i = 0; i < e; ++i)
			edge[i] = new Edge(); //edges are not initialized yet?
	}

	// A utility function to find set of a subset i (uses path compression technique)
	int find(subset subsets[], int i)
	{
		// find root of ith subset recursively, and set that as ith subset's parent(essentially a union?)
		if (subsets[i].parent != i)
			subsets[i].parent = find(subsets, subsets[i].parent); //set i'th subset's parent as i?
		return subsets[i].parent; //will always return the root of the subset, ie the full set
	}

	// A function that does union of two sets of x and y (uses union by rank)
	// Very neat function btw
	void Union(subset subsets[], int x, int y)
	{
		int xroot = find(subsets, x);
		int yroot = find(subsets, y);
		// Attach smaller rank tree under root of high rank tree (Union by Rank)
		if (subsets[xroot].rank //using rank to determine which set is on top, rank is basically a rank of size because of how it is incremented
			< subsets[yroot].rank)
			subsets[xroot].parent = yroot;
		else if (subsets[xroot].rank
				> subsets[yroot].rank)
			subsets[yroot].parent = xroot;
		// If ranks are same, then make one as
		// root and increment its rank by one
		else {
			subsets[yroot].parent = xroot;
			subsets[xroot].rank++;
		}
	}

	// The main function to construct MST using Kruskal's algorithm
	void KruskalMST()
	{
		// This will store the resultant MST
		Edge result[] = new Edge[V];
	
		// An index variable, used for result[]
		int e = 0;
	
		// An index variable, used for sorted edges
		int i = 0;
		for (i = 0; i < V; ++i)
			result[i] = new Edge();

		// Step 1: Sort all the edges in increasing order of their weight.
		// If we are not allowed to change the given graph, we can create a copy of array of edges
		Arrays.sort(edge);

		// Initialize all v subsets of size 1
		subset subsets[] = new subset[V];
		for (i = 0; i < V; ++i)
			subsets[i] = new subset();
		for (int v = 0; v < V; ++v)
		{
			subsets[v].parent = v;
			subsets[v].rank = 0;
		}

		i = 0; 

		//Find v-1 vertices
		while (e < V - 1)
		{
			// Step 2: Pick the smallest edge. And increment
			// the index for next iteration
			Edge next_edge = edge[i++];

			int x = find(subsets, next_edge.src);
			int y = find(subsets, next_edge.dest);

			// If this edge dont cause cycle, union the subsets
			//	add this edge to MST
			if (x != y) {
				result[e++] = next_edge; //note that result keep things chronologically
				Union(subsets, x, y);
			}
			// Else discard the next_edge
		}

		// print the contents of result[] to display the built MST
		System.out.println("Following are the edges in the constructed MST");
		int minimumCost = 0;
		for (i = 0; i < e; ++i)
		{
			System.out.println(result[i].src + " -- "
							+ result[i].dest
							+ " == " + result[i].weight);
			minimumCost += result[i].weight;
		}
		System.out.println("Minimum Cost Spanning Tree "
						+ minimumCost);
	}

	// Driver Code
	public static void main(String[] args)
	{
		int V = 4; // Number of vertices in graph
		int E = 5; // Number of edges in graph
		Graph graph = new Graph(V, E);

		// add edge 0-1
		graph.edge[0].src = 0;
		graph.edge[0].dest = 1;
		graph.edge[0].weight = 10;

		// add edge 0-2
		graph.edge[1].src = 0;
		graph.edge[1].dest = 2;
		graph.edge[1].weight = 6;

		// add edge 0-3
		graph.edge[2].src = 0;
		graph.edge[2].dest = 3;
		graph.edge[2].weight = 5;

		// add edge 1-3
		graph.edge[3].src = 1;
		graph.edge[3].dest = 3;
		graph.edge[3].weight = 15;

		// add edge 2-3
		graph.edge[4].src = 2;
		graph.edge[4].dest = 3;
		graph.edge[4].weight = 4;

		// Function call
		graph.KruskalMST();

	}
}
// This code is contributed by Aakash Hasija
