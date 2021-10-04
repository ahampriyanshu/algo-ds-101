function dfs(at) {
  // if we have been visited the node then return
  if(visited[at]) return;
  // mark the node as visited
  visited[at] = true;
  
  result.push(at); // or you can do something with the node

  // find the nodes in depth
  let nodes = adjList.get(at);
  for (let neigh of nodes) {
    dfs(neigh);
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
const nodes = [0,1,2,3,4,5,6,7,8,9,10];
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
edges.forEach(edge=>addEdge(...edge));

// building an array for the flag of the visited nodes
let visited = new Array(nodes.length).fill(false);

// traverse starting from node 0
let start_node = 0;
let result = [];
dfs(start_node);
console.log(`the result of traverse the graph from ${start_node} is`, result);