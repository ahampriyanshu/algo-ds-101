#include<stdio.h>
#include<stdlib.h>
struct qlist
{int info;
struct qlist *next;
};
struct qlist *front=NULL,*rear=NULL;
void enqueue(struct qlist **,struct qlist **,int );
int dequeue(struct qlist **,struct qlist**);
int main()
{
int ch,item;
while(1)
{
	printf("\n 1. Enqueue \n2.Dequeue \n3.exit");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("\n Enter item");
			scanf("%d",&item);
			enqueue(&front,&rear,item);
			break;
		case 2:item=dequeue(&front ,&rear);
			printf("\n %d deleted",item);
			break;
		case 3:exit(0);
		default:printf("\n invalid");
	}
}
}
void enqueue(struct qlist **pfront,struct qlist **prear,int item)
{
	
	struct qlist *newnode;
	newnode=(struct qlist *)malloc(sizeof(struct qlist));
	newnode->info=item;
	newnode->next=NULL;
	if(*pfront==NULL)
		*pfront=newnode;
	else
		(*prear)->next=newnode;
	*prear=newnode;
}
int dequeue(struct qlist **pfront,struct qlist**prear)
{
	struct qlist *temp;
	int item;
	if(*pfront==NULL)
	{
		printf("\n underflow");
		return(-9999);
	}
	temp=*pfront;
	item=(*pfront)->info;
	if(*pfront==*prear)
	{
		*pfront=NULL;
		*prear=NULL;
	}
	else
		*pfront=(*pfront)->next;
	temp->next=NULL;
	free(temp);
	return(item);
}
