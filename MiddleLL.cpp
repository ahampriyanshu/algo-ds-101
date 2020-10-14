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
int Middle(Node *head)
{
    Node *slow=head, *fast=head;
    while(fast!=NULL && slow!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
int main()
{
    insertbeg(5);
    insertbeg(4);
    insertbeg(1);
    insertbeg(9);
    insertbeg(7);
    insertbeg(2);
    insertbeg(11);
    display(head);
    cout<<"Middle element: "<<Middle(head)<<endl;
}