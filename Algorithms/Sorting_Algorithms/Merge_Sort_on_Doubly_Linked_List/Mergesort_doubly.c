#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{ 
    int data; 
    struct Node *next, *prev; 
}; 
  
struct Node *split(struct Node *head); 
  
// Function to merge two linked lists 
struct Node *merge(struct Node *first, struct Node *second) 
{ 
    // If first linked list is empty 
    if (!first) 
        return second; 
  
    // If second linked list is empty 
    if (!second) 
        return first; 
  
    // Pick the smaller value 
    if (first->data < second->data) 
    { 
        first->next = merge(first->next,second); 
        first->next->prev = first; 
        first->prev = NULL; 
        return first; 
    } 
    else
    { 
        second->next = merge(first,second->next); 
        second->next->prev = second; 
        second->prev = NULL; 
        return second; 
    } 
} 
  
// Function to do merge sort 
struct Node *mergeSort(struct Node *head) 
{ 
    if (!head || !head->next) 
        return head; 
    struct Node *second = split(head); 
  
    // Recur for left and right halves 
    head = mergeSort(head); 
    second = mergeSort(second); 
  
    // Merge the two sorted halves 
    return merge(head,second); 
} 
  
// A utility function to insert a new node at the 
// beginning of doubly linked list 
void insert(struct Node **head, int data) 
{ 
    struct Node *temp = 
        (struct Node *)malloc(sizeof(struct Node)); 
    temp->data = data; 
    temp->next = temp->prev = NULL; 
    if (!(*head)) 
        (*head) = temp; 
    else
    { 
        temp->next = *head; 
        (*head)->prev = temp; 
        (*head) = temp; 
    } 
} 
  
// A utility function to print a doubly linked list in 
// both forward and backward directions 
void print(struct Node *head) 
{ 
    struct Node *temp = head; 
    printf("Forward Traversal using next poitner\n"); 
    while (head) 
    { 
        printf("%d ",head->data); 
        temp = head; 
        head = head->next; 
    } 
    printf("\nBackward Traversal using prev pointer\n"); 
    while (temp) 
    { 
        printf("%d ", temp->data); 
        temp = temp->prev; 
    } 
} 
  
// Utility function to swap two integers 
void swap(int *A, int *B) 
{ 
    int temp = *A; 
    *A = *B; 
    *B = temp; 
} 
  
// Split a doubly linked list (DLL) into 2 DLLs of 
// half sizes 
struct Node *split(struct Node *head) 
{ 
    struct Node *fast = head,*slow = head; 
    while (fast->next && fast->next->next) 
    { 
        fast = fast->next->next; 
        slow = slow->next; 
    } 
    struct Node *temp = slow->next; 
    slow->next = NULL; 
    return temp; 
} 
  
// Driver program 
int main(void) 
{ 
    struct Node *head = NULL; 
    insert(&head,5); 
    insert(&head,20); 
    insert(&head,4); 
    insert(&head,3); 
    insert(&head,30); 
    insert(&head,10); 
    head = mergeSort(head); 
    printf("\n\nLinked List after sorting\n"); 
    print(head); 
    return 0; 
}