#Code to get the inorder traversal and to find the lowest common ansester of two given node in binary search tree by user in python


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


def inorder(root):
    if root:
        inorder(root.left)
        print(root.data,end=" ")
        inorder(root.right)

def find_LCA(root,n1,n2):

    if root is None:
        return
    left_data=find_LCA(root.left,n1,n2)
    right_data=find_LCA(root.right,n1,n2)

    if root.data==n1 or root.data==n2:
        return root

    return left_data if left_data is not None else right_data


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
        2. LCA of two node
        3. Quit
        '''))
        if choice==1:
            inorder(root)
        elif choice==2:
            print('Give two node whose LCA you want to find: ')
            m1,m2=map(int,input().split())
            print(find_LCA(root,m1,m2).data)

    print('Have a nice day!')
