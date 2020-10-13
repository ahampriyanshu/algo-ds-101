#include <bits/stdc++.h> 
using namespace std; 

//Templates start here
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long
#define fo(i, j, k, in) for (int i = j; i < k; i += in)
#define refo(i, j, k, in) for (int i = j; i >= k; i -= in)
#define rep(i, j) fo(i, 0, j, 1)
#define rerep(i, j) fo(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define reall(cont) cont.end(), cont.begin()
#define foreach(it, l) for (auto it = l.begin() l it != l.end(); it++)
#define in(A, B, C) assert(B <= A && A <= C)
#define MOD (int)1e9
#define MOD7 1000000007
#define PI 3.1415926535897932384626433832795
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef map<int, int> MPII;
typedef map<long long, long long> MPLL;
typedef set<int> SETI;
typedef multiset<int> MSETI;
//Templates end here

//I haven't used above templates for your better understanding but you are free to use it

struct Node { 
	int key; 
	struct Node* next; 
}; 
Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->next = NULL; 
	return temp; 
} 
void printList(Node* head) 
{ 
	while (head != NULL) { 
		cout << head->key << " "; 
		head = head->next; 
	} 
	cout << endl; 
} 
int distance(Node* first, Node* last) 
{ 
	int counter = 0; 
	Node* curr; 
	curr = first; 
	while (curr != last) { 
		counter += 1; 
		curr = curr->next; 
	} 
	return counter + 1; 
} 
bool detectLoop(Node* head) 
{ 
	Node* temp = new Node; 
	Node *first, *last; 
	first = head; 
	last = head; 
	int current_length = 0; 
	int prev_length = -1; 
	while (current_length > prev_length && last != NULL) { 
		prev_length = current_length; 
		current_length = distance(first, last); 
		last = last->next; 
	} 
	if (last == NULL) { 
		return false; 
	} 
	else { 
		return true; 
	} 
} 
int main() 
{ 
	Node* head = newNode(1); 
	head->next = newNode(2); 
	head->next->next = newNode(3); 
	head->next->next->next = newNode(4); 
	head->next->next->next->next = newNode(5); 
	head->next->next->next->next->next = head->next->next; 
	bool found = detectLoop(head); 
	if (found) 
		cout << "Loop Found"; 
	else
		cout << "No Loop Found"; 
	return 0; 
}
