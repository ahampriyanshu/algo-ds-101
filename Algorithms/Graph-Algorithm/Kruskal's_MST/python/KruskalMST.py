# Python program for Kruskal's algorithm to find
# Minimum Spanning Tree of a given connected,
# undirected and weighted graph
def takeInput():
    """
    Takes input from stdin
    :return: Graph
    """
    v = int(input("Enter the number of vertices \t"))
    e = int(input("Enter the number of edges \t "))
    edges = []
    for i in range(e):
        print("Enter edge {} in form u v w".format(str(i+1)))
        inputEdge = list(map(int, input().split(" ")))
        edges.append(inputEdge)
    graph = Graph(v,edges)
    return graph


class Graph:
    def __init__(self, vertices,graph ):
        """
        constructor for the graph object
        :param vertices:  No of vertices
        :param graph: dictionary used to store the graph
        # Graph is stored as a list of tuples [(u,v,w)]
        """
        self.V = vertices
        self.graph = graph

    def find(self, parent, i):
        """
        Finds the parent or representative element
        :param parent: Array storing current belongingness of the vertices
        :param i: vertex whose parent is to be found
        :return: parent vertex
        """
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])

    def union(self, parent, rank, x, y):
        """
        union by rank of two sets of x and y
        :param parent: array storing current belongingness of the vertices
        :param rank: array storing current rank of the vertices (used to find the rank of parent)
        :param x: set x
        :param y: set y
        :return:
        """
        xroot = self.find(parent, x)
        yroot = self.find(parent, y)

        # Attach smaller rank tree under root of high rank tree (Union by Rank)
        if rank[xroot] < rank[yroot]:
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot]:
            parent[yroot] = xroot
        else:
            # If ranks are same, then make one as root
            # and increment its rank by one
            parent[yroot] = xroot
            rank[xroot] += 1


    def KruskalMST(self):
        """
        main function construct MST using Kruskal's Algo
        :return: List of edges in the MST
        """

        result = []  # This will store the resultant MST

        i = 0  # An index variable, used for sorted edges
        e = 0  # An index variable, used for result[]

        # Sorting all the edges in non-decereasing order of the weights
        self.graph = sorted(self.graph, key=lambda item: item[2])

        parent = []
        rank = []

        # Create V subsets with single elements
        for node in range(self.V):
            parent.append(node)
            rank.append(0)

        # Number of edges to be taken is equal to V-1
        while e < self.V - 1:

            # Pick the smallest edge and increment
            # the index for next iteration
            u, v, w = self.graph[i]
            i = i + 1
            x = self.find(parent, u)
            y = self.find(parent, v)

            # If including this edge does't cause cycle,
            # include it in result and increment the index
            # of result for next edge
            if x != y:
                e = e + 1
                result.append([u, v, w])
                self.union(parent, rank, x, y)
            # Else discard the edge
            else:
                continue

        # print the contents of result[] to display the built MST
        print("Edges in the MST are as follows ")
        print("Source \t-> Destination \t| Weight")
        for u, v, weight in result:
            print("%d \t-> %d \t\t|  %d" % (u, v, weight))


graph = takeInput()
graph.KruskalMST()
