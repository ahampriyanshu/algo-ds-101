// Depth First Search
// C Programming

#include <stdio.h>
#include <stdlib.h>

// Node -> A structure with a vertex and a link to the next Node.
struct Node {
  int vertex;
  struct Node* nextNode;
};

// Graph       -> A structure to represent a Graph.
// numVertices -> Number of Vertices.
// visited     -> Visited Nodes List 
// adjLists    -> To store an array of Linked lists
struct Graph {
  int numVertices;
  int* visited;
  struct Node** adjLists;
};

// Function name : createNode
// Input         : int v
// Output        : struct* Node
// Logic         : For creating a new Node by allocating memory for it.
struct Node* createNode(int v) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->vertex = v;
  newNode->nextNode = NULL;
  return newNode;
}

// Function name : DFS
// Input         : Graph graph, int vertex
// Output        : void
// Logic         : For implementing the Depth First Search Algorithm.
void DFS(struct Graph* graph, int vertex) {
  struct Node* adjList = graph->adjLists[vertex];
  struct Node* temp = adjList;

  graph->visited[vertex] = 1;
  printf("Visited %d \n", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->nextNode;
  }
}



// Function name : createGraph
// Input         : int vertices
// Output        : struct Graph
// Logic         : For creating Graphs.
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct Node*));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

// Function name : addEdge
// Input         : struct Graph, int src, int dest
// Output        : void
// Logic         : For adding an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct Node* newNode = createNode(dest);
  newNode->nextNode = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->nextNode = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

// Function name : printGraph
// Input         : struct Graph
// Output        : void
// Logic         : For printing the Graph.
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct Node* temp = graph->adjLists[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->nextNode;
    }
    printf("\n");
  }
}

int main() {
    int nVertices, nEdges, srcNode, destNode, vertex;

    printf("\nNumber of vertices : ");
    scanf("%d", &nVertices);

    struct Graph* graph = createGraph(nVertices);
    
    printf("\nNumber of edges : ");
    scanf("%d", &nEdges);

    for(int i=0; i<nEdges; i++){
        printf("Edge : ");
        scanf("%d %d", &srcNode, &destNode);
        addEdge(graph, srcNode, destNode);
    }

    printGraph(graph);

    printf("\nVertex to search for : ");
    scanf("%d", &vertex);

    DFS(graph, vertex);

    return 0;
}