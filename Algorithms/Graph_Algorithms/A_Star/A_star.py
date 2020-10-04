class Node:
    def __init__(self, position:(), parent:()):
        self.position = position
        self.parent = parent
        self.g = 0 
        self.h = 0 
        self.f = 0 
    def __eq__(self, other):
        return self.position == other.position
    def __lt__(self, other):
         return self.f < other.f

    def __repr__(self):
        return ('({0},{1})'.format(self.position, self.f))

def draw_grid(map, width, height, spacing=2, **kwargs):
    for y in range(height):
        for x in range(width):
            print('%%-%ds' % spacing % draw_tile(map, (x, y), kwargs), end='')
        print()

def draw_tile(map, position, kwargs):
    
    value = map.get(position)
   
    if 'path' in kwargs and position in kwargs['path']: value = '+'
    if 'start' in kwargs and position == kwargs['start']: value = '@'
    if 'goal' in kwargs and position == kwargs['goal']: value = '$'
   
    return value 

def astar_search(map, start, end):
    
    open = []
    closed = []
    
    start_node = Node(start, None)
    goal_node = Node(end, None)

    open.append(start_node)
  
    while len(open) > 0:
      
        open.sort()

        current_node = open.pop(0)
     
        closed.append(current_node)
    
        if current_node == goal_node:
            path = []
            while current_node != start_node:
                path.append(current_node.position)
                current_node = current_node.parent
            return path[::-1]
       
        (x, y) = current_node.position

        neighbors = [(x-1, y), (x+1, y), (x, y-1), (x, y+1)]

        for next in neighbors:
     
            map_value = map.get(next)

            if(map_value == '#'):
                continue
            neighbor = Node(next, current_node)
            if(neighbor in closed):
                continue
      
            neighbor.g = abs(neighbor.position[0] - start_node.position[0]) + abs(neighbor.position[1] - start_node.position[1])
            neighbor.h = abs(neighbor.position[0] - goal_node.position[0]) + abs(neighbor.position[1] - goal_node.position[1])
            neighbor.f = neighbor.g + neighbor.h
        
            if(add_to_open(open, neighbor) == True):
    
                open.append(neighbor)

    return None

def add_to_open(open, neighbor):
    for node in open:
        if (neighbor == node and neighbor.f >= node.f):
            return False
    return True
def main():
    map = {}
    chars = ['c']
    start = None
    end = None
    width = 0
    height = 0
    fp = open('data\\maze.in', 'r')
    
    while len(chars) > 0:
        chars = [str(i) for i in fp.readline().strip()]
        width = len(chars) if width == 0 else width
        for x in range(len(chars)):
            map[(x, height)] = chars[x]
            if(chars[x] == '@'):
                start = (x, height)
            elif(chars[x] == '$'):
                end = (x, height)

        if(len(chars) > 0):
            height += 1
    fp.close()

    path = astar_search(map, start, end)
    print()
    print(path)
    print()
    draw_grid(map, width, height, spacing=1, path=path, start=start, goal=end)
    print()
    print('Steps to goal: {0}'.format(len(path)))
    print()
if __name__ == "__main__": main()
