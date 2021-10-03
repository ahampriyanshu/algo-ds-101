#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

typedef int element;
typedef struct node
{
    element data;
    struct node *firstchild;
    struct node *nextsibling;
}*GenericTree;

GenericTree create()
{
    return NULL;
}

int isEmpty(GenericTree gt)
{
    return (gt==NULL);
}

GenericTree build(element e, GenericTree firstchild, GenericTree nextsibling)
{
    GenericTree tree;
    tree=(GenericTree)malloc(sizeof(struct node));
    if(!tree)
        return NULL;
    tree->data=e;
    tree->firstchild=firstchild;
    tree->nextsibling=nextsibling;
    return tree;
}

int nodeCount(GenericTree tree)
{
    if(!tree)
        return 0;
    return 1+nodeCount(tree->firstchild)+nodeCount(tree->nextsibling);

}

int nodeSum(GenericTree tree)
{
    if(!tree)
        return 0;
    return tree->data+nodeSum(tree->firstchild)+nodeSum(tree->nextsibling);
}

int nbS(GenericTree tree)
{
    int count=0;
    while(tree)
    {
        tree=tree->nextsibling;
        count++;
    }
    return count;
}

int nbC(GenericTree tree)
{
    int count=0;
    if(tree)
        tree=tree->firstchild;
    while(tree)
    {
        count++;
        tree=tree->nextsibling;
    }
    return count;
}

int main()
{
    GenericTree sample=build(1,build(2,NULL,build(3,build(4,NULL,NULL),
                    build(5,build(6,NULL,build(7,build(8,NULL,
                    build(9,NULL,NULL)),NULL)),build(10,build(11,NULL,
                    build(12,NULL,build(13,NULL,NULL))),NULL)))),NULL);
    printf("Number of nodes: %d\n",nodeCount(sample));
    printf("Sum of nodes: %d\n",nodeSum(sample));
    printf("Neighbour Siblings: %d\n",nbS(sample));
    printf("Neighbour Children: %d\n",nbC(sample));
    return 0;
}