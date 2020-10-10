class Node 
{ 
	int data; 
	Node left, right; 

	public Node(int data) 
	{ 
		this.data = data; 
		left = right = null; 
	} 
} 

// Class to implement pass by reference of size 
class Size 
{ 
	// variable to calculate size of tree 
	int size = 0; 
} 

public class Density 
{ 
	Node root; 

	// Function to compute height and 
	// size of a binary tree 
	int heighAndSize(Node node, Size size) 
	{ 
		if (node == null) 
			return 0; 

		// compute height of each subtree 
		int l = heighAndSize(node.left, size); 
		int r = heighAndSize(node.right, size); 

		//increase size by 1 
		size.size++; 

		//return larger of the two 
		return (l > r) ? l + 1 : r + 1; 
	} 

	//function to calculate density of a binary tree 
	float density(Node root) 
	{ 
		Size size = new Size(); 
		if (root == null) 
			return 0; 
				
		// Finds height and size 
		int _height = heighAndSize(root, size); 

		return (float) size.size / _height; 
	} 

	// Driver code to test above methods 
	public static void main(String[] args) 
	{ 
		Density tree = new Density(); 
		tree.root = new Node(1); 
		tree.root.left = new Node(2); 
		tree.root.right = new Node(3); 

		System.out.println("Density of given Binary Tree is : "
				+ tree.density(tree.root)); 
	} 

} 
