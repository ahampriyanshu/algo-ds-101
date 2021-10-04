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
		
		Scanner sc = new Scanner(System.in);

			BinaryTree tree = new BinaryTree();

			System.out.println("Please Enter the Size of the Array:");
			int n = sc.nextInt();

		int arr[] = new int[n];

		for(int i=0; i<n; i++) {
			System.out.println("Enter Array element " + (i+1) + ": ");
			arr[i] = sc.nextInt();
		}

		System.out.println("\nProcessing Array....");
		Arrays.sort(arr);
		System.out.printf("Sorted Array -> %s \n", Arrays.toString(arr));

		System.out.println("\nGenerating BST from Sorted Array....");
		Node root = tree.sortedArrayToBST(arr, 0, n - 1);

		System.out.println("\nPreorder traversal of generated BST");
		tree.preOrder(root);
    }
}

/* 
 * OUTPUT=>
 * 
 *  Please Enter the Size of the Array:
 *	6
 *	Enter Array element 1: 
 *	46
 *	Enter Array element 2: 
 *	88
 *	Enter Array element 3: 
 *	15
 *	Enter Array element 4: 
 *	76
 *	Enter Array element 5: 
 *	31
 *	Enter Array element 6: 
 *	62
 *	
 *	Processing Array....
 *	Sorted Array -> [15, 31, 46, 62, 76, 88] 
 *	
 *	Generating BST from Sorted Array....
 *	
 *	Preorder traversal of generated BST
 *	46 15 31 76 62 88  
 * 
 */

