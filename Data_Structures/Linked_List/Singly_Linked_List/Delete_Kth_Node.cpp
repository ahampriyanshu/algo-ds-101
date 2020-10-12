#include <iostream>
using namespace std;

class Node{
  public:
  //Node* head;
  Node* next;
  int data;
  
  Node(int data)
  {
      this->data=data;
      //head=NULL;
      this->next=NULL;
  }
    
};



Node* remove_Kth(Node* head,int n,int k)
{
    if(head==NULL)
    {
        return head;
    }
    
    if(k==n)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    
    Node* temp=head;
    int count=0;
    
    while(temp!=NULL&&count<(n-k-1))  ///Corner cases to see
    {
        temp=temp->next;
        count++;
    }
    
    Node* del=temp->next;
    temp->next=temp->next->next;
    delete del;
    return head;
}


void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}



int main() {
    //No. of Nodes
    int n,k;
    cin>>n>>k;
    
    if(k>n)
    {
        cout<<-1;
        return 0;
    }
    
    Node* head=NULL;
    Node* tail=head;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(head==NULL)
        {
            Node* temp=new Node(x);
            head=temp;
            tail=head;
            
        }
        else
        {
            Node* temp=new Node(x);
            tail->next=temp;
            
            tail=tail->next;
        }
    }
    
    head=remove_Kth(head,n,k);
    print(head);
    
	return 0;
}