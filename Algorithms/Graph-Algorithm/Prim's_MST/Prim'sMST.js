/*-----------------------------------------------------------------------------------------------
                                         PRIM'S MST IN JAVASCRIPT
---------------------------------------------------------------------------------------------------*/ 
function primsMST(){
    // Initialize graph that'll contain the MST
    const MST = new Graph();
    if (this.nodes.length === 0) {
       return MST;
    }
 
 
    // Select first node as starting node
    let s = this.nodes[0];
 
 
    // Creating a Priority Queue and explored set
    let edgeQueue = new PriorityQueue(this.nodes.length * this.nodes.length);
    let explored = new Set();
    explored.add(s);
    MST.addNode(s);
 
 
    // Adding all edges from this starting node to the PQ taking weights as priority
    this.edges[s].forEach(edge => {
       edgeQueue.enqueue([s, edge.node], edge.weight);
    });
 
 
    // Taking the smallest edge and add that to the new graph
    let currentMinEdge = edgeQueue.dequeue();
    while (!edgeQueue.isEmpty()) {
 
 
       // Continue removing edges till we get an edge with an unexplored node
       while (!edgeQueue.isEmpty() && explored.has(currentMinEdge.data[1])) {
          currentMinEdge = edgeQueue.dequeue();
       }
       let nextNode = currentMinEdge.data[1];
 
 
       // Checking again as queue might get empty without giving back unexplored element
       if (!explored.has(nextNode)) {
          MST.addNode(nextNode);
          MST.addEdge(currentMinEdge.data[0], nextNode, currentMinEdge.priority);
          // Again add all edges to the PQ
          this.edges[nextNode].forEach(edge => {
             edgeQueue.enqueue([nextNode, edge.node], edge.weight);
          });
 
 
          // Marking this node as explored explored.add(nextNode);
          s = nextNode;
       }
    }
    return MST;
 }

 //Written by Lalit Kumar