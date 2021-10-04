/**
 * Generate all subsets of a set comprised of 0 <= N ({0 1 2 3 ... N}).
 * 
 * @author Ytalo Ramon
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct _Stack{
    int posi, length;
    int *items;
} Stack;

int is_empty(Stack *stack);

void push(Stack *stack, int value);

int pop(Stack *stack);

void show_stack(Stack *stack);

void set_value_seq(Stack *stack, int start, int end);

void generate(Stack *stack, int max);

int main(int argc, char const *argv[]){
    
    int max = 6;
    Stack stack = {posi: -1, length: max, items: malloc(sizeof(int) * max + 1)} ;

    printf("----- All Subsets {0 ... %d} -----\n", max);
    set_value_seq(&stack, 0, max);
    if(max > 0) generate(&stack, max);
    printf("{ }\n");

    return 0;
}

int is_empty(Stack *stack){
    return stack->posi == -1;
}

void push(Stack *stack, int value){
    stack->items[++stack->posi] = value;
}

int pop(Stack *stack){
    return stack->items[stack->posi--];
}

void show_stack(Stack *stack){
    printf("{");
    for (int i = 0; i <= stack->posi; i++)
        printf(" %d", stack->items[i]);
    printf(" }\n");
}

void set_value_seq(Stack *stack, int start, int end){
    for (int i = start; i <= end; i++) push(stack, i);
}


void generate(Stack *stack, int max){
    show_stack(stack);
    int v = pop(stack), q;
    set_value_seq(stack, v + 1, max);

    if(!is_empty(stack))
        generate(stack, max);
}