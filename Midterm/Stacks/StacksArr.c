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
int isFull(Stack S);
int isEmpty(Stack S);

int main(){
    Stack S;
    
    initStack(&S);

    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);

    display(S);

    printf("%d\n", pop(&S));

    Stack D;

    initStack(&D);
    
    printf("%d\n", isEmpty(D));
    return 0;
}

void initStack(Stack* S){
    S->top = -1;
}

void push(Stack* S, int data){
    if(S->top == MAX-1) //to check if stack is full
    printf("Stack is full.\n");

    S->elem[++(S->top)] = data;
}

int pop(Stack* S){
    if(S->top == -1) // to check is stack is empty
    printf("Stack is empty.\n");

    return S->elem[(S->top)--];
}

void display(Stack S){
    int i;
    for(i=0; i<=S.top;i++){
        printf("%d ", S.elem[i]);
    }

    printf("\n");
}

int isFull(Stack S){
    return (S.top == MAX-1) ? 1 : 0;
}

int isEmpty(Stack S){
    return (S.top == -1) ? 1 : 0;
}