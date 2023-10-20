//Java program to implement the Karger's algorithm to find Minimum Cut in an
// undirected, unweighted and connected graph.

import java.io.*;
import java.util.*;

class GFG {
	
	// a structure to represent a unweighted edge in graph
	public static class Edge
	{
		int src, dest;
		Edge(int s, int d){
			this.src = s;
			this.dest = d;
		}
	}
	
	// a structure to represent a connected, undirected
	// and unweighted graph as a collection of edges.
	public static class Graph
	{
		// V-> Number of vertices, E-> Number of edges
		int V, E;
	
		// graph is represented as an array of edges.
		// Since the graph is undirected, the edge
		// from src to dest is also edge from dest
		// to src. Both are counted as 1 edge here.
		Edge edge[];
		Graph(int v, int e){
			this.V = v;
			this.E = e;
			this.edge = new Edge[e];
			/*for(int i=0;i<e;i++){
				this.edge[i]=new Edge(-1,-1);
			}*/
		}
	}
	
	// A structure to represent a subset for union-find
	public static class subset
	{
		int parent;
		int rank;
		subset(int p, int r){
			this.parent = p;
			this.rank = r;
		}
	}
	
	// A very basic implementation of Karger's randomized
	// algorithm for finding the minimum cut. Please note
	// that Karger's algorithm is a Monte Carlo Randomized algo
	// and the cut returned by the algorithm may not be
	// minimum always
	public static int kargerMinCut(Graph graph)
	{
		// Get data of given graph
		int V = graph.V, E = graph.E;
		Edge edge[] = graph.edge;
	
		// Allocate memory for creating V subsets.
		subset subsets[] = new subset[V];
	
		// Create V subsets with single elements
		for (int v = 0; v < V; ++v)
		{
			subsets[v] = new subset(v,0);
		}
	
		// Initially there are V vertices in
		// contracted graph
		int vertices = V;
	
		// Keep contracting vertices until there are
		// 2 vertices.
		while (vertices > 2)
		{
		// Pick a random edge
		int i = ((int)(Math.random()*10)) % E;
	
		// Find vertices (or sets) of two corners
		// of current edge
		int subset1 = find(subsets, edge[i].src);
		int subset2 = find(subsets, edge[i].dest);
	
		// If two corners belong to same subset,
		// then no point considering this edge
		if (subset1 == subset2){
			continue;
		}
	
		// Else contract the edge (or combine the
		// corners of edge into one vertex)
		else
		{
			System.out.println("Contracting edge "+edge[i].src+"-"+edge[i].dest);
			vertices--;
			Union(subsets, subset1, subset2);
		}
		}
	
		// Now we have two vertices (or subsets) left in
		// the contracted graph, so count the edges between
		// two components and return the count.
		int cutedges = 0;
		for (int i=0; i<E; i++)
		{
			int subset1 = find(subsets, edge[i].src);
			int subset2 = find(subsets, edge[i].dest);
			if (subset1 != subset2){
				cutedges++;
			}
		}
	
		return cutedges;
	}
	
	// A utility function to find set of an element i
	// (uses path compression technique)
	public static int find(subset subsets[], int i)
	{
		// find root and make root as parent of i
		// (path compression)
		if (subsets[i].parent != i){
			subsets[i].parent = find(subsets, subsets[i].parent);
		}
		return subsets[i].parent;
	}
	
	// A function that does union of two sets of x and y
	// (uses union by rank)
	public static void Union(subset subsets[], int x, int y)
	{
		int xroot = find(subsets, x);
		int yroot = find(subsets, y);
	
		// Attach smaller rank tree under root of high
		// rank tree (Union by Rank)
		if (subsets[xroot].rank < subsets[yroot].rank){
			subsets[xroot].parent = yroot;
		}else{
			if (subsets[xroot].rank > subsets[yroot].rank){
				subsets[yroot].parent = xroot;
			}
			// If ranks are same, then make one as root and
			// increment its rank by one
			else
			{
				subsets[yroot].parent = xroot;
				subsets[xroot].rank++;
			}
		} 
	}
	
	// Driver program to test above functions
	public static void main (String[] args) {
		/* Let us create following unweighted graph
			0------1
			| \ |
			| \ |
			|	 \|
			2------3 */
		int V = 4; // Number of vertices in graph
		int E = 5; // Number of edges in graph
		
		// Creates a graph with V vertices and E edges
		Graph graph = new Graph(V, E);
	
		// add edge 0-1
		graph.edge[0] = new Edge(0,1);
	
		// add edge 0-2
		graph.edge[1] = new Edge(0,2);
	
		// add edge 0-3
		graph.edge[2] = new Edge(0,3);
	
		// add edge 1-3
		graph.edge[3] = new Edge(1,3);
	
		// add edge 2-3
		graph.edge[4] = new Edge(2,3);
	
		System.out.println("Cut found by Karger's randomized algo is "+kargerMinCut(graph));
	}
}
//This code is contributed by shruti456rawal
