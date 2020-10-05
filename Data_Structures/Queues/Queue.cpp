// FIFO Mechanism

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

// Function to insert values in the end in the Queue
node *add(node *rear, int val)
{
    node *x;
    x = new node;
    x->data = val;
    x->next = NULL;
    if (rear != NULL)
        rear->next = x;
    rear = x;
    return rear;
}

// Function to delete values from the front in the Queue
node *del(node *front, int &val)
{
    if (front == NULL)
    {
        cout << "Queue is Empty..!" << endl; // Prints if the queue is empty
        val = -9999;
    }
    else
    {
        node *x;
        x = front;
        front = front->next;
        val = x->data; // Storing the deleted value in 'val'
        delete x;
    }
    return front;
}

// Function to print values in the Queue
void showqueue(node *front)
{
    node *ptr;
    ptr = front;
    if (ptr == NULL)
    {
        cout << "Queue is empty..!" << endl; // Prints if the queue is empty
    }
    else
    {
        cout << "Queue is " << endl;
        while (ptr != NULL)
        {
            cout << ptr->data << "\t";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int main()
{
    int choice, val;
    node *front, *rear;
    front = rear = NULL;

    // Menu Driven Program
    do
    {
        cout << "\nMain Menu\n"
             << "1. Insert\n"
             << "2. Delete\n"
             << "3. Show\n"
             << "4. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to be added: ";
            cin >> val;
            rear = add(rear, val);
            if (front == NULL)
                front = rear;
            break;
        case 2:
            front = del(front, val);
            if (val != -9999)
                cout << "The deleted value is: " << val << endl;
            if (front == NULL)
                rear = front;
            break;
        case 3:
            showqueue(front);
            break;
        default:
            break;
        }
    } while (choice != 4); // Program exits whenever the user enters no. 4
    return 0;
}

// Author - Ankit Goel