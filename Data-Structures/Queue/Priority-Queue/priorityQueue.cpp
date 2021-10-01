#include<bits/stdc++.h>
using namespace std;

// Node Declaration
struct node
{
	int priority;
	int info; // info stands for the value or the item to be added
	struct node *link;
};
// Class Priority Queue
class Priority_Queue
{
    private:
        node *front; //front node of queue
    public:
        Priority_Queue()
        {
            front = NULL;
        }
        // Insert into Priority Queue
        void insert(int item, int priority)
        {
            node *tmp, *q;
            tmp = new node; // make a temprory node
            tmp->info = item; //set the value
            tmp->priority = priority; //set the priority
            if (front == NULL || priority < front->priority) // if priority of current element less than front elemnt priority.
            {
                tmp->link = front;
                front = tmp;
            }
            //else if greater priority
            else
            {
                q = front;
                while (q->link != NULL && q->link->priority <= priority)
                    q=q->link;
                tmp->link = q->link;
                q->link = tmp;
            }
        }
        // Delete from Priority Queue
        void del()
        {
            node *tmp;
            if(front == NULL)
                cout<<"Queue Underflow\n";
            else
            {
                tmp = front;
                cout<<"Deleted item is: "<<tmp->info<<endl;
                front = front->link;
                free(tmp);
            }
        }
        //Print Priority Queue
    
        void display()
        {
            node *ptr;
            ptr = front;
            if (front == NULL)
                cout<<"Queue is empty\n";
            else
            {	cout<<"Queue is :\n";
                cout<<"Priority       Item\n";
                while(ptr != NULL)
                {
                    cout<<ptr->priority<<"                 "<<ptr->info<<endl;
                    ptr = ptr->link;
                }
            }
        }
};


int main()
{
    int choice, item, priority;
    Priority_Queue pq; 
    do
    {
        cout<<"1.Insert\n";
        cout<<"2.Delete\n";
        cout<<"3.Display\n";
        cout<<"4.Quit\n";
        cout<<"Enter your choice : "; 
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Input the item value to be added in the queue : ";
            cin>>item;
            cout<<"Enter its priority : ";
            cin>>priority;
            pq.insert(item, priority);
            break;
        case 2:
            pq.del();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            break;
        default :
            cout<<"Wrong choice\n";
        }
    }
    while(choice != 4);
    return 0;
}
