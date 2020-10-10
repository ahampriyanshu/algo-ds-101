#include<bits/stdc++.h> 
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

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
