#Created by Timothy Chua
#Implementation of Breadth First Search in Python
#References:
# - https://csacademy.com/app/graph_editor/
# - https://www.tutorialspoint.com/data_structures_algorithms/graph_data_structure.htm



def BFS(graph, point, explored, to_explore):
    if(len(graph) == len(explored)): #If we have explored every possible point
      return explored

    else:
      #We use two lists to track what we've explored and what is there left to explore
      explored.append(point)
      for vertice in graph[point]:
        if(vertice not in explored and vertice not in to_explore): #If the point we encounter isn't explored and not in our to_explore list, we add it.
          to_explore.append(vertice)

      while(len(to_explore) != 0):
        vertice = to_explore.pop(0)
        BFS(graph, vertice, explored, to_explore)


      return explored




if __name__ == "__main__":

    #Let's construct the graph using a dictionary
    #The keys of the dictionary are called vertices of the graph
    #The values of the dictionary are called the edges of the the graph
    graph = { "a" : ["b", "c"],
              "b" : ["a", "d"],
              "c" : ["a", "d"],
              "d" : ["e"],
              "e" : ["d"]
            }

    #Let us start with point a on the graph
    print(BFS(graph, "b", [], []))
