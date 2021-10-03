// Author : Sachin19k
// Topic: Binary Search Tree 

/* Problem Statement : 
Implement binary search tree and perform following operations:
a) Insert (Handle insertion of duplicate entry)
b) Delete
c) Search
d) Display tree Traversal (Recursive & Non-recursive)
e) Display - Depth of tree
f) Display - Mirror image
g) Create a copy
h) Display all parent nodes with their child nodes
i) Display leaf nodes
j) Display tree level wise  */

#include<iostream> 
#include<queue> 
#include<stack> 
using namespace std; 


// Structure of the node of Binary Search Tree
struct dll 
{ 
   int data; 
   dll *left; 
   dll *right; 
};

dll *BSTinsert(dll *root,int x) //Inserting node in BST
{ 
   dll *p, *prev, *r; 
   r=new dll; 
   r->data=x; 
   r->left=NULL; 
   r->right=NULL; 
   if(root==NULL) 
   { 
       return r; 
   } 

   p=root; 
   while(p!=NULL) 
   { 
       prev=p; 
       if(x>p->data) 
           p=p->right; 
       else if(x<p->data) 
           p=p->left; 
       else 
       { 
 cout<<"DUPLICATE ELEMENTS ARRIVED :(\n"; //duplicate entry 
 return (root); 
} 
} 
if(x>prev->data) 
   prev->right=r; 
else 
   prev->left=r; 
return (root); 
} 

void levelorder(dll *root) //Print the node in levelorder form
{ 
   if(root==NULL) 
       return; 
   queue <dll *> p; 
   p.push(root); 
   int count=1; 
   while(!p.empty()) 
   { 
       if(count==0) 
       { 
           cout<<"\n"; 
           count=p.size(); 
       } 

       dll *q = p.front(); 
       cout<<q->data<<"\t"; 
       if(q->left!=NULL) 
           p.push(q->left); 
       if(q->right!=NULL) 
           p.push(q->right); 
       p.pop(); 
       count--; 

   } 
} 

void Rpreorder(dll *root) //Recursive Postorder
{ 
   if(root!=NULL) 
   { 
       cout<<root->data<<"\t"; 
       Rpreorder(root->left); 
       Rpreorder(root->right); 
   } 
} 

void NRpreorder(dll *root) //Iterative Preorder
{ 
   stack <dll *> s; 
   while(!s.empty() || root!=NULL) 
   { 
       while(root!=NULL) 
       { 
           cout<<root->data<<"\t"; 
           s.push(root); 
           root=root->left; 
       } 
       root=s.top(); 
       s.pop(); 
       root=root->right; 

   } 
} 

void Rinorder(dll *root) //Recursive Inorder
{ 
   if(root!=NULL) 
   { 
       Rinorder(root->left); 
       cout<<root->data<<"\t"; 
       Rinorder(root->right); 
   } 
} 

void NRinorder(dll *root) //Iterative Inorder
{ 
   stack <dll *> s; 
   while(!s.empty() || root!=NULL) 
   { 
       while(root!=NULL) 
       { 
           s.push(root); 
           root=root->left; 
       } 
       root=s.top(); 
       s.pop(); 
       cout<<root->data<<"\t"; 
       root=root->right; 
   } 
} 

void Rpostorder(dll *root) //Recursive Postorder
{ 
   if(root==NULL) 
   { 
       return; 
   } 
   Rpostorder(root->left); 

   Rpostorder(root->right); 

   cout<<root->data<<"\t"; 
} 

void NRpostorder(dll *root) //Iterative Postorder
{ 
   stack <dll*> s1; 
   stack <int> s2; 
   while(root!=NULL) 
   { 
       s1.push(root); 
       s2.push(0); 
       root=root->left; 
   } 
   while(!s1.empty()) 
   { 
       root=s1.top(); 
       if(s2.top()==1) 
       { 
           s1.pop(); 
           s2.pop(); 
           cout<<root->data<<"\t"; 
       } 
       else 
       { 
           s2.top()=1; 
           root=root->right; 
           while(root!=NULL) 
           { 
               s1.push(root); 
               s2.push(0); 
               root=root->left; 
           } 
       } 
   } 
} 

int BSTheight(dll *root) //Height of BST
{ 
   if(root==NULL) 
       return -1; 
   queue <dll *> p; 
   p.push(root); 
   int ht=-1,count; 
   while(1) 
   { 
       count=p.size(); 
       if(count==0) 
           return ht; 
       ht++; 
       while(count--) 
       { 
           dll *q=p.front(); 
           p.pop(); 
           if(q->left!=NULL) 
               p.push(q->left); 
           if(q->right!=NULL) 
               p.push(q->right); 
       } 
   } 
} 

