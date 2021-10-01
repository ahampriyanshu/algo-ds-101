#Code for inorder as well as vertical order traversal of BST in python

class new_node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None

def insert(root,data):
    if root==None:
        return new_node(data)
    else:
        if root.data==data:
            return root
        elif root.data>data:
            root.right=insert(root.right,data)
        elif data>root.data:
            root.left=insert(root.left,data)

    return root

def vertical_line(root,hd,m):
    if root is None:
        return
    try:
        m[hd].append(root.data)
    except:
        m[hd]=[root.data]

    vertical_line(root.left,hd-1,m)
    vertical_line(root.right,hd+1,m)

def print_vertical_order(root):
    m=dict()
    h=0
    vertical_line(root,h,m)
    for ind,val in enumerate(sorted(m)):
        for i in m[val]:
            print(i)
        print()

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data)
        inorder(root.right)


if __name__=='__main__':
    n = int(input('Enter number of node u want in this BST: '))
    x=int(input('Enter data you want to insert in root node: '))
    root=new_node(x)

    for i in range(n-1):
        v=int(input('Data: '))
        insert(root,v)
    choice=0
    while(choice!=3):
        choice=int(input('''
        1. Inorder Traversal of BST
        2. Vertical-order-traversal of BST
        3. Quit
        '''))
        if choice==1:
            inorder(root)
        elif choice==2:
            print_vertical_order(root)

    print('Have a nice day!')
