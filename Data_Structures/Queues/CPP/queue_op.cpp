/*Functions to demonstrate queue in STL
Operations: empty(), size(), front(), back(), push(g), pop()*/

#include<bits/stdc++.h>
using namespace std;

void show_queue(queue<int> q){
	while(!q.empty()){					// to check if queue is empty()
		cout<<q.front()<<" ";				// FIFO this returns the first element that was inserted
		q.pop();						// pops the first element
	}
	cout<<endl;
}

int main(){
	queue<int> qu;
	cout<<"IS empty? "<<qu.empty()<<endl;				// chekc if empty()
	qu.push(1);							// current elements =  1
	qu.push(2);							// current elements = 1,2
	qu.push(3);							// current elements = 1,2,3
	cout<<"Size "<<qu.size()<<endl;
	cout<<"Queue Elements";
	show_queue(qu);
	qu.pop();							// will pop element from front
	cout<<"Front element "<<qu.front()<<endl;		// will return element at the front of the queue
	cout<<"Last element "<<qu.back()<<endl;		// will return last inserted element.
	qu.pop();
	cout<<"Queue Elements";
	show_queue(qu);
}