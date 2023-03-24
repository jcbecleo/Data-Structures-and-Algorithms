#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
    int elem;
    struct cell* next;
}*node;

typedef struct{
    node front;
    node rear;
}Queue;

void initQueue(Queue *Q);
int isEmpty(Queue Q);
void enqueue(Queue *Q, int elem);
void dequeue(Queue *Q);
int front(Queue Q);
void display(Queue* Q);

int main(){
    Queue Q;

    initQueue(&Q);

    enqueue(&Q, 1);
    enqueue(&Q, 4);
    enqueue(&Q, 7);
    enqueue(&Q, 2);

    display(&Q);

    dequeue(&Q);
    display(&Q);
    return 0;
}

void initQueue(Queue* Q){
    Q->front = NULL;
    Q->rear = NULL;
}

int isEmpty(Queue Q){
  return (Q.front == NULL) ? 1 : 0;  
}

void enqueue(Queue *Q, int elem){
    node temp;
    temp = (node)malloc(sizeof(struct cell));
    if(temp != NULL){
        temp->elem = elem;
        temp->next = NULL;
        if(isEmpty(*Q) == 1){
        Q->front = Q->rear = temp; 
    }else{
        Q->rear = Q->rear->next = temp;  
    }
 }
}

void dequeue(Queue *Q){
node temp;

if(isEmpty(*Q) == 0){
  temp = Q->front;
  Q->front = temp->next;
  free(temp);
  
  if(isEmpty(*Q) == 1){
    Q->rear = NULL;
    }
  }
  
}

int front(Queue Q){
  if(isEmpty(Q) == 0){
    return Q.front->elem;
    }
}

void display(Queue* Q){
Queue temp;
int num;
initQueue(&temp);

while(isEmpty(*Q) == 0){
  num = front(*Q);
  printf("%d", num);
  dequeue(Q);
  enqueue(&temp,num);
  }
printf("\n");
while(isEmpty(temp) == 0){
  num = front(temp);
  dequeue(&temp);
  enqueue(Q, num);
  }

}