#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node *next;
};
struct stack{
  int top;
  struct node *list;//head of list
};
struct node *newNode(){
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the number to be inserted\n");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  return newnode;
}
struct stack *create_stack(){
  struct stack *st=(struct stack*)malloc(sizeof(struct stack));
  st->list=NULL;
  st->top=-1;
  return st;
}
void push(struct node **head){
  struct node *n=newNode();
  if(*head==NULL){
    *head=n;
  }
  else{
    struct node *p=*head;
    n->next=p;
    *head=n;
  }
}
void pop(struct node **head){
  if(*head==NULL){
    printf("\nUNDERFLOW\n");
  }
  else{
    struct node *temp=*head;
    *head=temp->next;
    printf("\nDeleted %d\n",temp->data);
    free(temp);
  }
}
void top_element(struct node *head){
  printf("\nTop element is %d\n",head->data);
}
void print_stack(struct node *head){
  printf("\n");
  struct node *p=head;
  while(p!=NULL){
    printf("%d ",p->data);
    p=p->next;
  }
  printf("\n");
}
int main(){
  struct stack *st=create_stack();
  char ch;
  printf("a->push\nd->pop\np->find top element\nk->print stack\nq->quit\n");
  do{
    printf("\nEnter a character from the given menu to perform the operations on stack\n");
    ch=getche();
    switch(ch){
      case 'a': ;
      push(&st->list);
      break;
      case 'd': ;
      pop(&st->list);
      break;
      case 'p': ;
      top_element(st->list);
      break;
      case 'q': ;
      break;
      case 'k': ;
      print_stack(st->list);
      break;
      default:
      printf("\nIllegal Character entered\n");
      break;
    }
  }while(ch!='q');
}
