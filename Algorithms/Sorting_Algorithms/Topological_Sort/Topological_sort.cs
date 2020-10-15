//  Topological_sort algorithm.
using System; 
using System.Collections.Generic; 
  
// Class represents a directed graph 
// using adjacency list representation 
class Graph { 
  
    // for vertices 
    private int V; 
  
    // Adjacency List as ArrayList 
    // of ArrayList's 
    private List<List<int> > adj; 
  
    Graph(int v) 
    { 
        V = v; 
        adj = new List<List<int> >(v); 
        for (int i = 0; i < v; i++) 
            adj.Add(new List<int>()); 
    } 
  
    // Function to add an edge into the graph 
    public void AddEdge(int v, int w) { adj[v].Add(w); } 
  
    // A recursive function used by topologicalSort 
    void TopologicalSortUtil(int v, bool[] visited, 
                             Stack<int> stack) 
    { 
  
        visited[v] = true; 
        foreach(var vertex in adj[v]) 
        { 
            if (!visited[vertex]) 
                TopologicalSortUtil(vertex, visited, stack); 
        } 
  
        // Push current vertex to 
        // stack which stores result 
        stack.Push(v); 
    } 
  
   
    void TopologicalSort() 
    { 
        Stack<int> stack = new Stack<int>(); 
  
        // Mark all the vertices as not visited 
        var visited = new bool[V]; 
   
        for (int i = 0; i < V; i++) { 
            if (visited[i] == false) 
                TopologicalSortUtil(i, visited, stack); 
        } 
  
        // Print contents of stack 
        foreach(var vertex in stack) 
        { 
            Console.Write(vertex + " "); 
        } 
    } 
  
    public static void Main(string[] args) 
    { 
  
        // Create a graph given 
        // in the above diagram 
        Graph g = new Graph(6); 
        g.AddEdge(5, 2); 
        g.AddEdge(5, 0); 
        g.AddEdge(4, 0); 
        g.AddEdge(4, 1); 
        g.AddEdge(2, 3); 
        g.AddEdge(3, 1); 
          
          // Function Call 
        g.TopologicalSort(); 
    } 
} 
  
  /* output is: 5 4 3 2 1 0
   * time complexity : O(V+E)
   * auxiliary space: O(V)
   */