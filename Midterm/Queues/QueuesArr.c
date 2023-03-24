#include <stdio.h>
#define MAX 5

typedef struct{
  int elem[MAX];
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
    Queue Q;
    initQueue(&Q);

    enqueue(&Q, 1);
    enqueue(&Q, 2);
    enqueue(&Q, 3);
    enqueue(&Q, 4);

    display(&Q);

    return 0;
}

void initQueue(Queue* Q){
    Q->front = 1;
    Q->rear = 0;
}

void enqueue(Queue* Q, int num){
    if(Q->front == (Q->rear+2) % MAX) //to check if queue is full
    printf("Queue is full.\n");

    Q->rear = (Q->rear+1) % MAX;
    Q->elem[Q->rear] = num;
}

void dequeue(Queue* Q){
    if(Q->front == (Q->rear+1) % MAX) //to check if queue is empty
    printf("Queue is empty.\n");

    Q->front = (Q->front+1) % MAX;
}

int front(Queue Q){
    return Q.elem[Q.front];
}

int isEmpty(Queue Q){
  return (Q.front == (Q.rear+1) % MAX) ? 1 : 0;  
}

void display(Queue* Q){
    Queue temp;
    int num;

    while(isEmpty(*Q)==0){
        num = front(*Q);
        printf("%d ", front(*Q));
        dequeue(Q);
        enqueue(&temp, num);
    }

    while(isEmpty(temp)==0){
        num = front(temp);
        dequeue(&temp);
        enqueue(Q, num);
    }
}
