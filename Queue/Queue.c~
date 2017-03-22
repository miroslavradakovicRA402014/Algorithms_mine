#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5

int enqueue(int);
int dequeue();
int isEmpty();
int isFull();
int front();
int* createQueue(int);
void destroyQueue(int*);
void printQueue();


static int* qBegin = NULL;
static int* qEnd = NULL;
static int* queue = NULL;
static int* rear = NULL;

int main() {

   queue = createQueue(QUEUE_SIZE);  
   qEnd = queue + 4;
   qBegin = queue;


   printf("Initial queue :\n\n");
   enqueue(1);
   enqueue(3);
   enqueue(5);
   enqueue(7);
   enqueue(9);
   //enqueue(12);
   printQueue();

   dequeue();
   dequeue();
   
   printf("Stack dequeue and dequeue :\n\n");  
   printQueue();

   printf("Front element is %d \n.",front());

   destroyQueue(queue);

   return 0;
}

void printQueue() {

  int* curr = qBegin; 

  if (isEmpty()) {
    printf("Queue empty!Can't print elements. \n");
  } else {
     for (; curr <= rear ; curr++) {
        printf(" %d ",*curr);
     }
  }
  printf("\n\n");
}

int enqueue(int el) {

   if (isEmpty()) {
    rear = queue;
    *rear = el;
    return el;
   } else {
      if (isFull()) {
         printf("Queue full!Can't enqueue element. \n");
         return -1;
      } else {
         rear++;
         *rear = el;
         return -1;
      }
   }

}

int dequeue() {
   if (isEmpty()) {
      printf("Queue empty!Can't dequeue element.");
      return -1;
   } else {
      int el;
      el = *qBegin;
      if (rear == queue) {
        rear = NULL;
      } else {
        rear--;
      }
      return el;
   }
}
int front() {
  
   if (isEmpty()) {
     printf("Queue empty !\n");
     return -1;
   } else {
     return *qBegin;
   }

}

int* createQueue(int size) {

   int* queue = (int*) calloc(size,sizeof(int));

   if (queue == NULL) {
      printf("ERROR: Don't enough RAM for queue ! \n");
      exit(1);
   }

   return queue;
}

void destroyQueue(int* queue) {
   
    free(queue);
}

int isEmpty() {
   if (rear == NULL) {
     return 1;
   } else {
     return 0;
   }

}

int isFull() {
   if (rear == qEnd) {
     return 1;
   } else {
     return 0;
   }

}

