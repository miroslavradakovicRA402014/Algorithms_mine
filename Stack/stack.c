#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5

int push(int);
int pop();
int isEmpty();
int isFull();
int peak();
int* createStack(int);
void destroyStack(int*);
void printStack();


static int* top = NULL;
static int* topAdd = NULL;
static int* stack = NULL;

int main() {

   stack = createStack(STACK_SIZE);   
   topAdd = stack + 4;

   push(1);
   push(3);
   push(5);
   push(7);
   push(9);

   printf("Initial stack :\n\n");
   printStack();
/*
   printf("Afted adding 12. \n");
   push(12);
   push(15);
*/
   pop();
   pop();
   printf("Stack pop and pop :\n\n");  
   printStack();

   destroyStack(stack);

   return 0;
}

void printStack() {

  int* curr = top; 

  if (isEmpty()) {
    printf("Stack empty!Can't print element. \n");
  } else {
     for (; curr >= stack ; curr--) {
        printf(" %d \n",*curr);
     }
  }
  printf("\n\n");
}

int push(int el) {

   if (isEmpty()) {
    top = stack;
    *top = el;
    return el;
   } else {
      if (isFull()) {
         printf("Stack full!Can't push element. \n");
         return -1;
      } else {
         top++;
         *top = el;
         return -1;
      }
   }

}

int pop() {
   if (isEmpty()) {
      printf("Stack empty!Can't pop element.");
      return -1;
   } else {
      int el;
      el = peak();
      if (top == stack) {
        top = NULL;
      } else {
        top--;
      }
      return el;
   }
}
int peak() {
  
   if (isEmpty()) {
     printf("Stack empty !\n");
     return -1;
   } else {
     return *top;
   }

}

int* createStack(int size) {

   int* stack = (int*) calloc(size,sizeof(int));

   if (stack == NULL) {
      printf("ERROR: Don't enough RAM for stack ! \n");
      exit(1);
   }

   return stack;
}

void destroyStack(int* stack) {
   
    free(stack);
}

int isEmpty() {
   if (top == NULL) {
     return 1;
   } else {
     return 0;
   }

}

int isFull() {
   if (top == topAdd) {
     return 1;
   } else {
     return 0;
   }

}



