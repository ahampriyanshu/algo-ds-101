class Node{
  int value;
  Node left;
  Node right;
  Node(int value){
    this.value = value;
    left = null;
    right = null;        
  }
}
// Class for Binary Search Tree
class BST{
  Node node;
  BST(int value){
    node = new Node(value);
  }
  public Node insert(Node node, int value){
    if(node == null){
      return new Node(value);
    }
    // Move to left for value less than parent node
    if(value < node.value){
      node.left = insert(node.left, value);
    }
    // Move to right for value greater than parent node
    else if(value > node.value){
      node.right = insert(node.right, value);
    }
    return node;
  }
    
  // For traversing in order
  public void inOrder(Node node){
    if(node != null){
      // recursively traverse left subtree
      inOrder(node.left);
      System.out.print(node.value + " ");
      // recursively traverse right subtree
      inOrder(node.right);
    }
  }
}

public class TreeSort {
  public static void main(String[] args) {
    int[] arr = {65, 68, 82, 42, 10, 75, 25, 47, 32, 72};
    System.out.println("Original array- " + Arrays.toString(arr));
    // start creating tree with element at index 0 as root node
    BST bst = new BST(arr[0]);
    for(int num : arr){
      bst.insert(bst.node, num);
    }
    System.out.print("Sorted Array after Tree sort- ");
    bst.inOrder(bst.node);
    System.out.println();
  }
}
