/*
	Author : adi1212
*/

/*Problem Statement : 

Implement In-order Threaded Binary Tree and traverse it in In-order and Pre-order*/

#include<bits/stdc++.h> 
using namespace std; 


//Structure of the Threaded Binary Tree
struct TBT_nd 
{ 
   int data; 
   TBT_nd *left; 
   TBT_nd *right; 
   int th_left; 
   int th_right; 
} *head; 

TBT_nd *insert(TBT_nd *root, TBT_nd *temp) //Inserting node in Threaded Binary Tree
{ 
   if(head->left==head && head->right==head) 
   { 
       temp->left=head; 
       temp->right=head; 
       head->left=temp; 
       head->th_left=1; 
       root=temp; 
       return root; 
   } 
   TBT_nd *curr=root; 
   if(temp->data < curr->data) 
   { 
       if(curr->th_left==0) 
       { 
           temp->left=curr->left; 
           curr->left=temp; 
           temp->right=curr; 
           curr->th_left=1; 
       } 
       else 
       { 
           insert(curr->left,temp); 
       } 
   } 
   else if(temp->data > curr->data) 
   { 
       if(curr->th_right==0) 
       { 
           temp->right=curr->right; 
           curr->right=temp; 
           temp->left=curr; 
           curr->th_right=1; 
       } 
       else 
       { 
           insert(curr->right,temp); 
       } 
   } 
   return root; 
} 

TBT_nd *new_nd() 
{ 
   TBT_nd *temp=new TBT_nd; 
   cout<<"ENTER DATA : "; 
   cin>>temp->data; 
   temp->left=NULL; 
   temp->right=NULL; 
   temp->th_left=0; 
   temp->th_right=0; 
   return temp; 
} 

TBT_nd *create(TBT_nd *root) //Create the node in Threaded Binary Tree
{ 
   int ch; 
   TBT_nd *temp; 
   if(root==NULL) 
   { 
       head=new TBT_nd; 
       head->data=9999; 
       head->left=head; 
       head->right=head; 
       head->th_right=1; 
       head->th_left=0; 
       root=head; 
   } 
   do 
   { 
       temp=new_nd(); 
       if(root!=NULL) 
       { 
           root=insert(root,temp); 
       } 
       cout<<"do you want to insert more nodes?? (enter 1 to continue)\n"; 
       cin>>ch; 
   } 
   while(ch==1); 
   return root; 
} 

TBT_nd *pre_suc(TBT_nd *t) //Predecessor of the node
{ 
   if(t->th_left==1) 
       return(t->left); 
   while(t->th_right==0) 
       t=t->right; 
   return(t->right); 

} 

void TBTpreoder(TBT_nd *root) //Preoder Traversal in Threaded BT
{ 
   TBT_nd *p=root; 
   while(p!=head) 
   { 
       cout<<p->data<<"\t"; 
       p=pre_suc(p); 
   } 
} 

TBT_nd *in_suc(TBT_nd *t) //Successor of the node 
{ 
   if(t->th_right==0) 
       return (t->right); 
   t=t->right; 
   while(t->th_left==1) 
       t=t->left; 
   return(t); 
} 

void TBTinoder(TBT_nd *root) //Inoder Traversal in Threaded BT
{ 
   TBT_nd *p=root; 
   while(p->th_left==1) 
   { 
       p=p->left; 
   } 
   while(p!=head) 
   { 
       cout<<p->data<<"\t"; 
       p=in_suc(p); 
   } 
} 

int main() //Main function
{ 
   TBT_nd *root=NULL; 
   int n; 
   cout<<"INORDER THREADED BINARY TREE !"; 
   do 
   { 
       cout<<"\n[1] CREATE (Or insert node in existing tree)?\n"; 
       cout<<"[2] INORDER TRAVERSE?\n"; 
       cout<<"[3] PREORDER TRAVERSE?\n"; 
       cout<<"\nEnter your choice: (enter 0 to exit)"; 
       cin>>n; 
       if(n==1) 
       { 
           root=create(root); 
       } 
       else if(n==2) 
       { 
           cout<<"INORDER TRAVERSAL: \n"; 
           TBTinoder(root); 
       } 
       else if(n==3) 
       { 
           cout<<"PREORDER TRAVERSAL: \n"; 
           TBTpreoder(root); 
       } 
   } 
   while(n!=0); 
   cout<<"\nOPERATION COMPLETED!! THANK YOU"; 
   return 0; 
}


/*
-----------------------------------------------------------------------------------------------------------------------------
OUTPUT : 

INORDER THREADED BINARY TREE !
[1] CREATE (Or insert node in existing tree)?
[2] INORDER TRAVERSE?
[3] PREORDER TRAVERSE?

Enter your choice: (enter 0 to exit)1
ENTER DATA : 10
do you want to insert more nodes?? (enter 1 to continue)
1
ENTER DATA : 6
do you want to insert more nodes?? (enter 1 to continue)
1
ENTER DATA : 13
do you want to insert more nodes?? (enter 1 to continue)
1
ENTER DATA : 15
do you want to insert more nodes?? (enter 1 to continue)
1
ENTER DATA : 7
do you want to insert more nodes?? (enter 1 to continue)
1
ENTER DATA : 20
do you want to insert more nodes?? (enter 1 to continue)
1
ENTER DATA : 2
do you want to insert more nodes?? (enter 1 to continue)
1
ENTER DATA : 3
do you want to insert more nodes?? (enter 1 to continue)
0

[1] CREATE (Or insert node in existing tree)?
[2] INORDER TRAVERSE?
[3] PREORDER TRAVERSE?

Enter your choice: (enter 0 to exit)2
INORDER TRAVERSAL: 
2       3       6       7       10      13      15      20
[1] CREATE (Or insert node in existing tree)?
[2] INORDER TRAVERSE?
[3] PREORDER TRAVERSE?

Enter your choice: (enter 0 to exit)3
PREORDER TRAVERSAL: 
10      6       2       3       7       13      15      20
[1] CREATE (Or insert node in existing tree)?
[2] INORDER TRAVERSE?
[3] PREORDER TRAVERSE?

Enter your choice: (enter 0 to exit)0

OPERATION COMPLETED!! THANK YOU

...Program finished with exit code 0
Press ENTER to exit console.
*/
