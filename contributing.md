#include <iostream>
using namespace std;

struct Interval//interval variables declaration {
   int l, h;
};
struct ITNod//node declaration {
   Interval *i;
   int max;
   ITNod *l, *r;
};
ITNod * newNode(Interval i)//to create new node {
   ITNod *t = new ITNod;
   t->i = new Interval(i);
   t->max = i.h;
   t->l = t->r = NULL;
};
ITNod *insert(ITNod *r, Interval i) {
   if (r== NULL)
      return newNode(i);
      int l = r->i->l;
   if (i.l< l)
      r->l = insert(r->l, i);
   else
      r->r = insert(r->r, i);
   if (r->max < i.h)
      r->max = i.h;
      return r;
}
bool Overlap(Interval i1, Interval i2)// check if two intervals overlap or not. {
   if (i1.l <= i2.h && i2.l<= i1.h)
      return true;
      return false;
}
Interval *intervalFind(ITNod *root, Interval i) {
   if (root == NULL)
      return NULL;
   if (Overlap(*(root->i), i))
      return root->i;
   if (root->l!= NULL && root->l->max >= i.l)
      return intervalFind(root->l, i);
      return intervalFind(root->r, i);
}

void inorder(ITNod *root)//perform inorder traversal {
   if (root == NULL)
      return;
      inorder(root->l);
      cout << "[" << root->i->l<< ", " << root->i->h << "]" << " max = "<< root->max << endl;
      inorder(root->r);
}
int main(int argc, char **argv) {
   Interval ints[] = { { 5, 20 }, { 6, 7 }, { 3, 4 }, { 67, 26 }, { 3, 4 } };
   int n = sizeof(ints) / sizeof(ints[0]);
   ITNod *root = NULL;
   for (int i = 0; i < n; i++)
      root = insert(root, ints[i]);
      cout << "In-order traversal of the constructed Interval Tree is\n";
      inorder(root);
      Interval x = { 7, 6 };
      cout << "\nSearching for interval [" << x.l << "," << x.h << "]";
      Interval *res = intervalFind(root, x);
      if (res == NULL)
         cout << "\nNo Overlapping Interval";
      else
         cout << "\nOverlaps with [" << res->l << ", " << res->h << "]";
}
