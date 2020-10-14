#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
void insertbeg(int data)
{
    Node *ptr = new Node();
    ptr->data = data;
    ptr->next = head;
    head = ptr;
}
void display(Node *np)
{
    while (np != NULL)
    {
        cout << np->data << "-->";
        np = np->next;
    }
    cout << endl;
}
int findEle(int k)
{
    int count=0;
    Node *temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    //number of elements=count. Kth from end=count-k from start
    int pos=count-k, cnt=0;
    Node *cur=head;
    while(cnt!=pos && cur!=NULL)
    {
        cnt++;
        cur=cur->next;
    }
    return cur->data;
}
int main()
{
    int k;
    insertbeg(5);
    insertbeg(4);
    insertbeg(1);
    insertbeg(9);
    insertbeg(6);
    insertbeg(9);
    insertbeg(12);
    display(head);
    cout<<"Enter k: ";
    cin>>k;
    cout<<"Kth from end is: "<<findEle(k)<<endl;
}