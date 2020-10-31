# Python3 program for Bidirectional BFS 
# Search to check path between two vertices

# Class definition for node to
# be added to graph
class AdjacentNode:
	
	def __init__(self, vertex):
		
		self.vertex = vertex
		self.next = None

# BidirectionalSearch implementation
class BidirectionalSearch:
	
	def __init__(self, vertices):
		
		# Initialize vertices and
		# graph with vertices
		self.vertices = vertices
		self.graph = [None] * self.vertices
		
		# Initializing queue for forward 
		# and backward search
		self.src_queue = list()
		self.dest_queue = list()
		
		# Initializing source and 
		# destination visited nodes as False
		self.src_visited = [False] * self.vertices
		self.dest_visited = [False] * self.vertices
		
		# Initializing source and destination 
		# parent nodes
		self.src_parent = [None] * self.vertices
		self.dest_parent = [None] * self.vertices
		
	# Function for adding undirected edge 
	def add_edge(self, src, dest):
		
		# Add edges to graph
		
		# Add source to destination
		node = AdjacentNode(dest)
		node.next = self.graph[src]
		self.graph[src] = node

		# Since graph is undirected add
		# destination to source
		node = AdjacentNode(src)
		node.next = self.graph[dest]
		self.graph[dest] = node
		
	# Function for Breadth First Search 
	def bfs(self, direction = 'forward'):
		
		if direction == 'forward':
			
			# BFS in forward direction
			current = self.src_queue.pop(0)
			connected_node = self.graph[current]
			
			while connected_node:
				vertex = connected_node.vertex
				
				if not self.src_visited[vertex]:
					self.src_queue.append(vertex)
					self.src_visited[vertex] = True
					self.src_parent[vertex] = current
					
				connected_node = connected_node.next
		else:
			
			# BFS in backward direction
			current = self.dest_queue.pop(0)
			connected_node = self.graph[current]
			
			while connected_node:
				vertex = connected_node.vertex
				
				if not self.dest_visited[vertex]:
					self.dest_queue.append(vertex)
					self.dest_visited[vertex] = True
					self.dest_parent[vertex] = current
					
				connected_node = connected_node.next
				
	# Check for intersecting vertex 
	def is_intersecting(self):
		
		# Returns intersecting node 
		# if present else -1
		for i in range(self.vertices):
			if (self.src_visited[i] and
				self.dest_visited[i]):
				return i
				
		return -1

	# Print the path from source to target 
	def print_path(self, intersecting_node, 
				src, dest):
						
		# Print final path from 
		# source to destination
		path = list()
		path.append(intersecting_node)
		i = intersecting_node
		
		while i != src:
			path.append(self.src_parent[i])
			i = self.src_parent[i]
			
		path = path[::-1]
		i = intersecting_node
		
		while i != dest:
			path.append(self.dest_parent[i])
			i = self.dest_parent[i]
			
		print("*****Path*****")
		path = list(map(str, path))
		
		print(' '.join(path))
	
	# Function for bidirectional searching 
	def bidirectional_search(self, src, dest):
		
		# Add source to queue and mark 
		# visited as True and add its
		# parent as -1
		self.src_queue.append(src)
		self.src_visited[src] = True
		self.src_parent[src] = -1
		
		# Add destination to queue and
		# mark visited as True and add 
		# its parent as -1
		self.dest_queue.append(dest)
		self.dest_visited[dest] = True
		self.dest_parent[dest] = -1

		while self.src_queue and self.dest_queue:
			
			# BFS in forward direction from
			# Source Vertex
			self.bfs(direction = 'forward')
			
			# BFS in reverse direction 
			# from Destination Vertex
			self.bfs(direction = 'backward')
			
			# Check for intersecting vertex
			intersecting_node = self.is_intersecting()
			
			# If intersecting vertex exists
			# then path from source to 
			# destination exists
			if intersecting_node != -1:
				print(f"Path exists between {src} and {dest}")
				print(f"Intersection at : {intersecting_node}")
				self.print_path(intersecting_node, 
								src, dest)
				exit(0)
		return -1

# Driver code
if __name__ == '__main__':
	
	# Number of Vertices in graph
	n = 15
	
	# Source Vertex
	src = 0
	
	# Destination Vertex
	dest = 14
	
	# Create a graph
	graph = BidirectionalSearch(n)
	graph.add_edge(0, 4)
	graph.add_edge(1, 4)
	graph.add_edge(2, 5)
	graph.add_edge(3, 5)
	graph.add_edge(4, 6)
	graph.add_edge(5, 6)
	graph.add_edge(6, 7)
	graph.add_edge(7, 8)
	graph.add_edge(8, 9)
	graph.add_edge(8, 10)
	graph.add_edge(9, 11)
	graph.add_edge(9, 12)
	graph.add_edge(10, 13)
	graph.add_edge(10, 14)
	
	out = graph.bidirectional_search(src, dest)
	
	if out == -1:
		print(f"Path does not exist between {src} and {dest}")
  
