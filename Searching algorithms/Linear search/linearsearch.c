#include <stdio.h>

void printArray(int* arr);
int linearSearch(int* arr,int el);

static int len = 10;
int main() {

   int arr[] = {10,14,19,26,27,31,33,35,42,44};

   printArray(arr);

   int ind;

   if ((ind = linearSearch(arr,31)) == -1) {
     printf("%d don't exist!",31);
   } else {
     printf("%d is on index %d .",31,ind);
   }     


   return 0;
}

void printArray(int* arr) {

    int i;

    printf("\n\n");

    for (i = 0; i < len ; i++) {
       printf("A[%d]= %d \n",i,*(arr + i));
    }

    printf("\n\n");
}

int linearSearch(int* arr,int el) {

   int i = 0;   

   for (;i < len ; i++) {
      if (*(arr + i) == el) {
        return i;
      }
   }

   return -1; 
}