dll* f_min(dll *root) //Find Minimum element from root
{ 
   dll*p=root; 
   while(p->left!=NULL) 
   { 
       p=p->left; 
   } 
   return (p); 
} 

dll *f_max(dll *root) //Find Maximum element from root
{ 
   dll *p=root; 
   while(p->right!=NULL) 
   { 
       p=p->right; 
   } 
   return (p); 
} 

bool search(dll *root,int x) //Search an element in BST
{ 
   while(root!=NULL) 
   { 
       if(x==root->data) 
       { 
           cout<<"ELEMENT FOUND :)\n" ; 
           return true; 
       } 
       else if(x>root->data) 
       { 
           root=root->right; 
       } 
       else 
       { 
           root=root->left; 
       } 
   } 
   cout<<"ELEMENT NOT FOUND :( \n" ; 
   return false; 

} 

dll *bstdelete(dll *root, int x) //Delete the node from BST
{ 
   dll *m; 
   if(root==NULL) 
   { 
       cout<<"NOT FOUND!!"; 
       return root; 
   } 
   if(x < root->data) 
   { 
       root->left=bstdelete(root->left,x); 
       return root; 
   } 
   if(x>root->data) 
   { 
       root->right=bstdelete(root->right,x); 
       return root; 
   } 
   if(root->left==NULL && root->right==NULL) 
   { 
       m=root; 
       delete m; 
       return (NULL); 
   } 
   else if(root->left==NULL) 
   { 
       m=root; 
       root=root->right; 
       delete m; 
       return (root); 
   } 
   else if(root->right==NULL) 
   { 
       m=root; 
       root=root->left; 
       delete m; 
       return (root); 
   } 
   m=f_min(root->right); 
   root->data=m->data; 
   root->right=bstdelete(root->right, m->data); 
   return (root); 
} 

dll *mirr(dll *root) //Mirror image of the BST
{ 
   if(root==NULL) 
       return NULL; 
   dll *p=root; 
   queue <dll *> q; 
   q.push(root); 
   while(!q.empty()) 
   { 
       dll *curr=q.front(); 
       q.pop(); 
       swap(curr->left, curr->right); 
       if(curr->left) 
           q.push(curr->left); 
       if(curr->right) 
           q.push(curr->right); 
   } 
   return (p); 
} 

dll *nd_copy(dll *root) 
{ 
   if(root==NULL) 
   { 
       return root; 
   } 
   dll *p = new dll; 
   p->data=root->data; 
   p->left=nd_copy(root->left); 
   p->right=nd_copy(root->right); 
   return p; 
} 

void par_chld(dll *root) //Print all parents and their Children
{ 
   if(root==NULL) 
       return; 
   queue <dll *> p; 
   p.push(root); 
   int count=1,x; 
   while(!p.empty()) 
   { 
       x=0; 
       dll *q = p.front(); 
       cout<<q->data<<"\t"; 
       if(q->left!=NULL) 
       { 
           x++; 
           p.push(q->left); 
           cout<<(q->left)->data<<"\t"; 
       } 
       if(q->right!=NULL) 
       { 
           x++; 
           p.push(q->right); 
           cout<<(q->right)->data<<"\t"; 
       } 
       if(x==0) 
       { 
           cout<<"\t\t(node has no child)"; 
       } 
       else if(x==1) 
       { 
           cout<<"\t(node has one child)"; 
       } 
       else if(x==2) 
       { 
           cout<<"(node has two children)"; 
       } 
       p.pop(); 
       cout<<"\n"; 

   } 
} 

void leaf_nd(dll *root) //Print all leafnode in BST
{ 
   if (!root) 
       return; 

   if (root->left==NULL && root->right==NULL) 
   { 
       cout << root->data << "\t"; 
       return; 
   } 

   if (root->left) 
       leaf_nd(root->left); 

   if (root->right) 
       leaf_nd(root->right); 
} 

