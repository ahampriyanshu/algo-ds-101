#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
typedef struct node *nodeptr;
nodeptr getNode(int item)
{
    nodeptr p = (nodeptr)malloc(sizeof(struct node));
    p->next = NULL;
    p->data = item;
    return p;
}
nodeptr insertNode(nodeptr start, int item)
{
    nodeptr p = getNode(item);
    if (start == NULL)
        start = p;
    else
    {
        nodeptr temp = start;
        nodeptr toBeInsertedAfter = NULL;
        while (temp != NULL && item <= temp->data)
        {
            toBeInsertedAfter = temp;
            temp = temp->next;
        }
        if (toBeInsertedAfter == NULL)
        {
            p->next = start;
            start = p;
        }
        else
        {
            p->next = toBeInsertedAfter->next;
            toBeInsertedAfter->next = p;
        }
    }
    return start;
}
nodeptr deleteNode(nodeptr start)
{
    nodeptr temp = start;
    start = start->next;
    free(temp);
    return start;
}
void display(nodeptr start)
{
    nodeptr temp = start;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
typedef struct node *nodeptr;
int main()
{
    nodeptr start = NULL;
    nodeptr list2 = NULL;
    nodeptr startSorted = NULL;
    int choice, item, prio, i;
    for (i = 1; i; i++)
    {
        cout << "1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "ENTER ELEMENT TO BE INSERTED" << endl;
            cin >> item;
            start = insertNode(start, item);
            break;
        case 2:
            start = deleteNode(start);
            break;
        case 3:
            display(start);
            break;
        case 4:
            return 0;
        }
    }
}
