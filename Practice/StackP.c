#include <stdio.h>
#define MAX 10

typedef struct{
    char elem[MAX];
    int top;
}Stack;

int main(){
    Stack S;
    return 0;
}

void push(Stack* S, char data){
    if(S->top == 0)
    printf("Stack is full.");

    S->elem[++(S->top)];
}

int pop(Stack* S){
    if(S->top == MAX-1)
    printf("Stack is empty.");

    return S->elem[(S->top)--];
}

void  display(Stack S){
    int i;
    for(i=0;i<=MAX-1;i++){
        printf("%d ", S.elem[S.top]);
    }
}