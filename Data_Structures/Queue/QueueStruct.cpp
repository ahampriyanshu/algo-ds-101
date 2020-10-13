#include <iostream>

using namespace std;

struct node
{
	int value;
	node * next;

	node(int x){
		value = x;
		next = NULL;
	}
};

struct myQueue
{
	private:
		node * head;
		node * tail;
		int cnt;

	public:
		myQueue()
		{
			head = NULL;
			tail = NULL;
			cnt = 0;
		}

		void push(int x) {
			node * el = new node(x);
			if(empty()){
				head = el;
			}
			else{
				tail->next = el;
			}

			tail = el;

			cnt++;
		}
		
		void pop() {
			if(!empty()) {
				int res = head->value;
				head = head->next;
				cnt--;
				cout << res;
			}
			
			else {
				cout << "error";
			}
		}
		void front() {
			if(!empty())
				cout << head->value;
			else
				cout << "error";
		}

		int size() {
			return cnt;
		}
		void clear() {
			head = NULL;
			tail = NULL;
			cnt = 0;
		}
		bool empty() {
			return cnt == 0;
		}
		
};

int main()
{
	string q;
	int x;
	myQueue mq;
	do {
        cin >> q;
        if(q == "push"){
            cin >> x;
            mq.push(x);
            cout << "ok";
        }
        if(q == "pop"){
            mq.pop();
        }
        if(q == "front"){
            mq.front();
        }
        if(q == "size"){
            cout << mq.size();
        }
        if(q == "clear"){
            mq.clear();
            cout << "ok";
        }
        if(q == "exit"){
            cout << "bye";
        }
        cout << endl;
    }
    while(q != "exit");
	return 0;
}
