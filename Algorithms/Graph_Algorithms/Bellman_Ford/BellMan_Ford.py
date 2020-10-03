#Bellman-Ford Python Implementation
#Complexity : O(|V|*|E|) where V = No. of vertices ; E = No. of edges

class Graph:

	#Initialise the data structure
	def __init__(self, nodes):
		self.nodes = nodes
		self.weighted_edges = []
	
	#Add edges in the form 
	#(u -> 1st vertex, v -> 2nd vertex, weight -> weight of u--v)		
	def createEdge(self, u, v, weight):
		if u>=self.nodes or v>=self.nodes:
			#Taking care of wrong Input
			print("Please enter vertices from 0 to |V|-1")
			exit(0)
		self.weighted_edges.append((u,v,weight))
		
	
		
class Solution:
	
	#Print the shortest distances from src to all vertices
	def printSoln(self, dist, src):
		print("Dist from source : ",src," are as follows")
		for vertex,weight in enumerate(dist):
			print("to vertex : ",vertex," shortest distance is : ",weight)
	
	
	def bellmanFord(self, graph, src):
		#Initialise all distances with infinity and src distance with 0
		dist = [float("inf")]*graph.nodes
		dist[src] = 0
		
		#Update each edge weight by any smaller weighted path possible
		#we do it for |V|-1 times to ensure all edge weights have least possible value
		for i in range(graph.nodes-1):
			
			#Relax all the edges
			for u,v,w in graph.weighted_edges:
				if dist[u] != float("inf") and dist[v] > dist[u] + w:
					dist[v] = dist[u] + w
		
		#After |V|-1 relaxations if again a shorter edge
		#found means a negative cycle encountered
		for u, v, w in graph.weighted_edges:
			if dist[u] != float("inf") and dist[u] + w < dist[v]:  
                        	print("Negative weight cycle detected")
                        	#If negative cycle detected, no solution exists, so return 
                        	return
                #To print the final solution
		self.printSoln(dist, src)
                
if __name__=="__main__":
	
	#Inputs from stdin
	V = int(input("Enter total vertices in graph : "))
	E = int(input("Enter no. of edges : "))
	
	#Create a Graph object with |V| vertices
	g = Graph(V)
	
	#Input and Add edges to the graph object g
	for i in range(E):
		u,v,w = map(int,input("Enter u,v,w subjected to (0-|V|-1,0-|V|-1,Any Integer) values seperated by space : ").split())
		g.createEdge(u, v, w)
		
	#Input Source from which distance is to be calculated
	src = int(input("Select the source : "))
	ans = Solution()
	print("==================================")
	#Call the Bellman Ford algorithm
	ans.bellmanFord(g, src)
                
                
                
                
					
					
		
		
