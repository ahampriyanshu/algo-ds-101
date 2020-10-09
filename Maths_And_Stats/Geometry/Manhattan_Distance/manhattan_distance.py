# function to calculate Manhattan Distance between two points
def manhattan_dist(x1, y1, x2, y2):
    return abs(x1-x2) + abs(y1-y2)

x1, y1 = (list(map(int, input("Enter the first point (x,y): ").split(","))))
x2, y2 = (list(map(int, input("Enter the second point (x,y): ").split(","))))
print("Manhattan Distance: ", manhattan_dist(x1, y1, x2, y2))