#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
int info;
Node *left;
Node *right;
};
Node* FindMin(Node *node)
{
if(node==NULL)
{
return NULL;
}
if(node->left)
return FindMin(node->left);
else
return node;
}
Node* FindMax(Node *node)
{
if(node==NULL)
{
return NULL;
}
if(node->right)
return(FindMax(node->right));
else
return node;
}
Node *Insert(Node *node,int info)
{
if(node==NULL)
{
Node *temp;
temp=new Node;
temp -> info = info;
temp -> left = temp -> right = NULL;
return temp;
}
if(info >(node->info))
{
node->right = Insert(node->right,info);
}
else if(info < (node->info))
{
node->left = Insert(node->left,info);
}
return node;
}
Node * Delet(Node *node, int info)
{
Node *temp;
if(node==NULL)
{
cout<<"Element Not Found";
}
else if(info < node->info)
{
node->left = Delet(node->left, info);
}
else if(info > node->info)
{
node->right = Delet(node->right, info);
}
else
{
if(node->right && node->left)
{
temp = FindMin(node->right);
node -> info = temp->info;
node -> right = Delet(node->right,temp->info);
}
else
{
temp = node;
if(node->left == NULL)
node = node->right;
else if(node->right == NULL)
node = node->left;
free(temp);
}
}
return node;
}
Node * Find(Node *node, int info)
{
if(node==NULL)
{
return NULL;
}
if(info > node->info)
{
return Find(node->right,info);
}
else if(info < node->info)
{
return Find(node->left,info);
}
else
{
return node;
}
}
void Inorder(Node *node)
{
if(node==NULL)
{
return;
}
Inorder(node->left);
cout<<node->info<<" ";
Inorder(node->right);
}
void Preorder(Node *node)
{
if(node==NULL)
{
return;
}
cout<<node->info<<" ";
Preorder(node->left);
Preorder(node->right);
}
void Postorder(Node *node)
{
if(node==NULL)
{
return;
}
Postorder(node->left);
Postorder(node->right);
cout<<node->info<<" ";
}

int n=1;

int CountNodes(Node*root)
{
	if(root==NULL)
		return 0;
	if(root->left!=NULL)
	{
		n=n+1;
		n=CountNodes(root->left);
	}
	if(root->right!=NULL)
	{
		n=n+1;
		n=CountNodes(root->right);
	}
	return n;
}



main()
{
Node *root = NULL,*temp;
int ch;
while(1)
{
cout<<"\n\t\t OPERATION MENU ";
cout<<"\n\t 1.Insert\n\t 2.Delete\n\t 3.Inorder\n\t 4.Preorder\n\t 5.Postorder\n\t 6.";
cout<<"FindMin\n\t 7.FindMax\n\t 8.Search\n\t 9.Count NO. of Nodes\n\t 10.Exit\n";
cout<<"Enter your choice:";
cin>>ch;
switch(ch)
{
case 1:
cout<<"\nEnter element to be insert:";
cin>>ch;
root = Insert(root, ch);
cout<<"\nElements in BST are:";
Inorder(root);
break;
case 2:
cout<<"\nEnter element to be deleted:";
cin>>ch;
root = Delet(root,ch);
cout<<"\nAfter deletion elements in BST are:";
Inorder(root);
break;
case 3:
cout<<"\nInorder Travesals is:";
Inorder(root);
break;
case 4:
cout<<"\nPreorder Traversals is:";
Preorder(root);
break;
case 5:
cout<<"\nPostorder Traversals is:";
Postorder(root);
break;
case 6:
temp = FindMin(root);
cout<<"\nMinimum element is :"<<temp->info;
break;
case 7:
temp = FindMax(root);
cout<<"\nMaximum element is :"<<temp->info;
break;
case 8:
cout<<"\nEnter element to be searched:";
cin>>ch;
temp = Find(root,ch);
if(temp==NULL)
{
cout<<"Element is not found\n";
}
else
{
cout<<"Element "<<temp->info<<" is Found\n";
}
break;
case 9:
    {
        cout<<"\n Total No. of Nodes is: "<<CountNodes(root);
        break;
    }
    case 10:
exit(0);

default:
cout<<"\nEnter correct choice:";
break;
}
}
}
