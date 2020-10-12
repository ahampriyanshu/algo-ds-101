#include<stdio.h>
#include<stdlib.h>

// structure of node
typedef struct Node 
{
	struct Node *next;
	int data;
} NODE;

// insert a new node at the beginning of the linked list
NODE *insert(NODE* head, int val)
{
	NODE *p = (NODE *)malloc(sizeof(NODE));
	p->data = val;
	p->next = (head == NULL) ? NULL : head;
	return head = p;
}

// reverse the linked list
NODE *reverse(NODE *head)
{
	NODE *p, *q, *r;
	p = NULL;
	q = head;
	while(q != NULL)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	return p;
}

// print the linked list
void print_(NODE *head)
{
	if(head == NULL)
	{
		printf("\n");
		return;
	}
	printf("%d ", head->data);
	print_(head->next);
}

int main()
{
	NODE *head = NULL;
	// inserting nodes in the linked list
	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 4);
	head = insert(head, 5);
	// printing the original linked list
	print_(head);				// Output 5 4 3 2 1
	// invoking the reverse head function
	NODE *revHead = reverse(head);
	// printing the reversed linked list
	print_(revHead);			// Output 1 2 3 4 5
	return 0;
}
