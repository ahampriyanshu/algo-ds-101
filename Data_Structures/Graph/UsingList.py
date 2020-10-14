# graph implementation with adjacency list

# undirected version


class node():
    
    def __init__(self, node_name):
        self.node_name   = node_name # node_name is unique name of node.
        self.has_edge_to = [] # list which records the all edges of this node and their edge weights.
        
    def add_neigbor(self, neighbor): # neighbor is node name. not node object.
        self.has_edge_to.append(neighbor)
        
    def list_edges_of(self):
        return self.has_edge_to
    
    def get_node_name(self):
        return self.node_name
    
    def __str__(self):
        return str(self.node_name)
    

class graph():
    
    def __init__(self):
        self.adj_list_of_graph = {} # keys are node names. values are edge_lists of nodes
        self.node_num_in_graph = 0
        self.nodes_object_list = []
    

    def add_node(self, node_name):
        self.node_num_in_graph += 1
        new_node = node(node_name)
        self.nodes_object_list.append(new_node)
        #self.adj_list_of_graph[new_node.get_node_name()] = new_node.list_edges_of()
        self.update_adj_list()
        return new_node
    
    def get_node(self, node_name_to_search): # return node which its name is node_name_to_search
        for x in self.nodes_object_list:
            if node_name_to_search == x.get_node_name():
                return x
        return None


    def get_edges_of_node(self, node_name_to_search): 
        return self.get_node(node_name_to_search).list_edges_of()
        # return self.adj_list_of_graph[node_name_to_search]
    
    def update_adj_list(self):
        for x in self.nodes_object_list:
            if x.get_node_name() in self.adj_list_of_graph.keys():
                # node is exist in adj list. it is good. lets update its edge list.
                self.adj_list_of_graph[x.get_node_name()] = x.list_edges_of()
            else:
                # we need to cretae new row in adj list for this new node.
                self.adj_list_of_graph[x.get_node_name()] = x.list_edges_of()


    def add_edge(self, from_node, to_node): # in fact from and to notation is meaningless. b/c this is not directed graph. but i use them for convenience to modify.
        # from_node and to_node are node names. not node object 
        self.exist_flag_of_from_node  = False
        self.exist_flag_of_to_node    = False
        for x in self.nodes_object_list:
            if from_node == x.node_name:
                # from_node is exist in graph. no need to create it again.
                self.exist_flag_of_from_node=True

            if to_node == x.node_name:
                # to_node is exist in graph. no need to create it again.
                self.exist_flag_of_to_node=True

        if not self.exist_flag_of_from_node:
            self.add_node(from_node)

        if not self.exist_flag_of_to_node:
            self.add_node(to_node)


        for ii,x in enumerate(self.nodes_object_list):
            if from_node == x.node_name:
                self.nodes_object_list[ii].add_neigbor(to_node)
            if to_node == x.node_name:
                self.nodes_object_list[ii].add_neigbor(from_node)

        self.update_adj_list()
                
        
    def get_all_node_objects_in_graph(self):
        return self.nodes_object_list.keys()
    
    def __iter__(self):
        return iter(self.nodes_object_list)
    
    def __contains__(self, node_name_to_search):
        flag=False
        for x in self.adj_list_of_graph.keys():
            if node_name_to_search == x.node_name:
                flag=True
        
        return flag
        
        

    

##########################################################
#### Breadth First Search (BFS) Algorithm
from queue import Queue

def bfs(graph, entry_node):
    visited = []
    queue   = Queue()
    queue.put(entry_node)
    while not queue.empty():
        node = queue.get()
        if node.get_node_name() not in visited:
            visited.append(node.get_node_name())
            j = graph.get_edges_of_node(node.get_node_name())
            for jj in j:
                if not jj in visited:
                    queue.put(graph.get_node(jj))

    print(queue.empty())
    print(visited)            
    return visited





##########################################################
##### Depth First Search (DFS) Algorithm
def dfs(graph, start):
    visited = [ ]
    stack   = [start] # we will implement stack with python list
    
    while stack: # while stach is not empty
        node = stack.pop()
        if node.get_node_name() not in visited:
            visited.append(node.get_node_name())
            j = graph.get_edges_of_node(node.get_node_name())
            for jj in j:
                if not jj in visited:
                    stack.append(graph.get_node(jj))


    return visited
##########################################################

g_instance_2 = graph()

g_instance_2.add_node("A")
g_instance_2.add_node("B")
g_instance_2.add_node("C")
g_instance_2.add_node("D")
g_instance_2.add_node("E")
g_instance_2.add_node("F")


g_instance_2.add_edge("A","B")
g_instance_2.add_edge("A","C")

#g_instance_2.add_edge("B","A")
g_instance_2.add_edge("B","D")
g_instance_2.add_edge("B","E")

#g_instance_2.add_edge("C","A")
g_instance_2.add_edge("C","F")

#g_instance_2.add_edge("E","B")
g_instance_2.add_edge("E","F")

#g_instance_2.add_edge("F","C")
#g_instance_2.add_edge("F","E")

#print(g_instance_2.adj_list_of_graph)
for v in g_instance_2.adj_list_of_graph:
    print(v,g_instance_2.adj_list_of_graph[v])

visited = bfs(g_instance_2, g_instance_2.get_node("A"))
print("bfs traversal:",visited)

visited = dfs(g_instance_2,g_instance_2.get_node("A"))
print("dfs traversal:", visited)

##########################################################



















