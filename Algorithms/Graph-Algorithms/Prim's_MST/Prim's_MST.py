# Prim's Algorithm in Python
#Created by Sneha Sai KNVS(snehaa1989)
#Implementation of Prim's Minimum spanning tree in Python
#References:
# - https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

INF = 9999999
# number of vertices
N = 5
# adjacency matrix to represent graph
G = [[0, 9, 75, 0, 0],
     [9, 0, 95, 19, 42],
     [75, 95, 0, 51, 66],
     [0, 19, 51, 0, 31],
     [0, 42, 66, 31, 0]]
# array to track node that was selected.
selected_node = [0, 0, 0, 0, 0]

no_edge = 0

selected_node[0] = True

# Let's print for edge and weight
print("Edge : Weight\n")
while (no_edge < N - 1):
# For every vertex in the set S, Let's find the all adjacent vertices
# we calculate the distance from the vertex selected and
# if the vertex is already in the set S, leave it otherwise
# choose another vertex nearest to selected vertex.    
    minimum = INF
    a = 0
    b = 0
    for m in range(N):
        if selected_node[m]:
            for n in range(N):
                if ((not selected_node[n]) and G[m][n]):  
                    # not in selected and there is an edge
                    if minimum > G[m][n]:
                        minimum = G[m][n]
                        a = m
                        b = n
    print(str(a) + "-" + str(b) + ":" + str(G[a][b]))
    selected_node[b] = True
    no_edge += 1
