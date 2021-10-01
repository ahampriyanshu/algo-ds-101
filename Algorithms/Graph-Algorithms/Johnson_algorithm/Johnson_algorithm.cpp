/* 

@ CPP Program to implement Johnson algorithm

    @ Sample Graph with negative weights


             5
         |-------|
         |       |   
         v  -3   |
    --->(0)---->(1)
    |    | ^     |
    |    |  \ 1  |
-1  |  2 |   \   | 3
    |    |    \  |
    |    v     \ v
    ----(3)-----(2)
             4

    
    @ Sample output


        Enter the number of vertices : 4
        Enter the number of edges : 7
        Enter the edges with source, destination and weight : 
        0 1 -3
        1 2 3
        3 2 4
        2 0 1
        1 0 5
        0 3 2
        3 0 -1

        Shortest distance with vertex 0 as the source : 
        Vertex           Distance from Source
        0                0
        1                -3
        2                0
        3                2

        Shortest distance with vertex 1 as the source : 
        Vertex           Distance from Source
        0                4
        1                0
        2                3
        3                6

        Shortest distance with vertex 2 as the source : 
        Vertex           Distance from Source
        0                1
        1                -2
        2                0
        3                3

        Shortest distance with vertex 3 as the source : 
        Vertex           Distance from Source
        0                -1
        1                -4
        2                -1
        3                0

*/	




#include <bits/stdc++.h> 
  
using namespace std;

// a structure to represent a weighted edge in graph 
struct Edge { 
    int src, dest, weight; 
}; 
  
// a structure to represent a connected, directed and 
// weighted graph 
struct Graph { 
    // V-> Number of vertices, E-> Number of edges 
    int V, E; 
  
    // graph is represented as an array of edges. 
    struct Edge* edge; 
}; 
  
// Creates a graph with V vertices and E edges 
struct Graph* createGraph(int V, int E) 
{ 
    struct Graph* graph = new Graph; 
    graph->V = V; 
    graph->E = E; 
    graph->edge = new Edge[E]; 
    return graph; 
} 
  
  
// The main function that finds shortest distances from src to 
// all other vertices using Bellman-Ford algorithm.  The function 
// also detects negative weight cycle 
vector<int> BellmanFord(struct Graph* graph) 
{ 
    int V = graph->V; 
    int E = graph->E; 
    vector<int> dist; 
  
    // Step 1:  Add a source s and calculate its min distance from every other node 

    for (int i = 0; i <= V; i++) 
        dist.push_back(INT_MAX);
    dist[V] = 0; 

    // An edge is added from s all other vertices...

    for (int i = 0; i < V; i++)
    {
        graph->edge[(E-V)+i].src = V;
        graph->edge[(E-V)+i].dest= i;
        graph->edge[(E-V)+i].weight = 0;
    }
    
  
    // Step 2: Relax all edges |V| - 1 times. A simple shortest 
    // path from src to any other vertex can have at-most |V| - 1 
    // edges 
    for (int i = 0; i < V; i++) { 
        for (int j = 0; j < E; j++) { 
            int u = graph->edge[j].src; 
            int v = graph->edge[j].dest; 
            int weight = graph->edge[j].weight; 
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
                dist[v] = dist[u] + weight; 
        } 
    } 
  
    // Step 3: check for negative-weight cycles.  The above step 
    // guarantees shortest distances if graph doesn't contain 
    // negative weight cycle.  If we get a shorter path, then there 
    // is a cycle. 
    for (int i = 0; i < E; i++) { 
        int u = graph->edge[i].src; 
        int v = graph->edge[i].dest; 
        int weight = graph->edge[i].weight; 
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) { 
            printf("Graph contains negative weight cycle"); 
            return dist; // If negative cycle is detected, simply return 
        } 
    } 
  
    dist.pop_back();
    return dist; 
} 

void printSolution(int dist[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < 4; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 


//  Returns the vertex with minimum  
//  distance from the source 
int minDistance(int dist[], bool sptSet[], int V) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 

// dijkstra algorithm for graph with 
// modified weights(removing negative weights)
void dijkstra(struct Graph* graph, int src, vector<int> h){

    int V = graph->V;
    int E = graph->E;
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int i = 0; i < V-1; i++)
    {
        int u = minDistance(dist, sptSet, V);

        sptSet[u]= true;
        
        for (int j = 0; j < E-V; j++)
        {
            int tu = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int w = graph->edge[j].weight; 
            if (!sptSet[v] && dist[tu] != INT_MAX && dist[tu] + w < dist[v])
            {
                dist[v] = dist[tu] + w;
            }           
        }
    }

    // δ (u, v) + h (v) - h (u)

    for (int i = 0; i < V; i++)
    {
        dist[i] = dist[i] + h[i] - h[src];
    }
    
    printSolution(dist);
}

// Johnson's algorithm for finding all pairs shortest paths
// main algorithm
void johnsonAlgorithm(struct Graph* graph){
    
    int V = graph->V;
    int E = graph->E;

    vector<int> modifiedWeights = BellmanFord(graph);

    cout << endl;

    for (int i = 0; i < E-V; i++)
    {
        int u = graph->edge[i].src; 
        int v = graph->edge[i].dest; 
        graph->edge[i].weight = graph->edge[i].weight + modifiedWeights[u] - modifiedWeights[v];
    }

    for(int src = 0; src < V; src++){
        cout << "\nShortest distance with vertex " << src << " as the source : \n";
        dijkstra(graph,src,modifiedWeights);
    }
    
}

  
// Driver program to test above functions 
int main() 
{ 
    int V; // Number of vertices in graph 
    int E; // Number of edges in graph 
    cout << "Enter the number of vertices : ";
    cin >> V;
    cout << "Enter the number of edges : ";
    cin >> E;

    // Array of edges for graph
    struct Graph* graph = createGraph(V, E+V);

    //------- adding the edges of the graph
    /*
            edge(u, v)
            where 	u = start vertex of the edge (u,v)
                    v = end vertex of the edge (u,v)
            
            w is the weight of the edge (u,v)
        */

    cout << "Enter the edges with source, destination and weight : \n";

    for (int i = 0; i < E; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        graph->edge[i].src = t1;
        graph->edge[i].dest= t2;
        graph->edge[i].weight = t3;
    }; 
  
    johnsonAlgorithm(graph); 
  
    return 0; 
} 