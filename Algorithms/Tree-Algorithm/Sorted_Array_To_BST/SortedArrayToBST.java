class Node {
     
    int data;
    Node left, right;
     
    Node(int d) {
        data = d;
        left = right = null;
    }
}
 
class BinaryTree {
 
    Node sortedArrayToBST(int arr[], int start, int end) {
 
        if (start > end) {
            return null;
        }
 
        /* Get the middle element and make it root */
        int mid = (start + end) / 2;
        Node node = new Node(arr[mid]);
 
        //Construct the left subtree and make it
        //left child of root using recursion
        node.left = sortedArrayToBST(arr, start, mid - 1);
 
        //Construct the right subtree and make it
        //right child of root using recursion
        node.right = sortedArrayToBST(arr, mid + 1, end);
         
        return node;
    }
 
    //Print preorder traversal of BST 
    void preOrder(Node node) {
        if (node == null) {
            return;
        }
        System.out.print(node.data + " ");
        preOrder(node.left);
        preOrder(node.right);
    }
}

public class SortedArrayToBST {

	public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        int arr[] = new int[]{10, 20, 30, 40, 50, 60, 70};
        int n = arr.length;
        Node root = tree.sortedArrayToBST(arr, 0, n - 1);
        
        System.out.println("Preorder traversal of generated BST");
        tree.preOrder(root);
    }
}

/* 
 * Output:
 * 			Preorder traversal of generated BST
 *			40 20 10 30 60 50 70 
 * 
 */
