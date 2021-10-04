using System; 

class DA {
    static int V = 9; 
    int minDistance(int[] dist, 
                    bool[] sptSet) 
    { 
        int min = int.MaxValue, min_index = -1; 
  
        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min) { 
                min = dist[v]; 
                min_index = v; 
            }
        return min_index; 
    } 
  
    void printSolution(int[] dist, int n) 
    { 
        Console.Write("Vertex     Distance " + "from Source\n"); 
        for (int i = 0; i < V; i++) 
            Console.Write(i + " \t\t " + dist[i] + "\n"); 
    } 
  
    void dijkstra(int[, ] graph, int src) 
    { 
        int[] dist = new int[V]; // The output array. dist[i] 
        bool[] sptSet = new bool[V]; 
 
        for (int i = 0; i < V; i++) { 
            dist[i] = int.MaxValue; 
            sptSet[i] = false; 
        } 
  
        dist[src] = 0; 
  
        // To find shortest path for all the vertices 
        for (int count = 0; count < V - 1; count++) { 
            int u = minDistance(dist, sptSet); 

            sptSet[u] = true; 
            for (int v = 0; v < V; v++) 
                if (!sptSet[v] && graph[u, v] != 0 &&  
                     dist[u] != int.MaxValue && dist[u] + graph[u, v] < dist[v]) 
                    dist[v] = dist[u] + graph[u, v]; 
        } 
  
        printSolution(dist, V); 
    } 
  
    public static void Main() 
    {  
        int[, ] graph = new int[, ] { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                                      { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                                      { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                                      { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                                      { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                                      { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                                      { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                                      { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                                      { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
        DA t = new DA(); 
        t.dijkstra(graph, 0); 
    } 
} 