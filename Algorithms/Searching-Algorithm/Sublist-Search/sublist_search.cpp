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

//I'm not using my templates for better understanding, else above templates can be easily used, you can alse benefit yourself just copy above templates and use them

struct Node 
{ 
    int data; 
    Node* next; 
}; 
bool findList(Node* first, Node* second) 
{ 
    Node* ptr1 = first, *ptr2 = second; 
    if (first == NULL && second == NULL) 
        return true; 
    if ( first == NULL || (first != NULL && second == NULL)) 
        return false; 
    while (second != NULL) 
    { 
        ptr2 = second; 
        while (ptr1 != NULL) 
        { 
            if (ptr2 == NULL) 
                return false; 
            else if (ptr1->data == ptr2->data) 
            { 
                ptr1 = ptr1->next; 
                ptr2 = ptr2->next; 
            } 
            else break; 
        } 
        if (ptr1 == NULL) 
            return true; 
        ptr1 = first; 
        second = second->next; 
    } 
  
    return false; 
} 
void printList(Node* node) 
{ 
    while (node != NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 
Node *newNode(int key) 
{ 
    Node *temp = new Node; 
    temp-> data= key; 
    temp->next = NULL; 
    return temp; 
}
int main() 
{
    Node *a = newNode(1); 
    a->next = newNode(2); 
    a->next->next = newNode(3); 
    a->next->next->next = newNode(4); 
    Node *b = newNode(1); 
    b->next = newNode(2); 
    b->next->next = newNode(1); 
    b->next->next->next = newNode(2); 
    b->next->next->next->next = newNode(3); 
    b->next->next->next->next->next = newNode(4); 
    findList(a,b) ? cout << "LIST FOUND" : cout << "LIST NOT FOUND"; 
    return 0; 
} 