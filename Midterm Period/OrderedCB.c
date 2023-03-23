#include <stdio.h>

#define MAX 100

typedef struct {
  int data;
  int next;
} elem;

typedef struct {
  elem list[MAX];
  int available;
  int start;
} VirtualHeap;

VirtualHeap initializeCB() {
  VirtualHeap heap;

  heap.available = MAX-1;
  heap.start = -1;

  int count;
  for (count=MAX-1 ; count!=-1 ; count--) {
    heap.list[count].next = count-1;
  }

  return heap;
} 

void insertCB(VirtualHeap* heap, int data) {
  if (heap->available == -1) return;
  
  int temp, *trav;

  for (trav=&heap->start ; *trav!=-1 && data>heap->list[*trav].data; trav=&heap->list[*trav].next) {}

  temp = heap->available;

  heap->available = heap->list[temp].next;

  heap->list[temp].data = data;
  heap->list[temp].next = *trav;

  *trav = temp;
}

int deleteCB(VirtualHeap* heap, int data) {
  int temp, *trav;

  for (trav=&heap->start ; *trav!=-1 && heap->list[*trav].data!=data ; trav=&heap->list[*trav].next) {}

  if (*trav == -1) return data-1;

  temp = *trav;
  *trav = heap->list[*trav].next;
  
  heap->list[temp].next = heap->available;
  heap->available = temp;

  return data;
}

void updateCB(VirtualHeap* heap, int removed, int updated) {
  if (deleteCB(heap, removed) == removed) {
    insertCB(heap, updated);
  }
}

void showCB(VirtualHeap heap) {
  int trav;

  for (trav=heap.start ; trav!=-1 ; trav=heap.list[trav].next) {
    printf("%d ", heap.list[trav].data);
  }
}

int main() {
  VirtualHeap heap = initializeCB();

  printf("Initial content of CB: ");
  insertCB(&heap, 5);
  insertCB(&heap, 2);
  insertCB(&heap, 10);
  insertCB(&heap, 31);
  insertCB(&heap, 1);
  showCB(heap);

  printf("\nContent of CB after Deletion: ");
  deleteCB(&heap, 2);
  deleteCB(&heap, 5);
  showCB(heap);

  printf("\nContent of CB after Update: ");
  updateCB(&heap, 10, 12);
  updateCB(&heap, 31, 22);
  showCB(heap);

  return 0;
}