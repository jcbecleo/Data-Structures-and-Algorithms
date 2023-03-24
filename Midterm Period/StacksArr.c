#include <stdio.h>
#define MAX 20

//stack grows from 0 to MAX-1

typedef struct{
    int elem[MAX];
    int top;
}Stack;

void initStack(Stack* S);
void push(Stack* S, int data);
int pop(Stack* S);
void display(Stack S);

int main(){
    Stack S;

    initStack(&S);

    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);

    display(S);

    return 0;
}

void initStack(Stack* S){
    S->top = -1;
}

void push(Stack* S, int data){
    if(S->top == MAX-1){
        printf("Stack is full.\n");
    }

    S->elem[++(S->top)] = data;
}

int pop(Stack* S){
    if(S->top == -1)
    printf("Stack is empty.\n");

    S->elem[S->top];
    return S->elem[(S->top)--];
}

void display(Stack S){
    int i;
    for(i=0; i<=S.top;i++){
        printf("%d ", S.elem[i]);
    }
}