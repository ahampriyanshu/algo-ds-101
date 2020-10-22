#include <iostream>
using namespace std;
struct node
{
    long long int data;
    struct node *next;
};
typedef struct node *nodeptr;
nodeptr getNode(long long int item)
{
    nodeptr p = (nodeptr)malloc(sizeof(struct node));
    p->data = item;
    p->next = NULL;
    return p;
}
nodeptr insertAtTheBeginning(long long int item, nodeptr start)
{
    nodeptr p = getNode(item);
    if (start == NULL)
        start = p;
    else
    {
        p->next = start;
        start = p;
    }
    return start;
}
nodeptr insertAtTheEnd(long long int item, nodeptr start)
{
    if (start == NULL)
        return insertAtTheBeginning(item, start);
    nodeptr p = getNode(item);
    nodeptr temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = p;
    return start;
}
nodeptr insertAtLocation(long long int item, nodeptr start, long long int location)
{
    nodeptr p = getNode(item);
    long long int i;
    nodeptr temp = start;
    for (i = 1; i < location - 1; i++)
        temp = temp->next;
    if (i == 1)
        return insertAtTheBeginning(item, start);
    else
    {
        p->next = temp->next;
        temp->next = p;
        return start;
    }
}
nodeptr deleteFirst(nodeptr start)
{
    nodeptr temp = start;
    start = start->next;
    free(temp);
    return start;
}
nodeptr deleteGivenNode(long long int item, nodeptr start)
{
    if (item == start->data)
        return deleteFirst(start);
    else
    {
        nodeptr temp = start;
        while (temp != NULL && (temp->next)->data != item)
            temp = temp->next;
        nodeptr toBeDeleted = temp->next;
        temp->next = (temp->next)->next;
        free(toBeDeleted);
        return start;
    }
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
long long int countNodes(nodeptr start)
{
    nodeptr temp = start;
    long long int counter = 1;
    if (start != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
            counter++;
        }
    }
    return counter;
}
nodeptr deleteNode(nodeptr start, long long int counter, long long int k)
{
    if (start == NULL)
    {
        cout << "VOID DELETION" << endl;
        return NULL;
    }

    else
    {
        long long int it;
        nodeptr temp = start;
        for (it = 1; it <= counter - k; it++)
            temp = temp->next;
        cout << temp->data << " HAS BEEN DELETED" << endl;
        return deleteGivenNode(temp->data, start);
    }
}
int main()
{
    nodeptr start = NULL;
    nodeptr list2 = NULL;
    nodeptr startSorted = NULL;
    long long int choice, item, location, i, counter = 0, k;
    for (i = 1; i; i++)
    {
        cout << "(1)INSERT AT BEGINNING\n(2)INSERT AT END\n(3)INSERT AT A LOCATION\n(4)DELETE NODE\n(5)DISPLAY\n(6)EXIT" << endl;
        cout << "ENTER CHOICE: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "ENTER ELEMENT TO BE INSERTED: ";
            cin >> item;
            start = insertAtTheBeginning(item, start);
            counter = countNodes(start);
            break;
        case 2:
            cout << "ENTER ELEMENT TO BE INSERTED: ";
            cin >> item;
            start = insertAtTheEnd(item, start);
            counter = countNodes(start);
            break;
        case 3:
            cout << "ENTER ELEMENT TO BE INSERTED: ";
            cin >> item;
            cout << "ENTER LOCATION: ";
            cin >> location;
            start = insertAtLocation(item, start, location);
            counter = countNodes(start);
            break;
        case 4:
            cout << "ENTER POSITION OF ELEMENT TO BE DELETED FROM END: ";
            cin >> k;
            if (k > counter || counter == 0)
                cout << "VOID DELETION" << endl;
            else
            {
                start = deleteNode(start, counter, k);
                counter = countNodes(start);
            }

            break;
        case 5:
            display(start);
            break;
        case 6:
            return 0;
        }
    }
    return 0;
}
