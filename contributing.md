#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct nod//node declaration {
   int d;
   struct nod* l;
   struct nod* r;
};

class CarTree {
   public://declare the functions
   nod *newNode (int);
   int min(int [], int, int);
   nod *buildTree (int [], int, int);
   void inorder (nod* node);
   void show(nod *, int);
   CTree()
   {}
};

int CarTree::min(int arr[], int s, int e) {
   int i, min = arr[s], minind = s;
   for (i = s + 1; i <= e; i++) {
      if (arr[i] < min) {
         min = arr[i];
         minind = i;
      }
   }
   return minind;
}

nod *CarTree::buildTree (int inorder[], int s, int e)//build the cratesian tree {
   if (s >e)
      return NULL;
      int i = min(inorder, s, e);
      nod *r = newNode(inorder[i]);
   if (s == e)
      return r;
      r->l = buildTree(inorder, s, i - 1);//call the function recursively for left child
      r->r = buildTree(inorder, i + 1, e);//call the function recursively for right child
      return r;
}

void CarTree::inorder (struct nod* node) {
   if (node == NULL)
      return;
      inorder (node->l);
      cout<<node->d<<" ";
      inorder (node->r);
}

void CarTree::show(nod *ptr, int level)//show the tree {
   int i;
   if(ptr == NULL)
      return;
   if (ptr != NULL) {
      show(ptr->r, level + 1);
      cout<<endl;
      for (i = 0;i < level;i++)
         cout<<" ";
         cout<<ptr->d;
         show(ptr->l, level + 1);
   }
}

nod *CarTree::newNode (int d)//creation of new node {
   nod* t = new nod;
   t->d = d;
   t->l = NULL;
   t->r = NULL;
   return t;
}

int main() {
   CarTree ct;
   int i, n;
   cout<<"Enter number of elements to be inserted: ";
   cin>>n;
   int a[n];
   for (i = 0; i < n; i++) {
      cout<<"Enter Element "<<i + 1<<" : ";
      cin>>a[i];
   }
   nod *r = ct.buildTree(a, 0, n - 1);
   cout<<"Cartesian tree Structure: "<<endl;
   ct.show(r,1);
   cout<<endl;
   cout<<"\n Inorder traversal of the tree \n"<<endl;
   ct.inorder(r);
   cout<<endl;
   return 0;
}
