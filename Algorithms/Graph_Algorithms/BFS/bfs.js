function bfs(at) {
  let queue = [at];
  // mark the first node as visited
  visited[at] = true;
  // adding the first node to the result
  result.push(at)

  // find the node neighbours
  let nodes = adjList.get(at);
  while(queue.length > 0){
    // take the next node to explore
    let node = queue.shift();
    // find the node neighbours
    let nodes = adjList.get(node);
    for(let neigh of nodes){
      if(!visited[neigh]){
        queue.push(neigh);
        // mark the node as visited
        visited[neigh] = true;
        // adding the node to the explored nodes
        result.push(neigh); // or you can do something with the node
      }
    }
  }
}

function addNode(node) {
    // adding the node, at first point to nothing
    adjList.set(node, []);
}

function addEdge(origin, destination) {
    // finding the node origin and set the edge to destination
    adjList.get(origin).push(destination);
    // finding the node destination and set the edge to origin
    adjList.get(destination).push(origin);
}

// T E S T
const nodes = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
const edges = [
    [0, 4],
    [0, 3],
    [3, 2],
    [3, 7],
    [3, 8],
    [5, 4],
    [5, 1],
    [5, 10],
    [5, 6],
    [10, 1],
];

// define a structure to support the graph
let adjList = new Map();

// biulding the nodes of the graph
nodes.forEach(addNode);

// building the edges
edges.forEach(edge => addEdge(...edge));

// building an array for the flag of the visited nodes
let visited = new Array(nodes.length).fill(false);

// traverse starting from node 0
let start_node = 0;
let result = [];
bfs(start_node);
console.log(`the result of traverse the graph from ${start_node} is`, result);