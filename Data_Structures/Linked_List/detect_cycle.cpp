// Program to detect loop in a linked list 
#include <bits/stdc++.h> 
using namespace std; 

// trivial node definition
class Node { 
public: 
	int data; 
	Node* next; 
}; 

// helper function to create a linked list
void push(Node** head_ref, int new_data) 
{ 
	// allocate memory
	Node* new_node = new Node(); 

	new_node->data = new_data; 

  // add new node to the beginning of the list
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

// main function which implements Floyd's algo
bool detectLoop(Node* list) 
{ 
	Node *slow_p = list, *fast_p = list; 

  // iterate until either pointer is null or faster pointer reaches null
	while (slow_p && fast_p && fast_p->next) { 
    // move slow pointer by one and fast pointer by two steps
		slow_p = slow_p->next; 
		fast_p = fast_p->next->next; 
    
    // check if the two pointers are same anywhere
		if (slow_p == fast_p) { 
			return true; 
		} 
	} 
	return false; 
} 


int main() 
{ 
  // Driver code taken from GFG
	/* Start with the empty list */
	Node* head = NULL; 

	push(&head, 20); 
	push(&head, 4); 
	push(&head, 15); 
	push(&head, 10); 

	/* Create a loop for testing */
	head->next->next->next->next = head; 
	if (detectLoop(head)) 
		cout << "Loop found"; 
	else
		cout << "No Loop"; 
	return 0; 
} 

// This is code is contributed by rathbhupendra 
