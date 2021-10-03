#include<stdio.h>
#include<stdlib.h>
struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
    int e;
    Position next;
};

void Insert(int x, List l, Position p)
{
    Position TmpCell;
    TmpCell = (struct Node*) malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        printf("Memory out of space\n");
    else
    {
        TmpCell->e = x;
        TmpCell->next = p->next;
        p->next = TmpCell;
    }
}


int isLast(Position p, List l)
{
    return (p->next == l);
}

Position FindPrevious(int x, List l)
{
    Position p = l;
    while(p->next != l && p->next->e != x)
        p = p->next;
    return p;
}

Position Find(int x, List l)
{
    Position p = l->next;
    while(p != l && p->e != x)
        p = p->next;
    return p;
}

void Delete(int x, List l)
{
    Position p, TmpCell;
    p = FindPrevious(x, l);
    if(!isLast(p, l))
    {
        TmpCell = p->next;
        p->next = TmpCell->next;
        free(TmpCell);
    }
    else
        printf("Element does not exist!!!\n");
}

void Display(List l)
{
    printf("The list element are :: ");
    Position p = l->next;
    while(p != l)
    {
        printf("%d -> ", p->e);
        p = p->next;
    }
}

void main()
{
    int x, pos, ch, i;
    List l, l1;
    l = (struct Node *) malloc(sizeof(struct Node));
    l->next = l;
    List p = l;
 //   printf("CIRCULAR LINKED LIST IMPLEMENTATION OF LIST ADT\n\n");
    do
    {
        printf("\n\n1. INSERT\t 2. DELETE\t 3. FIND\t 4. PRINT\t 5. QUIT\n\nEnter the choice :: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                p = l;
                printf("Enter the element to be inserted :: ");
                scanf("%d",&x);
                printf("Enter the position of the element :: ");
                scanf("%d",&pos);
                for(i = 1; i < pos; i++)
                {
                    p = p->next;
                }
                Insert(x,l,p);
                break;

            case 2:
                p = l;
                printf("Enter the element to be deleted :: ");
                scanf("%d",&x);
                Delete(x,p);
                break;

            case 3:
                p = l;
                printf("Enter the element to be searched :: ");
                scanf("%d",&x);
                p = Find(x,p);
                if(p == l)
                    printf("Element does not exist!!!\n");
                else
                    printf("Element exist!!!\n");
                break;

            case 4:
                Display(l);
                break;
        }
    }while(ch<5);
    return 0;
}
