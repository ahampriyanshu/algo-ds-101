#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Element{                    // this is the structure of element to be stored in stack
    int left;                       //left index of array
    int right;                      //right index of array
    int state;                      //state = 0 represents the array needs to be split and 1 represents that to merge
};

struct Stack{                           //Structure for Stack
    int top;
    struct Element array[10000];       //array of Element
};

int IsEmpty(struct Stack *stack){
    if(stack->top == -1){
        return 1;
    }
    return 0;
}

int Push(struct Stack *stack, struct Element val){      // val is of type struct Element
    stack->top += 1;
    stack->array[stack->top] = val;
    return 0;    
}

struct Element Top(struct Stack *stack){
    if(IsEmpty(stack)){
        struct Element empty={0,0,0};                // to return an empty element
        return empty;                                // this if condition will never come true because only for
    }                                                // non empty stacks, we will call Top and Pop.
    else{
        return stack->array[stack->top];
    }
}
struct Element Pop(struct Stack *stack){
    if(stack->top == -1){
        struct Element empty= {0,0,0};
        return empty;
    }
    else{
        struct Element item = stack->array[stack->top] ;
        stack->top -= 1;
        return item;
    }
}



void merge(int* A,int* B, int n, int left, int mid, int right){         //This is the basic merge function, no change
    int p = left, q=mid+1 ,r =left;
    while(r<=right){
        if(p<=mid && q<=right){
            if(A[p]<=A[q]){
                B[r]=A[p];
                r=r+1, p=p+1;
                continue;
            }
            else{
                B[r] =A[q];
                r=r+1, q=q+1;
                continue;
            }
        }
        else if(p<=mid && q>right){
            B[r]= A[p];
            r=r+1, p=p+1;
            continue;
        }
        else if(p>mid && q<=right){
            B[r]=A[q];
            r=r+1, q=q+1;
            continue;
        }
    }
    
    for(int i=left; i<=right;i++){
        A[i]=B[i];
    }
}

void merge_sort(int* A,int* B, int n){              //we will call this function only once for an array
    struct Stack stack;                            //therefore new stack is defined once for every array 
    stack.top = -1;
    struct Element parent_array = {0,n-1,0};           //parent_array represents the array with left = 0, right = n-1
    Push(&stack, parent_array);
    
    while(!IsEmpty(&stack)){
        struct Element current_array = Pop(&stack);       //current_array is the one we are working with
        if(current_array.state == 0){                     //the array needs to be split
            current_array.state =1;                       //the state is changed to 1 meaning we have consdered state=0
            int mid = (current_array.left +current_array.right)/2;
            if(current_array.right <= current_array.left){                //for singleton do nothing
                continue;                                                                       
            }
            struct Element lchild_array = {current_array.left, mid, 0};//lchild_array and rchild_array are two subarrays
            struct Element rchild_array = {mid+1, current_array.right, 0};   // of current_array
        
            Push(&stack, current_array);
            Push(&stack, rchild_array);
            Push(&stack, lchild_array);
        }
        else{                                                            //if state = 1, we need to merge the subarray
            int mid = (current_array.left +current_array.right)/2;
            merge(A,B,n, current_array.left, mid, current_array.right);
        }
    }
}

int main() {
    
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++){
        int n;
        scanf("%d",&n);
        int A[n];
        int B[n];
        for(int j=0 ; j<n; j++){
            scanf("%d",&A[j]);
            B[j]= A[j];
        }
        merge_sort(A,B,n);
        for(int k=0; k<n; k++){
            printf("%d ",A[k]);
            
        }
        printf("\n");
    }

    return 0;

}
