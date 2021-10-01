# include <stdio.h>
# include <stdlib.h>
void create();
void display();
void insert_beg();
void count_node();
void delete();
struct node{
	int data;
	struct node *next;
};
struct node *start=NULL;
void create();
void display();
void insert_beg();
void insert_end();
void insert_at_loc();
int main()
{
	int c;
	create();
	while(1){
	   printf("\n Available options:");
	   printf("1.DISPLAY\n 2.INSERT AT BEGINNING\n 3.INSERT AT END\n 4.INSERT AT LOCATION\n 5.COUNT\n 6.DELETE\n");	
	   printf("\n Enter your choice");
	   scanf("%d",&c);
	   switch(c){
	        case 1: display();
	                break;
	        case 2: insert_beg();
	                break;
	        case 3: insert_end();
	                break;
	        case 4: insert_at_loc();
	                break;
	        case 5: count_node();
	                break;
	        case 6: delete();
	                break;
        }
   }
    return 0;
}
void create()
{
	int n,item,i=1;
	printf("Enter the value of n");
	scanf("%d",&n);
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
    start=p;
    printf("\n Enter the data for the node");
    scanf("%d",&item);
    p->data=item;
    p->next=NULL;
	for(i=2;i<=n;i++)
	{
		printf("\n Enter the data for the node");
		scanf("%d",&item);
		p->next = (struct node*)malloc(sizeof(struct node));
		p=p->next;
		p->data=item;
		p->next=NULL;
	}
}
void display()
{
	struct node *p=start;
	while(p!=NULL){
		printf("%d->",p->data);
		p=p->next;
	}
}
void insert_beg()
{
	int item;
	printf("\n Enter the data to be inserted");
	scanf("%d",&item);
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data= item;
	temp->next=start;
	start=temp;
}
void insert_end()
{
	struct node *p=start,*temp;
	int item;
	printf("\n Enter the data to be inserted");
	scanf("%d",&item);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->next=NULL;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=temp;
}
void insert_at_loc()
{
	int i,item,loc;
	printf("Enter the data to be inserted\n");
	scanf("%d",&item);
	printf("\n Enter the location");
	scanf("%d",&loc);
	struct node *p=start,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	for(i=1;i<loc;i++)
	{
		p=p->next;
    }
	temp->next=p->next;	
	p->next=temp;
}
void count_node()
{
	int count=0;
	struct node *p=start;
	while(p!=NULL)
	{
		count=count+1;
		p=p->next;
	}
	printf("Node count : %d",count);
}
void delete()
{
	int item;
	struct node *p=start,*old;
	printf("Enter the item to be deleted\n");
	scanf("%d",&item);
	while(p!=NULL)
	{
		if(p->data ==item){
			if(p==start){
				start=p->next;
				free(p);
				return;
			}
			else{
				old->next=p->next;
				free(p);
				return;
			}
		}
		else
		{
			old=p;
			p=p->next;
		}
	}
}

