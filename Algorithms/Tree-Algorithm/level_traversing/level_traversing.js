class Node{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BinarySearchTree{
    constructor(){
        this.root = null;
    }

    getRootNode(){
        return this.root;
    }
 
    insert(data){

        var newNode = new Node(data);
                        
        if(this.root === null)
            this.root = newNode;

        else
            this.insertBST(this.root, newNode);
    }

    insertBST(node, newNode){

        if(newNode.data < node.data){
            if(node.left === null)
                node.left = newNode;
            else
                this.insertBST(node.left, newNode);
        }
    

        else{
            if(node.right === null)
                node.right = newNode;
            else
                this.insertBST(node.right,newNode);
        }
    }

}

function levelOrder(root) {
    if (!root) return []
    let result = []      
    let queue = [root]     
    
    while (queue.length != 0) {  
        const n = queue.length
        
        for (let i = 0; i < n; i++) {
            let node = queue.pop()
            result.push(node.data)
            if (node.left) 
                queue.unshift(node.left);
            if (node.right) 
                queue.unshift(node.right);
        }
    }
    return result;
}

var BST = new BinarySearchTree();
 
// Inserting nodes to the BinarySearchTree
BST.insert(15);
BST.insert(25);
BST.insert(10);
BST.insert(7);
BST.insert(22);
BST.insert(17);
BST.insert(13);
BST.insert(5);
BST.insert(9);
BST.insert(27);

//          15
//         /  \
//        10   25
//       / \   / \
//      7  13 22  27
//     / \    /
//    5   9  17

const root = BST.getRootNode();
console.log(...levelOrder(root));

// Output:

// 15 10 25 7 13 22 27 5 9 17
