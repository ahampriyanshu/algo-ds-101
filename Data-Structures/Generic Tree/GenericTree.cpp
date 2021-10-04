#include<iostream>
#include <deque>
#include<climits>
#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
struct Node
{
    int key;
    vector<Node*> children;//reference to child nodes
    Node(int x)
   {
      key=x;
   }
};

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); //for fast IO
       Node *root = new Node(10);
       int n;
       //enter n numbers that will be children of root
       cin>>n;
       for(int i=0;i<n;i++)
       {
           int x;
           cin>>x;
           root->children.push_back(new Node(x));
       }
       //enter x1 numbers that will children of first child
       int x1;
       cin>>x1;
       for(int i=0;i<x1;i++)
       {

           int x;
           cin>>x;
           Node* k=new Node(x);
           root->children[0]->children.push_back(k);

       }
       int x2;
       cin>>x2;
        //enter x2 numbers that will children of first child
       for(int i=0;i<x2;i++)
       {
            
           int x;
           cin>>x;
           root->children[1]->children.push_back(new Node(x));

       }
      // dynamically we can more children 
   
       cout<<root->children[1]->key;

       }
