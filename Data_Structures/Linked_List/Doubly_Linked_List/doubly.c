#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *lptr,*rptr;
};

void insert(struct node **LH,struct node **RH,int val){
        struct node *NewNode,*temp;
        temp = *LH;
        NewNode = (struct node*)malloc(sizeof(struct node));
        NewNode->value = val;
        if(*LH == NULL && *RH == NULL){
            (*LH) = (*RH) = NewNode;
            NewNode->lptr = NewNode->rptr =NULL;
        }else{
            printf("1) insert at first\n2) insert at last\n3) insert at order\nWhere u want to insert :");
            int n;
            scanf("%d",&n);
            if(n==1){
                // insert at front
                NewNode->rptr = *LH;
                NewNode->lptr = NULL;
                (*LH)->lptr = NewNode;
                *LH = NewNode;
            }else if(n==2){
                NewNode->rptr = NULL;
                NewNode->lptr = *RH;
                (*RH)->rptr = NewNode;
                *RH = NewNode;
            }else if(n==3){
                if(temp->lptr == NULL){
                    if(temp->value >= val){
                NewNode->rptr = *LH;
                NewNode->lptr = NULL;
                (*LH)->lptr = NewNode;
                *LH = NewNode;
                    }
                    else{
                NewNode->rptr = NULL;
                NewNode->lptr = *RH;
                (*RH)->rptr = NewNode;
                *RH = NewNode;
                    }
                return;
                }
                if(temp->value >= val){
                NewNode->rptr = *LH;
                NewNode->lptr = NULL;
                (*LH)->lptr = NewNode;
                *LH = NewNode;
                return;
                }

                while(temp->rptr->value <= val)
                    temp = temp->rptr;
                 if(temp->rptr == *RH){
                NewNode->rptr = NULL;
                NewNode->lptr = *RH;
                (*RH)->rptr = NewNode;
                *RH = NewNode;
                }else{
                        NewNode->lptr = temp;
                        NewNode->rptr = temp->rptr;
                        temp->rptr->lptr = NewNode;
                        temp->rptr = NewNode;
                }
            }
            else printf("\nsomething wrong");
        }
}
void Display(struct node **LH,struct node ** RH){
    struct node *temp;
    temp = *LH;
    while(temp != NULL){
        printf(" %d ",temp->value);
        temp = temp->rptr;
    }
    printf("\n");
}

void delete_Link(struct node **LH,struct node **RH){
            struct node *NodetoBeDeleted,*temp;
            int n, val;
            temp = *LH;
            if(*LH == NULL ){
                    printf("\nsorry Link List is Empty\n");
                    return;
            }
            if(temp->lptr == NULL && temp->rptr == NULL){
                NodetoBeDeleted = temp;
                free(NodetoBeDeleted);
                *LH= *RH= NULL;
            }else{
                printf("1) Delete first Link\n2) Delete Last link\n3) Delete specific value  \nwhich value u want to Delete");
                scanf("%d",&n);
                if(n==3){
                    printf("Enter value :");
                    scanf("%d",&val);
                }
                if(n==1){
                    NodetoBeDeleted = *LH;
                    (*LH) = (*LH)->rptr;
                    free(NodetoBeDeleted);
                    return;
                }else if(n==2){
                    NodetoBeDeleted = *RH;
                     (*RH)->lptr->rptr = NULL;
                    *RH = (*RH)->lptr;
                    free(NodetoBeDeleted);
                    return;

                }else if(n==3){
                    if((*RH)->value == val){
                         NodetoBeDeleted = *RH;

                    *RH = (*RH)->lptr;
                    free(NodetoBeDeleted);
                    return;
                    }
                    if((*LH)->value == val){
                        NodetoBeDeleted = *LH;
                    *LH = (*LH)->rptr;
                    free(NodetoBeDeleted);
                    return;
                    }else{


                    while(temp->rptr->value != val)
                        temp = temp->rptr;

                     NodetoBeDeleted = temp->rptr;
                     temp->rptr = temp->rptr->rptr;
                     temp->rptr->lptr = temp;
                     free(NodetoBeDeleted);
                    }
                }else{
                printf("sorry something wrong\n");
                }

            }
}

int main(){
    struct node *LH,*RH;
    LH = RH = NULL;
    int c,n;
    printf("1) Insert\n2) Delete\n3) Display\n4) Exit");
    while(c!=4){
        printf("\nEnter your choice :");
        scanf("%d",&c);
    switch(c){
    case  1:
        printf("Enter value :");
        scanf("%d",&n);
        insert(&LH,&RH,n);
        break;
    case 2:
        delete_Link(&LH,&RH);
        break;
    case 3:
        Display(&LH,&RH);
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("Please Enter Between 1 to 4");
        break;

    }
            }

    return 0;
}
