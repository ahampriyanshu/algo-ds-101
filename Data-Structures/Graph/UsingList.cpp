#include <iostream>
#include <cstdlib>
using namespace std;
int n =5;
typedef struct node{
    int data;
    struct node *next;
}node;


void sortedInsert(node **p, int v){
    node *newnode;
    newnode = (node *) malloc (sizeof(node));
    newnode->data = v;
    newnode->next=0;

    if(*p == 0 || (*p)->data > v){
        newnode->next = (*p);
        *p =newnode;
    }
    else{
        node *temp;
        temp=*p;
        while (temp->next != 0  && temp->next->data  < v) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

}
void display(node *p){
    while(p!=0){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void BSFll(node* a[], int visit[], int row=0){
    int queue[n];
    int top =-1, i, bottom =-1;
    visit[row]=1;
    queue[++bottom] = row;
    cout<<(char)(row+65)<<" ";
    while(top != bottom){
        row= queue[++top];
        node * temp;
        temp = a[row];
        while(temp != NULL){
            i = temp->data;
            if(!visit[i]){
                visit[i]=1;
                cout<<(char)(i+65)<<" ";
                queue[++bottom] =i;
            }
            temp = temp->next;
        }
    }
}
void DSFll(node* a[], int visit[], int row=0){
    int stack[n];
    int top = -1,i;
    visit[row]=1;
    stack[++top]= row;
    cout<<(char)(row+65)<<" ";
    while(top!= -1){
        row= stack[top];
         node * temp;
         temp = a[row];
         while(temp != NULL){
            i = temp->data;
            if(!visit[i]){
                visit[i]=1;
                cout<<(char)(i+65)<<" ";
                stack[++top]=i;
                break;
            }
            temp = temp->next;
        }
        if(temp == NULL){
            top--;
        }
    }
}


void createGraph(node *a[], int s, int d){
    sortedInsert(&a[s], d);
    // condition for directed
    sortedInsert(&a[d], s);
}
int main()
{
    node* a[5]= {NULL};
    node *first =0, *second=0, *third=0, *fourth=0, *fifth=0;
    a[2] = third;
    a[1] = second;
    a[0] = first;
    a[3] = fourth;
    a[4] = fifth;
    int visit[5] ={0};
    createGraph(a, 0, 2);
    createGraph(a,1,2);
    createGraph(a,2,3);
    createGraph(a,3,4);
    BSFll(a,visit);
    return 0;
}
//Contributed by Vaishnavi Shah