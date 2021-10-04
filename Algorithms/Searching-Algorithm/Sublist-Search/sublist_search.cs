/******************************************** 
*  C# program to find a list in second list 
*
*  Author - Ayush Sharma (belphegor-s)
*
*
********************************************/
using System; 

class GFG 
{ 

// A Linked List node 
class Node 
{ 
	public int data; 
	public Node next; 
}; 

// Returns true if first list is 
// present in second list 
static Boolean findList(Node first, 
						Node second) 
{ 
	Node ptr1 = first, ptr2 = second; 

	// If both linked lists are empty, 
	// return true 
	if (first == null && second == null) 
		return true; 

	// Else If one is empty and 
	// other is not, return false 
	if (first == null || 
	(first != null && second == null)) 
		return false; 

	// Traverse the second list by 
	// picking nodes one by one 
	while (second != null) 
	{ 
		// Initialize ptr2 with 
		// current node of second 
		ptr2 = second; 

		// Start matching first list 
		// with second list 
		while (ptr1 != null) 
		{ 
			// If second list becomes empty and 
			// first not then return false 
			if (ptr2 == null) 
				return false; 

			// If data part is same, go to next 
			// of both lists 
			else if (ptr1.data == ptr2.data) 
			{ 
				ptr1 = ptr1.next; 
				ptr2 = ptr2.next; 
			} 

			// If not equal then break the loop 
			else break; 
		} 

		// Return true if first list gets traversed 
		// completely that means it is matched. 
		if (ptr1 == null) 
			return true; 

		// Initialize ptr1 with first again 
		ptr1 = first; 

		// And go to next node of second list 
		second = second.next; 
	} 
	return false; 
} 

/* Function to print nodes 
in a given linked list */
static void printList(Node node) 
{ 
	while (node != null) 
	{ 
		Console.Write("{0} ", node.data); 
		node = node.next; 
	} 
} 

// Function to add new node to linked lists 
static Node newNode(int key) 
{ 
	Node temp = new Node(); 
	temp.data= key; 
	temp.next = null; 
	return temp; 
} 

// Driver Code 
public static void Main(String[] args) 
{ 
	/* Let us create two linked lists to test 
	the above functions. Created lists shall be 
		a: 1->2->3->4 
		b: 1->2->1->2->3->4*/
	Node a = newNode(1); 
	a.next = newNode(2); 
	a.next.next = newNode(3); 
	a.next.next.next = newNode(4); 

	Node b = newNode(1); 
	b.next = newNode(2); 
	b.next.next = newNode(1); 
	b.next.next.next = newNode(2); 
	b.next.next.next.next = newNode(3); 
	b.next.next.next.next.next = newNode(4); 

	if(findList(a, b) == true) 
		Console.Write("LIST FOUND"); 
	else
		Console.Write("LIST NOT FOUND"); 
} 
} 
