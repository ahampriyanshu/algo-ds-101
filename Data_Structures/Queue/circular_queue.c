#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct queue
{
int info;
struct queue *next;
} *rear,*front,*temp;;
int size = 0;

void enqueue(int info);
void dequeue();
void display();

void main(){
    int choice,x;
    do{
        printf("1-Insert\n2-Delete\n3-Display\n\nEnter a choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nEnter the info to be inserted in the Queue : ");
                    scanf("%d",&x);
                    enqueue(x);
                    display();
                    break;
            case 2: dequeue();
                    display();
                    break;
            case 3: display();
                    break;
            default:printf("Invalid choice, please try again.\n");
                    exit(0);
        }
    }while(choice!=4);
}

void enqueue(int x)
{
    temp = (struct queue*) malloc(sizeof(struct queue));
    temp -> info = x;
    if(front == NULL)
        front = temp;
    else
    {
        rear -> next = temp;
        rear = temp;
    }
    rear -> next = front;
    size++;
}

void dequeue()
{
    int x;
    if (front == NULL)
    {
        printf("\nQueue is Empty");
    }
    else if (front == rear)
    {
        x = front->info;
        free (front);
        front = rear = NULL;
    }
    else
    {
        temp = front;
        x = temp -> info;
        front = front -> next;
        rear -> next = front;
        free (temp);
    }
    size--;
    printf("\nThe deleted element is: %d",x);
}
void display()
    {
        if(front == NULL)
            printf("\nQueue is Empty!!!\n");

        temp = front;
        while (temp->next!=NULL) {
        printf("%d\n", temp->info);
        temp = temp->next;
    }
    printf("%d\n", temp->info);
}

