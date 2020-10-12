# Creating class deque
class Deque():
    
    # Initializing class
    def __init__(self, data=None):
        self.elements = []
        if(data is not None):
            self.elements = list(data)

    # Appending an item
    def append(self, item):
        self.elements.append(item)

    # Appending an item to the left
    def appendleft(self, item):
        self.elements = [item] + self.elements
    
    # Popping an item
    def pop(self):
        return self.elements.pop()
    
    # Popping item from the left
    def popleft(self):
        return self.elements.pop(0)
    
    # Searching for item in range
    def index(self, item, start, stop):
        for i in range(start, min(stop, len(self.elements))):
            if(item == self.elements[i]):
                return i
    
    # Inserting item at index
    def insert(self,idx,item):
        self.elements = self.elements[:idx] + [item] + self.elements[idx:]
    
    # Removing item
    def remove(self, item):
        self.elements.remove(item)

    # Counting occurence of an item
    def count(self, item):
        counter = 0
        for i in self.elements:
            if(i == item):
                counter+=1
        return counter

    # Extending
    def extend(self, list_2):
        list_2 = list(list_2)
        self.elements += list_2
        
    # Extending to the left    
    def extendleft(self, list_2):
        list_2 = list(list_2)
        self.elements = list_2[::-1] + self.elements
    
    # Rotating deque
    def rotate(self,idx):
        self.elements = self.elements[-idx:] + self.elements[:-idx]
        
    # Clearing the deque
    def clear(self):
        self.elements.clear()
    
    # Creating a copy
    def copy(self):
        return Deque(self.elements)

    # Returning a string version
    def __str__(self):
        return str(self.elements)
    
    # Returning iterable
    def __iter__(self):
        for item in self.elements:
            yield item


if __name__ == "__main__":
    x = Deque([2,3])
    print("x:", x)
    x.appendleft(1)
    print("Appending 1 to the left:", x)
    x.append(4)
    print("Appending 4:", x)
    print("Popping element:\n", x.pop(), x)
    print("Popping first element:\n", x.popleft(), x)
    y = Deque([1,2,3,4,5,6,7,8,9])
    print("y:", y)
    y.insert(0,0)
    print("Inserting 0 at position 0:", y)
    y.insert(10,10)
    print("Inserting 10 at position 10:", y)
    print("Index of 4:", y.index(4,0,100))
    y.remove(10)
    print("After removing 10",y)
    y.extendleft(x)
    print("Extending x to the left:", y)
    y.extend([4,4,4])
    print("Extending [4,4,4]:", y)
    y.rotate(2)
    print("Rotating by 2", y)
    y.rotate(-2)
    print("Rotating by -2", y)
    y.clear()
    print("Cleared y:",y)
    z = x.copy()
    print("Creating copy of x:",z)
    z.append(12345)
    print("After appending 12345 to z:", z)
    print("x:",x,"z:",z)