#include<iostream>
#include<stdlib.h>
#include<process.h>

using namespace std;

void enqueue(int);
void dequeue();
void display_CQ();

const int size = 5;
int Cqueue[size],front=-1,rear=-1;

int main()
{
    int item,choice;
     cout<<("\n\n\t\t OPERATION MENU ");
     cout<<("\n\n\t\t 1.PUSH\n\t\t 2.POP\n\t\t 3.DISPLAY\n\t\t 4.EXIT");
    do
    {
     cout<<("\n ENTER YOUR CHOICE : ");
     cin>>choice;
     switch(choice)
     {
       case 1:
       {
           cout<<"\n ENTER THE ITEM TO BE PUSHED : ";
           cin>>item;
           enqueue(item);
           break;
       }
       case 2:
        {
            dequeue();
            break;
        }
       case 3:
        {
         display_CQ();
         break;
        }
       case 4:
        exit(100);
     }
    }while(choice!=4);
    return 0;
}

void enqueue(int temp)
{
    if((front==0 && rear==size-1) || (front==rear+1))
    {
      cout<<"\n QUEUE OVERFLOW ";
      return ;
    }
    if(front==-1)
    {
        front=rear=0;
    }
    else
    {
    if(rear==size-1)
     {
        rear=0;
     }
     else
        rear++;
    }
    Cqueue[rear]=temp;
}

void dequeue()
{
    if(front==-1)
    {
        cout<<"\n QUEUE UNDERFLOW ";
        return ;
    }
    cout<<"\n ELEMENT DELETED IS "<<Cqueue[front];
        if(front==rear)
            front=rear=-1;
        else
        {
            if(front==size-1)
            front=0;
        else
            front++;
        }
}

void display_CQ()
{
int front_pos = front,rear_pos = rear;
    if(front == -1)
    {
    printf("QUEUE IS EMPTY");
    return;
    }
        printf("QUEUE IS :");
        if( front_pos <= rear_pos )
            while(front_pos <= rear_pos)
            {
            printf("%d ",Cqueue[front_pos]);
            front_pos++;
            }
        else
        {
                while(front_pos <= size-1)
                {
                printf("%d ",Cqueue[front_pos]);
                front_pos++;
                }
            front_pos = 0;
            while(front_pos <= rear_pos)
            {
            printf("%d ",Cqueue[front_pos]);
            front_pos++;
            }
        }
}

