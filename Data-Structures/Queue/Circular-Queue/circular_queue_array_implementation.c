#include <stdio.h>
int front=-1;
int rear=-1;
int isFull(int size){
  if((front==rear+1)||(front==0 && rear==size-1))
  return 1;
  return 0;
}
int isEmpty(){
  if(front==-1){
  return 1;
}
  return 0;
}
void display(int queue[],int size){
  printf("\n");
  int i;
  if(front>rear){
    for(i=front;i<size;i++){
      printf("%d ",queue[i]);
    }
    for(i=0;i<=rear;i++){
      printf("%d ",queue[i]);
    }
  }
  else{
    for(i=front;i<=rear;i++){
      printf("%d ",queue[i]);
    }
  }
}
void enqueue(int queue[],int element,int size){
  if(isFull(size)){
    printf("\nOverflow\n");
    return;
  }
  else{
    if(rear==-1){
      rear++;
      front++;
    }
    else if(front>0 && rear==size-1)
    rear=0;
    else
    rear++;
    queue[rear]=element;
  }
}
void dequeue(int queue[]){
  if(isEmpty()){
    printf("\nUnderflow\n");
  }
  else{
    if(front==rear){
      printf("\nDeleted %d\n",queue[front]);
      front=-1;
      rear=-1;
    }
    else{
      printf("\nDeleted %d\n",queue[front]);
      front++;
    }
  }
}
int main(){
int size;
printf("Enter the size of the circular queue\n");
scanf("%d",&size);
int queue[size];
printf("Enter the character from the following menu to perform the given operations\n");
printf("f->Display front element\nr->Display rear element\np->Display circular queue\ne->add an element from queue\nd->delete an element from queue\nq->quit");
char ch;
while (1) {
  printf("\nEnter a character\n");
  ch=getche();
  if(ch=='q')
  break;
  else{
  switch (ch) {
    case 'f': ;
    if(front!=-1)
    printf("\nFront element is %d\n",queue[front]);
    else
    printf("\nNo element present\n");
    break;
    case 'r': ;
    if(rear!=-1)
    printf("\nRear element is %d\n",queue[rear]);
    else
    printf("\nNo element present\n");
    break;
    case 'p': ;
    display(queue,size);
    break;
    case 'e': ;
    int tbe;
    printf("\nEnter the number to be inserted\n");
    scanf("%d",&tbe);
    enqueue(queue,tbe,size);
    break;
    case 'd': ;
    dequeue(queue);
    break;
    default:
    printf("\nIllegal character\n");
    break;
  }
}
}
}
