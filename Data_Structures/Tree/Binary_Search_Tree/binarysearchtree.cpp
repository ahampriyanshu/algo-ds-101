#include<iostream>
#include<stdlib.h>

using namespace std;

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
};

treeNode* FindMin(treeNode *node)
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

treeNode* FindMax(treeNode *node)
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

// Inserting Element in the BST

treeNode *Insert(treeNode *node,int data)
{
    if(node==NULL)
    {
        treeNode *temp;
        temp=new treeNode;
//temp = (treeNode *)malloc(sizeof(treeNode));
        temp -> data = data;
        temp -> left = temp -> right = NULL;
        return temp;
    }
    if(data >(node->data))
    {
        node->right = Insert(node->right,data);
    }
    else if(data < (node->data))
    {
        node->left = Insert(node->left,data);
    }
    /* Else there is nothing to do as the data is already in the tree. */
    return node;
}

//Deleting Element in BST

treeNode * Delet(treeNode *node, int data)
{
    treeNode *temp;
    if(node==NULL)
    {
        cout<<"Element Not Found";
    }
    else if(data < node->data)
    {
        node->left = Delet(node->left, data);
    }
    else if(data > node->data)
    {
        node->right = Delet(node->right, data);
    }
    else
    {
        /* Now We can delete this node and replace with either minimum element
        in the right sub tree or maximum element in the left subtree */
        if(node->right && node->left)
        {
            /* Here we will replace with minimum element in the right sub tree */
            temp = FindMin(node->right);
            node -> data = temp->data;
            /* As we replaced it with some other node, we have to delete that node */
            node -> right = Delet(node->right,temp->data);
        }
        else
        {
            /* If there is only one or zero children then we can directly
            remove it from the tree and connect its parent to its child */
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            free(temp); /* temp is longer required */
        }
    }
    return node;
}

//Searching for an Element in BST

treeNode * Find(treeNode *node, int data)
{
    if(node==NULL)
    {
        /* Element is not found */
        return NULL;
    }
    if(data > node->data)
    {
        /* Search in the right sub tree. */
        return Find(node->right,data);
    }
    else if(data < node->data)
    {
        /* Search in the left sub tree. */
        return Find(node->left,data);
    }
    else
    {
        /* Element Found */
        return node;
    }
}

//Inorder BST

void Inorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    Inorder(node->left);
    cout<<node->data<<" ";
    Inorder(node->right);
}

//Preorder BST

void Preorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    cout<<node->data<<" ";
    Preorder(node->left);
    Preorder(node->right);
}

//Postorder BST

void Postorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    Postorder(node->left);
    Postorder(node->right);
    cout<<node->data<<" ";
}

//main function
int main()
{
    treeNode *root = NULL,*temp;
    int ch;
    while(1)
    {
        cout<<"\n1.Insert\n\n 2.Delete\n\n 3.Inorder\n\n 4.Preorder\n\n 5.Postorder\n\n 6.FindMin\n\n 7.FindMax\n\n 8.Search\n\n 9.Exit\n";
        cout<<"Enter ur choice:";
        cin>>ch;
        
        //switch case
        
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
            cout<<"\nMinimum element is :"<<temp->data;
            break;
        case 7:
            temp = FindMax(root);
            cout<<"\nMaximum element is :"<<temp->data;
            break;
        case 8:
            cout<<"\nEnter element to be searched:";
            cin>>ch;
            temp = Find(root,ch);
            if(temp==NULL)
            {
                cout<<"Element is not foundn";
            }
            else
            {
                cout<<"Element "<<temp->data<<" is Found\n";
            }
            break;
        case 9:
            exit(0);
            break;
        default:
            cout<<"\nEnter correct choice:";
            break;
        }
    }
    return 0;
}
