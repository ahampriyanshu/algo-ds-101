#include<stdio.h>

void enqueue(int[],int);
void dequeue(int[]);
void display_Queue(int[]);

int Queue[],size,front=-1,rear=-1;

void main()
 {
     int item,choice;
     char ch;
     printf("\n ENETR THE SIZE OF QUEUE :");
     scanf("%d",&size);
     printf("\n AFTER DEQUEUE OPERATION");
                   dequeue(Queue);
      printf("\n ENTER THE ITEM :");
                    scanf("%d",&item);
                    enqueue(Queue,item);
    display_Queue(Queue);
 }

 void enqueue(int Queue[],int temp)
  {
      if(rear==size-1)
        printf("\n QUEUE OVERFLOW");
      else
        if(rear==-1)
          {
              front=rear=0;
              Queue[rear]=temp;
              display_Queue(Queue);
          }
        else
        {
            rear++;
            Queue[rear]=temp;
        }
  }

  void dequeue(int Queue[])
   {
       if(front==-1)
        printf("\n QUEUE UNDERFLOW");
       else
       {
         printf("\n THE DELETED ITEM IS %d",Queue[front]);
         front++;
        display_Queue(Queue);
        if(front==rear)
            front=rear=-1;
        else
          front++;
       }
   }

 void display_Queue(int Queue[])
  {
      if(front==-1)
        return ;
      for(int i=front;i<=rear;++i)
          printf(Queue[i]);printf("<-");
      printf("%d",Queue[rear]);

  }
