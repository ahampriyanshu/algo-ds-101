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
void SortLL(Node *head)
{
    Node *cur=NULL;
    Node *temp=head;
    while(temp!=NULL)
    {
        cur=temp->next;
        while(cur!=NULL)
        {
            if(cur->data<temp->data)
            {
                int t=temp->data;
                temp->data=cur->data;
                cur->data=t;
            }
            cur=cur->next;
        }
        temp=temp->next;
    }
}
Node *removeDuplicate(Node *head)
{
    SortLL(head);
    Node *temp=head;
    while(temp!=NULL && temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            temp->next=temp->next->next;
        }
        else
        {
            temp=temp->next;
        }
    }
    return head;
}
int main()
{
    insertbeg(5);
    insertbeg(4);
    insertbeg(1);
    insertbeg(2);
    insertbeg(5);
    insertbeg(2);
    insertbeg(11);
    insertbeg(5);
    insertbeg(1);
    display(head);
    head=removeDuplicate(head);
    display(head);
}