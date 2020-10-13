/*Functions to demonstrate queue in STL
Operations: empty(), size(), front(), back(), push(g), pop()*/

#include<bits/stdc++.h>
using namespace std;
//QUEUE is a FIFO data structure, where insertion and deletion of element is done at opposite ends.

void print(queue<int> q){
	while(!q.empty()){
		cout << q.front();
		q.pop();
	}
}

int main(int argc, char const *argv[]) {

	//declaration of queue
	queue<int> q;

	//add element to QUEUE
	q.push(1);

	//print the front item of queue.
	q.front();

	//print the last item of queue.
	q.back();

	//delete item from queue.
	q.pop();

	//check if queue is empty.
	q.empty();   //returns 0 or 1.

	//check the size of queue.
	q.size();

	//iterator to queue.
	auto it = q.begin();
	queue<int> it = q.end();

	//print queue, you can't use a normal for loop and iterator methord to print the queue.
	print(q);
	return 0;
}
