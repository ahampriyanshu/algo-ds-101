#include <iostream>

using namespace std;

struct node
{
	int value;
	node * next;
	node * prev;

	node(int x, node * pr, node * nx){
		value = x;
		prev = pr;
		next = nx;
	}
};

struct myDeque
{
	private:
		node * head;
		node * tail;
		int cnt;
		
		void push(int x) {
			node * el = new node(x, NULL, NULL);
			head = el;
			tail = el;
			cnt++;
		}

	public:
		myDeque()
		{
			head = NULL;
			tail = NULL;
			cnt = 0;
		}
		
		void push_back(int x) {
			if(empty()){
				push(x);
				return;
			}
			
			node * el = new node(x, tail, NULL);

			tail->next = el;
			tail = el;
			cnt++;
		}

		void push_front(int x) {
			if(empty()){
				push(x);
				return;
			}
			
			node * el = new node(x, NULL, head);
			
			head->prev = el;
			head = el;
			cnt++;
		}
		
		void pop_back() {
			if(!empty()) {
				int res = tail->value;
				tail = tail->prev;
				cnt--;
				cout << res;
			}

			else {
				cout << "error";
			}
		}

		void pop_front() {
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

		void back() {
			if(!empty())
				cout << tail->value;
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
	myDeque md;
	do
    {
        cin >> q;
        if(q == "push_back"){
            cin >> x;
            md.push_back(x);
            cout << "ok";
        }
        if(q == "push_front"){
            cin >> x;
            md.push_front(x);
            cout << "ok";
        }
        if(q == "pop_back"){
            md.pop_back();
        }
        if(q == "pop_front"){
            md.pop_front();
        }
        if(q == "front"){
            md.front();
        }
        if(q == "back"){
            md.back();
        }
        if(q == "size"){
            cout << md.size();
        }
        if(q == "clear"){
            md.clear();
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
