#include <stdio.h>
#define MAX 15

typedef struct{
    int data[MAX];
    int front;
    int rear;
}Queue;

void initQueue(Queue *Q);
void enqueue(Queue *Q, int num);
void dequeue(Queue *Q);
int front(Queue Q);
int isEmpty(Queue Q);
void display(Queue* Q);

int main(){
    Queue kyu;

    initQueue(&kyu);

    enqueue(&kyu, 1);
    enqueue(&kyu, 2);
    enqueue(&kyu, 3);
    enqueue(&kyu, 4);
    enqueue(&kyu, 5);

    dequeue(&kyu);
    return 0;
}

void initQueue(Queue* Q){
    Q->front =1;
    Q->rear = 0;
}

void enqueue(Queue* Q, int elem){
    if(Q->front == (Q->rear+2) % MAX) //to check if queue is full
    printf("Queue is full.");

    Q->data[Q->rear] = elem;
    Q->rear = (Q->rear) % MAX;
}

void dequeue(Queue* Q){
    if(Q->front == (Q->rear+1) % MAX)
    printf("Queue is empty.");

    Q->front = (Q->front+1) % MAX;
}

int front(Queue Q){
    return Q.front;
}

int isEmpty(Queue Q){
    return (Q.front == (Q.rear+2) % MAX) ? 1: 0;
}

