"""
Depth First Search - DFS

A Graph Traversal Algorithm where the nodes in a graph are visited in a depth-first pattern.
i.e The start or current node is processed and then its adjacent nodes are explored by going deeper into the graph or tree.

Steps
1. Pick a starting node or vertex.
2. Process the node by printing or appending to an array.
3. Mark the node as 'seen' in a set so it doesn't get visited again.
3. For each current node get its adjacent nodes or edges and repeat processes 1, 2 and 3.

Time complexity  is O(N) since we visit every node at least once. N is the number of nodes in the graph.
Space complexity is O(N) since we mark each visited node in a set data structure of size N. 


Sample Graph:

1 - 2 - 5
|   |      
4 - 3         , starting node = 1

DFS of this graph with starting node as 1 gives -> [1,2,5,3,4].
Another variant could be ->  [1,2,3,4,5].
"""

# Test Case
class Graph(object):
    def __init__(self):
        self.nodes = {} # Stores all nodes

    # Method to add a node
    def addNode(self, node):
        self.nodes[node] = []

    # Method to add an edge
    def addEdge(self, edge):
        self.nodes[edge[0]].append(edge[1])

    # Method to view graph (all nodes)
    def peek(self):
        return self.nodes

testGraph = Graph()
nodes = [1, 2, 3, 4,5]
edges = [[1,2], [1,4], [2,5], [2,3],[3,2], [3,4], [4,1], [4,3], [2,1]]

for node in nodes:
    testGraph.addNode(node)

for edge in edges:
    testGraph.addEdge(edge)

# Our graph will now look like this

# testGraph = {
#     1: [2, 4],
#     2: [5, 3, 1],
#     3: [2, 4],
#     4: [1, 3],
#     5: []
# }

# Code Implementation
output = []
seen = set()
currNode = 1

def dfs(currNode):

    if currNode in seen: # Check to see if the current node has been visited.
        return

    output.append(currNode) # Process the node
    seen.add(currNode) # Mark it as seen

    edges = testGraph.nodes[currNode] # Get current node's edges
    for edge in edges:                 # Explore and repeat the process
        dfs(edge)


print(testGraph.nodes)
print(output) # Prints [1,2,5,3,4]

