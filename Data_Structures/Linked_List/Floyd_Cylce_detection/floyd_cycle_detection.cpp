#include<bits/stdc++.h> 
using namespace std;
//Definition for singly-linked list-
struct ListNode {
    int val;
    ListNode *next;
};
//Utility function-
void push(ListNode** head, int new_val) { 
    ListNode* new_node = new ListNode(); 
    new_node->val = new_val;
    //link the old list off the new node-
    new_node->next = (*head);
    //move the head to point to the new node-
    (*head) = new_node; 
}
//Floyd cycle-finding algorithm uses two pointers: fast_ptr (moving two nodes at a time) and slow_ptr (moving one node at a time). 
//The concept used is that if these two pointers meet at any time, then a cycle exists, otherwise it does not.
int isCyclePresent(ListNode* head) {
    //both pointers start at the head node of the list-
    ListNode* slow=head;
    ListNode* fast=head;
    bool cycle=false;                //cycle is not yet detected
    //Floyd Algorithm-
    while(fast!=NULL){
        slow=slow->next;             //move forward one node
        if(fast->next!=NULL)
           fast=fast->next->next;    //move forward two nodes
        else
           fast=NULL;                //reached end of list
        
        if(slow==fast){              //the pointers meet
           cycle=true;
           break;
        }
    }
    if(cycle) 
       return 1;                     //cycle exists
    else
       return 0;                     //cycle doesn't exist
}

int main() { 
    //Start with the empty list
    ListNode* head = NULL;
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 10);
    //making cycle-
    head->next->next->next->next = head;    
    if (isCyclePresent(head)) 
        cout << "Loop found"; 
    else
        cout << "No Loop"; 
    return 0; 
} 
