

// With this we can create a linked list and we can display,reverse and check the occurence for a particular number
#include<bits/stdc++.h>
using namespace std;

struct node {
int data;
struct node *next;
}*stnode;
;
void createnodelist(int  n);
void check(int x,int count);
void display();
void reverse();
int main()
{int n,count=0,x;
cout<<"Enter the number of nodes you want to create :";
cin>>n;
createnodelist(n);
display();

cout<<"enter the number for which u want to find count";
cin>>x;
check(x,count);
reverse();
display();





return 0;
}
void createnodelist(int n){
    
    struct node *temp,*fnnode;
    int data,i;
    stnode = (struct node*)malloc(sizeof(struct node));
    if(stnode ==NULL)
    {
        cout<<"error";

    }
    else{
        cout<<"Enter the data : ";
        cin>>data;
        stnode->data=data;
        stnode->next= NULL;
        temp=stnode;

    for(i=2;i<=n;i++)
    {

        fnnode= (struct node *)malloc(sizeof(struct node));
        if(fnnode==NULL)
        {
            cout<<"error";
            break;

        }
        else {
            cin>>data;
            fnnode->data= data;
            fnnode->next=NULL;
                temp->next=fnnode;
                temp=temp->next;

        }

    }
    }

}
void display()
{
    struct node *temp;
    if(stnode==NULL)
    {
        cout<<"error";
    }
    else{
            temp=stnode;
    while(temp!=NULL)
          {

              cout<<"->"<<temp->data;
              temp=temp->next;
          }
    }
    cout<<endl;
}
void check(int x,int count)
{
    struct node *temp;
    if(stnode==NULL)
    {
        cout<<"error";
    }
    else{
            temp=stnode;
    while(temp!=NULL)
          {
              if(temp->data==x)
              count = count+1;

              temp=temp->next;
          }
    }
    cout<<"The count is "<<count<<endl;;
}
void reverse(){
    cout<<"Reversed Linked list";
    struct node *curr = stnode;
    struct node *prev=NULL,*next=NULL;
    while(curr!=NULL)
    {
    next  =  curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;

    }
    stnode=prev;
}

