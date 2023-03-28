#include <stdio.h>
#define MAX 10

typedef struct{
    char elem[MAX];
    int top;
}Stack;

void initStack(Stack* S);
void push(Stack* S, char data);
int pop(Stack* S);
void display(Stack S);
int isFull(Stack S);
int isEmpty(Stack S);

int main(){
    Stack S;
    initStack(&S);
    ]
    return 0;
}

void initStack(Stack* S){
    S->top = -1;
}

void push(Stack* S, char data){
    if(S->top == 0)
    printf("Stack is full.");

    S->elem[++(S->top)] = data;
}

int pop(Stack* S){
    if(S->top == MAX-1)
    printf("Stack is empty.");

    return S->elem[(S->top)--];
}

void display(Stack S){
    int i;
    for(i=0;i<=MAX-1;i++){
        printf("%d ", S.elem[i]);
    }
}

int isFull(Stack S){
    (S.top == 0) ? 1 : 0;
}

int isEmpty(Stack S){
    (S.top == MAX-1) ? 1 : 0;
}