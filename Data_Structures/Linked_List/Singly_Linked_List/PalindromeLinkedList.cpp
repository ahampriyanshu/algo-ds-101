#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node(int d)
    {
        data = d;
    }
    Node *ptr;
};

bool isPalin(Node *head)
{

    Node *slow = head;

    stack<int> s;

    while (slow != NULL)
    {
        s.push(slow->data);

        // Move ahead
        slow = slow->ptr;
    }

    while (head != NULL)
    {
        int i = s.top();

        s.pop();

        if (head->data != i)
        {
            return false;
        }

        head = head->ptr;
    }

    return true;
}

// Driver Code
int main()
{

    // Creating a Linked List
    Node one = Node(1);
    Node two = Node(2);
    Node three = Node(3);
    Node four = Node(2);
    Node five = Node(1);

    // Initializing next pointers
    five.ptr = NULL;
    one.ptr = &two;
    two.ptr = &three;
    three.ptr = &four;
    four.ptr = &five;
    Node *temp = &one;

    int result = isPalin(&one);

    if (result == 1)
        cout << "isPalindrome is true\n";
    else
        cout << "isPalindrome is true\n";

    return 0;
}