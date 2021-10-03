#include<iostream>
#include <deque>
#include<climits>
#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
struct Node
{
    int key;
    vector<Node *>child;
};
Node* newNode(int x)
{
     Node* k=new Node();
     k->key=x;
     return k;
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
         freopen("outpu.txt", "w", stdout);
    #endif 

       Node *root = newNode(10);
    (root->child).push_back(newNode(2));
    (root->child).push_back(newNode(34));
    (root->child).push_back(newNode(56));
    (root->child).push_back(newNode(100));
    (root->child[0]->child).push_back(newNode(77));
    (root->child[0]->child).push_back(newNode(88));
    (root->child[2]->child).push_back(newNode(1));
    (root->child[3]->child).push_back(newNode(7));
    (root->child[3]->child).push_back(newNode(8));
    (root->child[3]->child).push_back(newNode(9));
    //cout<<root->key;

       }
