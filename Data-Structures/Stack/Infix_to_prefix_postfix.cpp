/*
	Author: Sachin19k
*/

/*Problem Statement :

Implement stack as an abstract data type using singly linked list and use this ADT for conversion of infix expression to postfix, prefix and evaluation of postfix and prefix expression.

Sample Input for Testing:
1.	(a+b)*c
2.	(a+b)/(c*d)
3.	(a+(b*c))/(c-(d*b))
4.	a*b/(c-d)+e*f
5.	(a-z)*(b+c-d*e)*f   */

#include<iostream>
#include<string.h>
#include<ctype.h>

using namespace std;

struct node
{
	char data;
	node *next;
};

struct eval_node
{
	int data;
	eval_node *next;
};

class stack
{
	node *top;

public:
	stack()
	{
		top=NULL;
	}
	void push(char a);
	char pop();
};

class eval_stack
{
	eval_node *top;

public:
	eval_stack()
	{
		top=NULL;
	}
	void push(int a);

	int pop();
};

void stack::push(char a)
{
	node *newnode=new node;
	newnode->data=a;
	newnode->next=top;
	top=newnode;
}

char stack::pop()
{
	if(top==NULL)
	{
		cout<<"\n UNDERFLOW!!";
		return '%';
	}
	char a=top->data;
	node *ptr=top;
	top=top->next;
	delete ptr;
	return a;
}

void eval_stack::push(int a)
{
	eval_node *temp=new eval_node;
	temp->data=a;
	temp->next=top;
	top=temp;
}

int eval_stack::pop()
{
	if(top==NULL)
	{
		cout<<"\n UNDERFLOW!!";
		return '%';
	}
	int a=top->data;
	eval_node *ptr=top;
	top=top->next;
	delete ptr;
	return a;
}

void disp(char b[])
{
	cout<<"[";
	for(int i=0;b[i]!='\0';i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<"]";
}

void rev(char a[],int n)
{
	char p;
	for(int i=0;i<n/2;i++)
	{
		p=a[i];
		a[i]=a[n-1-i];
		a[n-i-1]=p;
	}

	for(int i=0;i<n;i++)
	{
		if(a[i]=='(')
		{
			a[i]=')';
		}
		else if(a[i]==')')
		{
			a[i]='(';
		}
	}

}

int seq(char a)
{
	if(a=='(')
		return 0;
	else if(a=='-')
		return 1;
	else if(a=='+')
		return 2;
	else if(a=='/')
		return 3;
	else
		return 4;
}

int result(int a1,int a2,char op)
{
	if(op=='+')
		return (a1+a2);
	else if(op=='-')
		return (a1-a2);
	else if(op=='*')
		return (a1*a2);
	else
		return (a1/a2);
}

void in_pos(char a[],char b[])
{
	stack s;
	char a1,a2;
	int b1,b2,top=-1,i=0,j=0;
	while(a[i]!='\0')
	{
		if(a[i]=='(')
		{
			s.push(a[i]);
			top++;
			i++;
		}

		else if(isalnum(a[i]))
		{
			b[j]=a[i];
			i++;
			j++;
		}

		else if(a[i]=='-' || a[i]=='+' || a[i]=='/' || a[i]=='*')
		{
			if(top==-1)
			{
				s.push(a[i]);
				top++;
			}
			else
			{
				a1=s.pop();
				top--;

				if(a1=='-' || a1=='+' || a1=='/' || a1=='*')
				{
					a2=a[i];
					b1=seq(a1);
					b2=seq(a2);
					if(b1>b2)
					{
						b[j]=a1;
						j++;
						s.push(a2);
						top++;
					}
					else
					{
						s.push(a1);
						top++;
						s.push(a2);
						top++;
					}
				}
			}
			i++;
		}
		else if(a[i]==')')
		{
			a1=s.pop();
			top--;
			while(a1!='(')
			{
				b[j]=a1;
				j++;
				a1=s.pop();
				top--;
			}
			i++;
		}
	}

	while(top!=-1)
	{
		a1=s.pop();
		top--;
		b[j]=a1;
		j++;
	}
	b[j]='\0';
}

void in_pre(char a[],char b[])
{
	int n=strlen(a);
	rev(a,n);
	in_pos(a,b);
	n=strlen(b);
	rev(b,n);
}

int eval_pos(char a[])
{
	eval_stack s;
	int op1,op2,top=-1,i=0,sol;

	while(a[i]!='\0')
	{
		if(isalnum(a[i]))
		{
			s.push(int(a[i])-48);
			top++;
		}
		else
		{
			op2=s.pop();
			top--;
			op1=s.pop();
			top--;
			sol=result(op1,op2,a[i]);
			s.push(sol);
			top++;
		}
		i++;
	}
	return sol;
}

int eval_pre(char a[])
{
	eval_stack s;
	int op1,op2,top=-1,sol;
	int i=strlen(a)-1;
	while(i>=0)
	{
		if(isalnum(a[i]))
		{
			s.push(int(a[i])-48);
			top++;
		}
		else
		{
			op1=s.pop();
			top--;
			op2=s.pop();
			top--;
			sol=result(op1,op2,a[i]);
			s.push(sol);
			top++;
		}
		i--;
	}
	return sol;
}
 int main()
 {
 	char ip[20],op[20];
 	int in,ch;

 	cout<<"----MENU----\n";
 	cout<<"[1] INFIX TO POSTFIX\n";
 	cout<<"[2] INFIX TO PREFIX\n";
 	cout<<"[3] EVALUATION OF POSTFIX\n";
 	cout<<"[4] EVALUATION OF PREFIX\n\n";

 	do
 	{
 		cout<<"**** Enter your choice ****\n\n";
 		cin>>ch;
 		if(ch==1)
 		{
 			cout<<"Enter Infix expression: \n";
 			cin>>ip;
 			in_pos(ip,op);
 			cout<<"Hence, Postfix Expression is: \n";
 			disp(op);
 		}
 		else if(ch==2)
 		{
 			cout<<"Enter Infix expression: \n";
 			cin>>ip;
 			in_pre(ip,op);
 			cout<<"Hence, Prefix Expression is: \n";
 			disp(op);
 		}
 		else if(ch==3)
 		{
 			cout<<"Enter Postfix expression: \n";
 			cin>>ip;
 			int s1=eval_pos(ip);
 			cout<<"Evaluating Postfix Expression, we get \n";
 			cout<<s1;
 		}
 		else if(ch==4)
 		{
 			cout<<"Enter Prefix expression: \n";
 			cin>>ip;
 			int s2=eval_pre(ip);
 			cout<<"Evaluating Prefix Expression, we get \n";
 			cout<<s2;
 		}
 		else
 		{
 			cout<<"Please enter Valid input!!\n";
 		}
 		cout<<"\n Do you want to continue (Enter 1 if yes)\n";
 		cin>>in;
 	}
 	while(in==1);
 	{
 		cout<<"\n----Operation Completed!! ThankYou----\n";
 		return 0;
 	}
 }

/*
---------------------------------------------------------------------------------------------------------------------------
OUTPUT : 

----MENU----
[1] INFIX TO POSTFIX
[2] INFIX TO PREFIX
[3] EVALUATION OF POSTFIX
[4] EVALUATION OF PREFIX

**** Enter your choice ****

1
Enter Infix expression: 
(a+(b*c))/(c-(d*b))
Hence, Postfix Expression is: 
[a b c * + c d b * - / ]
----Operation Completed!! ThankYou----
*/