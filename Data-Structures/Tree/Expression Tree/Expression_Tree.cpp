/*
	Author: adi1212 
*/

/*Problem Statement : 
Construct an Expression Tree from postfix and prefix expression. Perform recursive and nonrecursive In-order, pre-order and post-order traversals. */

#include<bits/stdc++.h> 
using namespace std; 

struct dll 
{ 
   char data; 
   dll *left; 
   dll *right; 
}; 

void levelorder(dll *root) 
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

void Rpreorder(dll *root) //Recursive preorder 
{ 
   if(root!=NULL) 
   { 
       cout<<root->data<<"\t"; 
       Rpreorder(root->left); 
       Rpreorder(root->right); 
   } 
}

void NRpreorder(dll *root) //non-Recursive preorder 
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

void Rinorder(dll *root) //Recursive inorder 
{ 
   if(root!=NULL) 
   { 
       Rinorder(root->left); 
       cout<<root->data<<"\t"; 
       Rinorder(root->right); 
   } 
} 

void NRinorder(dll *root) //non-Recursive inorder 
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

void Rpostorder(dll *root) //Recursive postorder 
{ 
   if(root==NULL) 
   { 
       return; 
   } 
   Rpostorder(root->left); 

   Rpostorder(root->right); 

   cout<<root->data<<"\t"; 
}

void NRpostorder(dll *root) //non-Recursive postorder 
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

bool isOperator(char c) //checking whether operator 
{ 
   if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') 
   { 
       return true; 
   } 
   return false; 
} 

void trav(dll *root) //tree traversal 
{ 
   int ch; 
   cout<<"\n[1] RECURSIVE PREORDER\n"; 
   cout<<"[2] NON RECURSIVE PREORDER\n"; 
   cout<<"[3] RECURSIVE INORDER\n"; 
   cout<<"[4] NON RECURSIVE INORDER\n"; 
   cout<<"[5] RECURSIVE POSTORDER\n"; 
   cout<<"[6] NON RECURSIVE POSTORDER\n"; 
   do 
   { 
       cout<<"\nEnter your choice: (enter -1 to exit)"; 
       cin>>ch; 
       switch(ch) 
       { 
           case 1: Rpreorder(root); 
           break; 
           case 2: NRpreorder(root); 
           break; 
           case 3: Rinorder(root); 
           break; 
           case 4: NRinorder(root); 
           break; 
           case 5: Rpostorder(root); 
           break; 
           case 6: NRpostorder(root); 
           break; 
       } 
   } 
   while(ch!=-1); 
}

void call1(char s[]) //postfix expression 
{ 
   stack <dll*> s1; 
   dll *p,*op1,*op2; 
   int i=0; 
   int n=strlen(s); 
   char c; 
   while(i<n) 
   { 
       p=new dll; 
       p->data=s[i]; 
       if(isOperator(s[i])) 
       { 
           op1=s1.top(); 
           s1.pop(); 
           op2=s1.top(); 
           s1.pop(); 

           p->left=op2; 
           p->right=op1; 
           s1.push(p); 
       } 
       else 
       { 
           p->left=NULL; 
           p->right=NULL; 
           s1.push(p); 
       } 
       i++; 
   } 
   p=s1.top(); 
   s1.pop(); 
   cout<<"\nwant to see level order? (TYPE Y if YES)\n"; 
   cin>>c; 
   if(c=='Y' || c=='y') 
   { 
       levelorder(p); 
   } 
   trav(p); 
} 

void call2(char s[]) //prefix expression 
{ 
   int i=strlen(s)-1; 
   stack <dll*> s1; 
   dll *p,*op1,*op2; 
   char c; 
   while(i>=0) 
   { 
       p=new dll; 
       p->data=s[i]; 
       if(isOperator(s[i])) 
       { 
           op2=s1.top(); 
           s1.pop(); 
           op1=s1.top(); 
           s1.pop(); 
           p->left=op2; 
           p->right=op1; 
           s1.push(p); 
       } 
       else 
       { 
           p->left=NULL; 
           p->right=NULL; 
           s1.push(p); 
       } 
       i--; 
   } 
   p=s1.top(); 
   s1.pop(); 
   cout<<"\nwant to see level order? (TYPE Y if YES)\n"; 
   cin>>c; 
   if(c=='Y' || c=='y') 
   { 
       levelorder(p); 
   } 
   trav(p); 
} 

int main() 
{ 
   dll *root=NULL; 
   char s[20],n; 
   int ch; 
   do 
   { 
       cout<<"Construct a EXPRESSION TREE from?\n"; 
       cout<<"[1] POSTFIX EXPRESSION\n"; 
       cout<<"[2] PREFIX EXPRESSION\n"; 
       cout<<"\nEnter your choice: (enter 0 to exit)"; 
       cin>>n; 
       if(n=='1') 
       { 
           cout<<"Enter postfix expression: \n"; 
           cin>>s; 
           call1(s); 
       } 
       else if(n=='2') 
       { 
           cout<<"Enter prefix expression: \n"; 
           cin>>s; 
           call2(s); 
       } 
   } 
   while(n!='0'); 
   cout<<"\nOPERATION COMPLETED!! THANK YOU"; 
   return 0; 
}

/*
---------------------------------------------------------------------------------------------------------------------------

OUTPUT :
 
Construct a EXPRESSION TREE from?
[1] POSTFIX EXPRESSION
[2] PREFIX EXPRESSION

Enter your choice: (enter 0 to exit)1
Enter postfix expression: 
AB*CD*+

want to see level order? (TYPE Y if YES)
y
+
*       *
A       B       C       D
[1] RECURSIVE PREORDER
[2] NON RECURSIVE PREORDER
[3] RECURSIVE INORDER
[4] NON RECURSIVE INORDER
[5] RECURSIVE POSTORDER
[6] NON RECURSIVE POSTORDER

Enter your choice: (enter -1 to exit)3
A       *       B       +       C       *       D
Enter your choice: (enter -1 to exit)-1
Construct a EXPRESSION TREE from?
[1] POSTFIX EXPRESSION
[2] PREFIX EXPRESSION

Enter your choice: (enter 0 to exit)0 

OPERATION COMPLETED!! THANK YOU

...Program finished with exit code 0
Press ENTER to exit console.
*/
