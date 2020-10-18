#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {

    struct Node *new_Node = new Node(new_data);

    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
int detectloop(struct Node *list);

int main() {
    int t, n, c, x, i;
    cin >> t;
    while (t--) {
        /* Start with the empty list */
        cin >> n;
        struct Node *head = NULL;
        struct Node *temp;
        struct Node *s;
        cin >> x;
        push(&head, x);
        s = head;
        for (i = 1; i < n; i++) {
            cin >> x;
            push(&head, x);
        }
        /* Create a loop for testing */
        cin >> c;
        if (c > 0) {
            c = c - 1;
            temp = head;
            while (c--) temp = temp->next;
            s->next = temp;
        }
        int g = detectloop(head);
        if (g)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}

int detectloop(Node *head) {
    if(head==NULL||head->next==NULL)
    {
        return 0;
    }
    Node* slow=head->next;
    Node* fast =head->next->next;
    
    while(fast!=NULL&&fast->next!=NULL)
    {
        if(slow==fast)
        {
            return 1;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    return 0;
}