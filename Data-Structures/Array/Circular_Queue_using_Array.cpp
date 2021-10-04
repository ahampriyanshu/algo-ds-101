/*
	Author: Sachin19k
*/

/* Problem Statement : 

Implement Circular Queue using Array. Perform following operations on it.
a) Insertion (Enqueue)
b) Deletion (Dequeue)
c) Display
(Note: Handle queue full condition by considering a fixed size of a queue.) */

#include<iostream> 
using namespace std; 

// Opetations on Queue required
struct Queue 
{ 
private: 
	int rear,front,size; 
public: 
	Queue(int n) 
	{ 
		size=n; 
		front=-1; 
		rear=-1; 
	} 
	void enqueue(int a[]); 
	void dequeue(int a[]); 
	void show(int a[]); 
};

void Queue::enqueue(int a[]) //INSERTION IN QUEUE 
{ 
	if((rear+1)%size == front) 
	{ 
		cout<<"\n QUEUE FULL!!\n"; 
	} 
	else 
	{ 
		int x; 
		cout<<"\n ENTER THE ELEMENT TO BE INSERTED: "; 
		cin>>x; 
		if(rear ==-1) 
		{ 
			front=0; 
			rear=0; 

		} 
		else 
		{ 
			rear=(rear+1)%size; 
		} 
		a[rear]=x; 
	} 
} 

void Queue::dequeue(int a[]) //DELETION FROM QUEUE
{ 
	if(rear == -1 && front == -1) 
	{ 
		cout<<"\n EMPTY QUEUE! (nothing to delete) \n "; 
		return; 
	} 
	else 
	{ 
		cout<<"Deleted element from queue is "<<a[front]<<"\n"; 
		if(rear == front) 
		{ 
			rear= -1; 
			front= -1; 
		} 
		else 
		{ 
			front=(front+1)%size; 
		} 
	} 
} 

void Queue::show(int a[]) //DISPLAY OF ELEMENTS 
{
	if(front == -1)
	{ 
		cout<<"\n QUEUE IS EMPTY! (nothing to show )) \n"; 
		return; 
	} 
	else 
	{ 
		int x=front; 
		while(x != rear) 
		{ 
			cout<<a[x]<<"\t"; 
			x=(x+1)%size; 
		} 
		cout<<a[rear]<<"\t"; 
	} 
} 

int main() //main function
{ 
	int n,ch; 
	cout<<"Enter the size of the array: "; 
	cin>>n; 
	int a[n]; 
	Queue s(n);
	cout<<" \n [1] INSERTION "; 
	cout<<" \n [2] DELETION "; 
	cout<<" \n [3] DISPLAY \n"; 
	do 
	{ 
		cout<<" \n *****Enter your choice***** (want to exit? enter 0) \n"; 
		cin>>ch; 
		switch(ch) 
		{ 
			case 1: 
			{ 
				s.enqueue(a); 
				break; 
			} 
			case 2: 
			{ 
				s.dequeue(a); 
				break; 
			} 
			case 3: 
			{ 
				s.show(a); 
				break; 
			}
		}
	} 
	while(ch>0 && ch<4); 
	cout<<"\n \t OPERATION COMPLETED!! THANK YOU :) \t \n"; 
	return 0; 
}

/*
--------------------------------------------------------------------------------------------------------------------------
OUTPUT :

 Enter the size of the array: 6
 
 [1] INSERTION  
 [2] DELETION  
 [3] DISPLAY 
 
 *****Enter your choice***** (want to exit? enter 0) 
1

 ENTER THE ELEMENT TO BE INSERTED: 2
 
 *****Enter your choice***** (want to exit? enter 0) 
1

 ENTER THE ELEMENT TO BE INSERTED: 6
 
 *****Enter your choice***** (want to exit? enter 0) 
1

 ENTER THE ELEMENT TO BE INSERTED: 8
 
 *****Enter your choice***** (want to exit? enter 0) 
1

 ENTER THE ELEMENT TO BE INSERTED: 9
 
 *****Enter your choice***** (want to exit? enter 0) 
1

 ENTER THE ELEMENT TO BE INSERTED: 22
 
 *****Enter your choice***** (want to exit? enter 0) 
3
2       6       8       9       22       
 *****Enter your choice***** (want to exit? enter 0) 
1

 ENTER THE ELEMENT TO BE INSERTED: 7
 
 *****Enter your choice***** (want to exit? enter 0) 
1

 QUEUE FULL!!
 
 *****Enter your choice***** (want to exit? enter 0) 
2
Deleted element from queue is 2
 
 *****Enter your choice***** (want to exit? enter 0) 
2
Deleted element from queue is 6
 
 *****Enter your choice***** (want to exit? enter 0) 
3
8       9       22      7        
 *****Enter your choice***** (want to exit? enter 0) 
0

         OPERATION COMPLETED!! THANK YOU :)      


...Program finished with exit code 0
Press ENTER to exit console.
*/