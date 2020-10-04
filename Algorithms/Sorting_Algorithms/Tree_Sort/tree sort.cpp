#include<iostream>
using namespace std;
struct tree{
    int info;
    tree *Left, *Right;
};
tree *root;
class TreeSort{
    public:
        int no_of_elements;
        int elements[10];
    public:
        void getarray();
        void sortit();
        void insert1(int);
        tree *insert2(tree *, tree *);
        void display(tree *);
};
void TreeSort::getarray(){
    cout<<"How many elements? ";
    cin>>no_of_elements;
    cout<<"Insert array of element to sort: ";
    for(int i=0;i<no_of_elements;i++){
        cin>>elements[i];
    }
}
void TreeSort::sortit(){
    for(int i = 0; i  < no_of_elements; i++){
        insert1(elements[i]);
    }
}
tree* TreeSort::insert2(tree *temp,tree *newnode){
    if(temp==NULL){
        temp=newnode;
    }
    else if(temp->info < newnode->info){
        insert2(temp->Right,newnode);
        if(temp->Right==NULL)
            temp->Right=newnode;
    }
    else{
        insert2(temp->Left,newnode);
        if(temp->Left==NULL)
            temp->Left=newnode;
    }
    return temp;
}
void TreeSort::insert1(int n){
    tree *temp=root,*newnode;
    newnode=new tree;
    newnode->Left=NULL;
    newnode->Right=NULL;
    newnode->info=n;
    root=insert2(temp,newnode);
}
/* Inorder traversal */
void TreeSort::display(tree *t = root){
    if(root==NULL){
        cout<<"Nothing to display";
    }else
    if(t!=NULL){
        display(t->Left);
        cout<<t->info<<" ";
        display(t->Right);
    }
}
int main(){
    TreeSort TS;
    TS.getarray();
    TS.sortit();
    TS.display();
    return 0;
}