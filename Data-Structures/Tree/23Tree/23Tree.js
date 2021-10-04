
//  Name: Manav Arora

//BT using Javascript
class BinarySearchTree
{
    constructor()
    {
        // root of a binary seach tree
        this.root = null
    }
    getrootNode()
    {
      return this.root
    }
    
    insert(data)
    {
        var newNode = new Node(data)
        if(this.root == null)
            this.root = newNode
        else
            this.insertNode(this.root, newNode)
    }
      
    insertNode(node, newNode)
    {
        if(newNode.data < node.data)
        {
            // if left is null insert node here
            if(node.left == null)
                node.left = newNode
            else
      
               this.insertNode(node.left, newNode) 
        }
      
        else
        {
            // if right is null insert node here
            if(node.right == null)
                node.right = newNode
            else
      
              this.insertNode(node.right,newNode)
        }
    }
   
    findMinNode(node)
    {
        // if left of a node is null
        // then it must be minimum node
        if(node.left === null)
            return node;
        else
            return this.findMinNode(node.left);
    }
  
    inorder(node)
    {
        //console.log(node.data)
        if(node != null)
        {
            this.inorder(node.left)
            console.log(node.data)
            this.inorder(node.right)
        }
    }
     
}

class Node 
{
    constructor (data, left, right) 
    {
      this.data = data
      this.left = null
      this.right = null
    }
}

const bst=new BinarySearchTree()
var r=new BinarySearchTree()
bst.insert(55)
bst.insert(10)
bst.insert(89)
bst.insert(62)
bst.insert(104)
bst.insert(60)
bst.insert(5)
bst.insert(-10)
bst.insert(20)
r=bst.getrootNode()
console.log("Inorder traversal of tree..")
bst.inorder(r)


/*

Output:

Inorder traversal of tree..
-10
5
10
20
55
60
62
89
104

*/

