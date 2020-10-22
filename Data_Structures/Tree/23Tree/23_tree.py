class Node(object):
    
    path = []

    def __init__(self, data, parent=None):
        self.childs = {}
        self.data = [data]
        self.parent = parent        

    def insert(self, value):
        Node.path = []
        insert_node = self.search(value)
        insert_node.add(value)

    def split(self):
        if self.parent is None and self.childs:
            branch = Node.path.pop()
            newNodeLeft = Node(self.data.pop(0), self)
            newNodeRight = Node(self.data.pop(1), self)                      
            if branch == "left":
               newNodeLeft.childs["left"] = self.childs["left"]
               newNodeLeft.childs["right"] = self.childs["overflow"]
               newNodeRight.childs["left"] = self.childs["mid"]
               newNodeRight.childs["right"] = self.childs["right"]
            elif branch == "mid":
               newNodeLeft.childs["left"] = self.childs["left"]
               newNodeLeft.childs["right"] = self.childs["mid"]
               newNodeRight.childs["left"] = self.childs["overflow"]
               newNodeRight.childs["right"] = self.childs["right"]
            elif branch == "right":
               newNodeLeft.childs["left"] = self.childs["left"]
               newNodeLeft.childs["right"] = self.childs["mid"]
               newNodeRight.childs["left"] = self.childs["right"]
               newNodeRight.childs["right"] = self.childs["overflow"]
            newNodeLeft.childs["left"].parent = newNodeLeft
            newNodeLeft.childs["right"].parent = newNodeLeft
            newNodeRight.childs["left"].parent = newNodeRight
            newNodeRight.childs["right"].parent = newNodeRight
            self.childs["left"] = newNodeLeft
            self.childs["right"] = newNodeRight
            del self.childs["mid"]

        elif self.parent is not None and self.childs:
            branch = Node.path.pop()
            newNode = Node(self.data.pop(), self.parent)
            self.parent.childs["overflow"] = newNode
            if branch == "left":  
                newNode.childs["left"] = self.childs["mid"]
                newNode.childs["right"] = self.childs["right"]
                self.childs["right"] = self.childs["overflow"]
            elif branch == "mid":
                newNode.childs["left"] = self.childs["overflow"]
                newNode.childs["right"] = self.childs["right"]
                self.childs["right"] = self.childs["mid"]
            elif branch == "right":
                newNode.childs["left"] = self.childs["right"]
                newNode.childs["right"] = self.childs["overflow"]
                self.childs["right"] = self.childs["mid"]
            newNode.childs["left"].parent = newNode
            newNode.childs["right"].parent = newNode
            del self.childs["mid"]

        elif self.parent is None and not self.childs:
            self.childs["left"] = Node(self.data.pop(0), self)
            self.childs["right"] = Node(self.data.pop(1), self)   

        elif self.parent is not None and not self.childs:
            self.parent.childs["overflow"] = Node(self.data.pop(), self.parent) 
            
                
    def add(self, value):
        if value not in self.data:
            self.data.append(value)
            self.data.sort()
            if len(self.data) == 3:
                self.split()
                if self.parent is not None:
                    self.parent.add(self.data.pop())
            else:
                if "overflow" in self.childs:
                    branch = Node.path.pop()
                    if branch == "left":
                        self.childs["mid"] = self.childs["overflow"]
                    elif branch == "right":
                        self.childs["mid"] = self.childs["right"]
                        self.childs["right"] = self.childs["overflow"]
                    del self.childs["overflow"]

    def search(self, value):   
        if self.childs:
            boundLeft = min(self.data)
            boundRight = max(self.data)
            if value < boundLeft:
                Node.path.append("left")
                return self.childs["left"].search(value)
            elif value > boundRight:
                Node.path.append("right")
                return self.childs["right"].search(value)
            else:
                Node.path.append("mid")
                return self.childs["mid"].search(value)
        else:
             return self 

    def element(self, value):
        if value in self.data:
            return True
        elif self.childs:
            boundLeft = min(self.data)
            boundRight = max(self.data)
            if value < boundLeft:
                return self.childs["left"].element(value)
            elif value > boundRight:
                return self.childs["right"].element(value)
            else:
                return self.childs["mid"].element(value)
        else:
            return False
