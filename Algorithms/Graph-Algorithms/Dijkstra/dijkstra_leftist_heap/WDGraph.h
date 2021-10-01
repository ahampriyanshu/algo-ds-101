#ifndef _WDGraph_
#define _WDGraph_

#include <iostream>
#include <cstddef>
#include <unordered_map>
#include <vector>

/*
 Implementation of a Weighted Directed Graph using Linked lists.
 Each vertex is represented by VertexNode:
 _elem       contains the value of the given node
 _visited    controls if the visited has been visited by any algorithm
 _nodesPointed controls the nomber of nodes in the list
 _visited	 stores the result of the dijkstra algorithm, true if visited after the algorithm
 _parentOnMinPath stores the parent of the note in the minimum path after dijkstra
 _next       pointer to the next VertexNode in the graph
 _edges      pointer to the first EdgeNode of the Vertex

 Each edge is represented by EdgeNode:
 _src        contains the value from the vertex wich the edge comes out
 _dst        contains the value from the vertex wich the edge goes to
 _weight     contains the cost of traveling trought the given edge
 _next       pointer to the next edge of the given VertexNode

 The complete graph is represented by WDGraph:
 _head       pointer to the first VertexNode in the graph
 */

class EdgeNode {   // Edges

public:
	int _src;
	int _dst;
	float _weight;
	EdgeNode *_next;
	EdgeNode(int src, int dst, float weight, EdgeNode *next);     // Constructor

};

class VertexNode {   // Adyacency list (linked list)

public:
	int _elem;
	float _dist;
	int _nodesPointed;
	bool _visited;
	VertexNode *_parentOnMinPath;
	VertexNode *_next;
	EdgeNode *_edges;
	VertexNode(int elem, VertexNode *next, EdgeNode *edges);    // Constructor

};

class WDGraph {

public:
	VertexNode *_head;
	int _nVertex;
	std::unordered_map<int, VertexNode*> *_map; 	// Stores the current vertex on the graph and a pointer to them in order to insert a new edge in O(1)
	void addEdge(int src, int dst, float weight); 	// Adds an EdgeNode from src to dst with the given weight
	void printGraph(); 								// Prints the adyacency list for the graph
	void printGraphvertices(); 						// Prints all the info of each vertex of the graph
	void getvertices(std::vector<VertexNode*> &ret);// Returns an array with all the vertices of the graph in it
	void changeVertexDistance(int e, float newDist);// Changes the distance attribute of the given node to the desired value
	void changeParent(int e, VertexNode* parent);	// Changes the parent attribute of the given node to the desired value
	void visitVertex(int e);                        // Marks the node as visited
	void getNeightbours(int e, std::vector<EdgeNode*> &ret); // Returns the neightbours oof the given vertex
	int getNumberOfNeightbours(int e); 				// Returns the number of neightbours of the given node
	VertexNode* getVertex(int e); 					// Returns the corresponding node to the given element
	WDGraph();                                      // Constructor

};

#endif
