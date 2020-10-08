#include<iostream>
#include<stdlib.h>
#include<process.h>
using namespace std;

struct Node
{
    int info;
    Node* next;
}*start,*newptr,*save,*ptr,*rear;
Node* Create_New_Node(int);
void Insert_End(Node*);
void Display(Node*);
void DelNode();
void Search(Node*);


int main()
{
    start=rear=NULL;
    int inf;  char ch='y';
    int choice;

    while(1)
    {
        cout<<"1:Insertion\n2:Display\n3:DelNode\n4:Search\n";
        cout<<"ENTER YOUR CHOICE : ";
        cin>>choice;
        switch(choice)
    {
        case 1:
        {
        cout<<"\nEnter the Information for the new node...";
        cin>>inf;
        newptr=Create_New_Node(inf);
        if(newptr!=NULL)
        {
            cout<<"\n";
        }
        else
        {
            cout<<"\nCannot create new node!!!\n";
            exit(1);
        }
        Insert_End(newptr);
        }break;
        case 2:
            cout<<endl<<endl;
        Display(start);
        break;
        case 3:
            cout<<endl;
        DelNode();
        break;
        case 4:
            cout<<endl;
        Search(start);
        break;
    }
    }

    return 0;
}
Node*Create_New_Node(int n)
{
    ptr = new Node;
    ptr->info=n;
    ptr->next=NULL;
    return ptr;
}
void Insert_End(Node*np)
{
    if(start==NULL)
    {
        start=rear=np;
    }else
    {
        rear->next=np;
        rear=np;
    }
}
void Display(Node*np)
{
    while(np!=NULL)
    {
        cout<<np->info<<"->";
        np=np->next;
    }
    cout<<"!!!\n";
}

void DelNode()
{
    if(start==NULL)
    {
        cout<<"UNDERFLOW!!!\n";
    }

    else
    {
        ptr=start;
        start=start->next;
        delete ptr;
    }
}
void Search(Node*np)
{
    int element;
    cout<<"Enter the Element to Search ";
    cin>>element;
    while(np!=NULL)
    {
        if(np->info==element)
        {
            cout<<"Search Successful  \n";
            break;
        }
        else
            cout<<"\n ELEMENT NOT FOUND ";
        np=np->next;
    }
}

