#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}*Stack;

void initStack(Stack* S);
void push(Stack* S, int n);
void pop(Stack* S);
int top(Stack S);
int isEmpty(Stack S);
void display(Stack* S);

int main(){
    Stack S;
    initStack(&S);

    push(&S, 1);
    push(&S, 2);
    push(&S, 3);

    display(&S);
    return 0;
}

void initStack(Stack* S){
    *S = NULL;
}

void push(Stack* S, int n){
    Stack temp;
    temp = (Stack)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = n;
        temp->next = *S;
        *S = temp;
    }
}

void pop(Stack* S){
    if(*S != NULL){
        Stack temp;
        temp = *S;
        *S = (*S)->next;
        free(temp);
    }
}

int top(Stack S){
    return S->data;
} 

int isEmpty(Stack S){
  return (S != NULL) ? 0: 1;
}

void display(Stack* S){
    Stack temp;
    int n;
    initStack(&temp);
    while(isEmpty(*S) == 0){
    n = top(*S);
    printf("%d ", n);
    pop(S);
    push(&temp, n);
    }
    while(isEmpty(temp) == 0){
    n = top(temp);
    pop(&temp);
    push(S, n);
    }  
}
