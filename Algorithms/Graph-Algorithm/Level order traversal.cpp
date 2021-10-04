#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll int data;
    node* left;
    node* right;
};
node* newnode(ll int data)
{
    node* newnode=new node();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    //cout<<newnode<<endl;
    return newnode;

}
void levelorder(node* root)
{   if(root==NULL) return;
else
{
 queue<node*>q;
 q.push(root);
 while(!q.empty())
 {
     node* current= q.front();
     cout<<current->data<<" ";
     if(current->left!=NULL)q.push(current->left);
     if(current->right!=NULL)q.push(current->right);
     q.pop();
 }
}
} node* inser(node* root,int data)
{
    if(root==NULL)
    {
        root=newnode(data);
    }
    else if(data<=root->data)
    {
        root->left=inser(root->left,data);
    }
    else
    {
        root->right=inser(root->right,data);
    }
    return root;
}
int main()
{
    node* root;
     root=NULL;
     root=inser(root,10);
     root=inser(root,25);
     root=inser(root,15);
     root=inser(root,7);
     root=inser(root,8);
     root=inser(root,5);
     root=inser(root,30);
     levelorder(root);
}

