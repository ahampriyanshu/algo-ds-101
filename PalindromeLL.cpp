#include <iostream>
#include <vector>
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
bool Palindrome(Node *head)
{
    Node *temp=head;
    vector<int> lst;
    while(temp!=NULL)
    {
        lst.push_back(temp->data);
        temp=temp->next;
    }
    int left=0, right=lst.size()-1;
    while(left<right)
    {
        if(lst[left++]!=lst[right--])
            return false;
    }
    return true;
}
int main()
{
    insertbeg(4);
    insertbeg(3);
    insertbeg(2);
    insertbeg(1);
    insertbeg(1);
    insertbeg(2);
    insertbeg(3);
    insertbeg(4);
    display(head);
    cout<<Palindrome(head)<<endl;
}