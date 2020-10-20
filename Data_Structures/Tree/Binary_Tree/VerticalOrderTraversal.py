# submission by liamm91

class TreeNode:
    def __init__(self, val=None, left=None, right=None):
        self._val = val
        self._left = left
        self._right = right

        # determining coords
        self._x = self._y = 0

    def insertNode(self, node):
        if node.val: # if there is a value
            if self.val < node.val: # insert to the right
                if self.right: # node exists
                    self.right.insertNode(node)
                else: # node doesn't exist
                    self.right = node
                    self.right.x = self.x + 1
                    self.right.y = self.y - 1
            else: # insert to the left
                if self.left: # node exists
                    self.left.insertNode(node)
                else: # node doesn't exist
                    self.left = node
                    self.left.x = self.x - 1
                    self.left.y = self.y - 1

    # properties

    @property
    def y(self):
        return self._y

    @y.setter
    def y(self, new_y):
        self._y = new_y

    @property
    def x(self):
        return self._x

    @x.setter
    def x(self, new_x):
        self._x = new_x

    @property
    def left(self):
        return self._left

    @left.setter
    def left(self, left_node):
        self._left = left_node

    @property
    def right(self):
        return self._right

    @right.setter
    def right(self, right_node):
        self._right = right_node
    
    @property
    def val(self):
        return self._val

    @val.setter
    def val(self, new_val):
        self._val = new_val

    def traverse(self):
        if self.left:
            self.left.traverse()
        print(self)
        if self.right:
            self.right.traverse()

    def __str__(self):
        return "Node at x: %d, y: %d with value %d" % (self.x, self.y, self.val)


class BinaryTree:
    def __init__(self, head: TreeNode=None):
        self.head = head
        self.vot = [self.head]

    def insertNode(self, node: TreeNode):
        if not self.head: # if head doesn't exist
            self.head = node
            self.head.x = self.head.y = 0
        else: # head exists
            self.head.insertNode(node)

    def vertical_order_traverse(self):
        self.vot = [self.head] # reinitializing the list incase self.head is None
        def __group_nodes(arr_nodes):
            r = t = [] # init vars
            for node in arr_nodes: # looping thru the array
                if t: # if there are nodes in the temp list
                    if t[0].x == node.x: # if the x pos of the node 
                        t.append(node) # add the node to the temp list
                    else: # if the x pos between the node and list differ
                        for n in t:
                            t[t.index(n)] = n.val # converting nodes into their values
                        r.append((t[0], t)[len(t) > 1]) # adding the temp list to the return array
                        t = [node] # putting the temp list to the new node
                else:
                    t = [node] # putting the temp list to thte new node

            if t: r.append(t[0].val) # if there are left over nodes, convert and add

            return r

        def __getsides(self, node): # recusive function to return all node in the tree
            l, r = node.left, node.right
            if l:
                self.vot.append(l) # appending node to the master list
                __getsides(self, l)
            if r:
                self.vot.append(r) # appending node to the master list
                __getsides(self, r)

        __getsides(self, self.head) # starting recursive function

        # sorting all the nodes
        self.vot.sort(key=lambda node: node.x)
        self.vot = __group_nodes(self.vot)

        # returning vertical traverse order
        return self.vot

def main():
    nums = [3,9,20,1,-5,15,7]
    tree = BinaryTree()
    for num in nums:
        tree.insertNode(TreeNode(num))

    tree.head.traverse()

    print(tree.vertical_order_traverse())

if __name__ == "__main__":
    main()
    