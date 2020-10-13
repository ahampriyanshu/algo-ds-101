using System; 
using System.Collections; 
using System.Collections.Generic; 

class CheckDuplicateValues 
{ 

	//Function that used HashSet to 
	// find presence of duplicate nodes 
	public static Boolean checkDupUtil(Node root, HashSet<int> s) 
	{ 
		// If tree is empty, there are no 
		// duplicates. 
		if (root == null) 
			return false; 
	
		// If current node's data is already present. 
		if (s.Contains(root.data)) 
			return true; 
	
		// Insert current node 
		s.Add(root.data); 
		
		// Recursively check in left and right 
		// subtrees. 
		return checkDupUtil(root.left, s) || 
				checkDupUtil(root.right, s); 
	} 
	
	public static Boolean checkDup(Node root) 
	{ 
		HashSet<int> s = new HashSet<int>(); 
		return checkDupUtil(root, s); 
	} 

	public static void Main(String []args) 
	{ 
		Node root = new Node(1); 
		root.left = new Node(2); 
		root.right = new Node(2); 
		root.left.left = new Node(3); 
		if (checkDup(root)) 
			Console.Write("Yes"); 
		else
			Console.Write("No"); 
	} 
} 
public class Node 
{ 
	public int data; 
	public Node left, right; 
	public Node(int data) 
	{ 
		this.data = data; 
	} 
}; 