int main() //main function
{ 
   dll *root=NULL,*z=NULL; 
   bool b; 
   int n,p,x; 
   
   cout<<"[1] BST INSERT\n"; 
   cout<<"[2] DELETE \n"; 
   cout<<"[3] SEARCH AN ELEMENT'S PRESENCE \n"; 
   cout<<"[4] RECURSIVE PREORDER\n"; 
   cout<<"[5] NON RECURSIVE PREORDER\n"; 
   cout<<"[6] RECURSIVE INORDER\n"; 
   cout<<"[7] NON RECURSIVE INORDER\n"; 
   cout<<"[8] RECURSIVE POSTORDER\n"; 
   cout<<"[9] NON RECURSIVE POSTORDER\n"; 
   cout<<"[10] HEIGHT OF TREE \n"; 
   cout<<"[11] MIRROR IMAGE \n"; 
   cout<<"[12] CREATE A COPY \n"; 
   cout<<"[13] DISPLAY ALL PARENT NODES WITH CHILD NODES \n"; 
   cout<<"[14] DISPLAY LEAF NODES \n"; 
   cout<<"[15] LEVEL ORDER DISPLAY\n"; 
   cout<<"[16] FIND MINIMUM \n"; 
   cout<<"[17] FIND MAXIMUM \n";
   
   do 
   { 
       cout<<"\nEnter your choice: "; 
       cin>>n; 
       switch(n) 
       { 
           case 1: 
           do 
           { 
               cout<<"enter the data \n"; 
               cin>>x; 
               root = BSTinsert(root,x); 
               cout<<"want to enter more?\n"; 
               cin>>p; 
           } 
           while(p!=0); 
           break; 
           case 2: 
           cout<<"enter the element to be deleted?\n"; 
           cin>>x; 
           if(search(root,x)) 
           { 
               root = bstdelete(root,x); 
               levelorder(root); 
           } 
           else 
           { 
               cout<<"CAN'T DELETE!! \n"; 
           } 
           break; 
           case 3: 
           cout<<"ENTER THE ELEMENT TO BE SEARCHED??\n"; 
           cin>>x; 
           b = search(root,x); 
           break; 
           case 4: Rpreorder(root); 
           break; 
           case 5: NRpreorder(root); 
           break; 
           case 6: Rinorder(root); 
           break; 
           case 7: NRinorder(root); 
           break; 
           case 8: Rpostorder(root); 
           break; 
           case 9: NRpostorder(root); 
           break; 
           case 10: 
           x = BSTheight(root); 
           cout<<x; 
           break; 
           case 11: 
           cout<<"MIRROR IMAGE IS:\n"; 
           z = mirr (root); 
           levelorder(root); 
           break; 
           case 12: 
           z = nd_copy(root); 
           cout<<"Created copy is:\n"; 
           levelorder(z); 
           break; 
           case 13: 
           par_chld(root); 
           break; 
           case 14: 
           leaf_nd(root); 
           break; 
           case 15: 
           levelorder(root); 
           break; 
           case 16: z=f_min(root); 
           cout<<z->data; 
           break; 
           case 17: z = f_max(root); 
           cout<<z->data; 
           break; 
       } 
   } 
   
   while(n<18); 
   
   cout<<"\nOPERATION COMPLETED!! THANK YOU"; 
   
   return 0; 
}


/*
-----------------------------------------------------------------------------------------------------------------------------

OUTPUT :

[1] BST INSERT
[2] DELETE 
[3] SEARCH AN ELEMENT'S PRESENCE 
[4] RECURSIVE PREORDER
[5] NON RECURSIVE PREORDER
[6] RECURSIVE INORDER
[7] NON RECURSIVE INORDER
[8] RECURSIVE POSTORDER
[9] NON RECURSIVE POSTORDER
[10] HEIGHT OF TREE 
[11] MIRROR IMAGE 
[12] CREATE A COPY 
[13] DISPLAY ALL PARENT NODES WITH CHILD NODES 
[14] DISPLAY LEAF NODES 
[15] LEVEL ORDER DISPLAY
[16] FIND MINIMUM 
[17] FIND MAXIMUM 
Enter your choice: 1
enter the data 
8
want to enter more?
1
enter the data 
3
want to enter more?
1
enter the data 
10
want to enter more?
1
enter the data 
1
want to enter more?
1
enter the data 
6
want to enter more?
1
enter the data 
14
want to enter more?
1
enter the data 
4
want to enter more?
1
enter the data 
7
want to enter more?
1
enter the data 
13
want to enter more?
0
Enter your choice: 3
ENTER THE ELEMENT TO BE SEARCHED??
7
ELEMENT FOUND :)
Enter your choice: 5
8       3       1       6       4       7       10      14      13
Enter your choice: 7
1       3       4       6       7       8       10      13      14
Enter your choice: 9
1       4       7       6       3       13      14      10      8
Enter your choice: 10
3
Enter your choice: 15
8
3       10
1       6       14
4       7       13
Enter your choice: 13
8       3       10      (node has two children)
3       1       6       (node has two children)
10      14              (node has one child)
1                       (node has no child)
6       4       7       (node has two children)
14      13              (node has one child)
4                       (node has no child)
7                       (node has no child)
13                      (node has no child)
Enter your choice: 11
MIRROR IMAGE IS:
8
10      3
14      6       1
13      7       4
Enter your choice: 16
14
Enter your choice: 15
8
10      3
14      6       1
13      7       4
Enter your choice: 18
OPERATION COMPLETED!! THANK YOU
...Program finished with exit code 0
Press ENTER to exit console.
*/
