#include <bits/stdc++.h>
using namespace std;

struct Node{
      int data;
      struct Node *next;
}*head=NULL; 

int main() {
      struct Node *temp,*mid,*prev=NULL;
	int n,x,i,midval=0;
	cout<<"Enter the number of nodes:";
	cin>>n;
	cout<<"\nEnter the elements\n";
	for(i=0;i<n;i++)
	{
	      cin>>x;
	      temp=new Node;
	      temp->data=x;
	      temp->next=NULL;
	      if(head==NULL)
	      {
	            head=temp;
	            prev=head;
	            mid=head;
	      }
	      else
	      {
	            prev->next=temp;
	            prev=temp;
	            if(i/2==midval)
	            continue;
	            else
	            {
	                  mid=mid->next;
	                  midval++;
	            }
	      }
	}
	cout<<"Middle element is:"<<mid->data<<endl;
	
	return 0;
}
