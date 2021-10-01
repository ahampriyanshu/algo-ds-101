#include <iostream>

using namespace std;

struct node
{
	int value;
	node * prev;

	node(int x, node * pr){
		value = x;
		prev = pr;
	}
};

struct myStack
{
	private:
		node * top;
		int cnt;



	public:
		myStack()
		{
			top = NULL;
			cnt = 0;
		}

		void push(int x) {
			/*
			node * el = new node();
			el->value = x;
			el->prev = top;
			top = el;
			cnt++;
			*/


			node * el = new node(x, top);
			top = el;
			cnt++;
		}
		
		void pop() {
			if(!empty()) {
				int res = top->value;
				top = top->prev;
				cnt--;
				cout << res;
			}
			
			else {
				cout << "error";
			}
		}
		void back() {
			if(!empty())
				cout << top->value;
			else
				cout << "error";
		}

		int size() {
			return cnt;
		}
		void clear() {
			top = NULL;
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
	myStack st;
	do
    	{
        cin >> q;
        if(q == "push"){
            cin >> x;
            st.push(x);
            cout << "ok";
        }
        if(q == "pop"){
            st.pop();
        }
        if(q == "back"){
            st.back();
        }
        if(q == "size"){
            cout << st.size();
        }
        if(q == "clear"){
            st.clear();
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
