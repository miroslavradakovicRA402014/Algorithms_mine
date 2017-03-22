#include <stdio.h>

void printArray(int* arr);
void bubbleSort(int* arr);

static int len = 5;

int main() {

   int arr[] = {14,33,27,35,10};

   printf("Unsorted array : \n\n");
   printArray(arr);
 
   bubbleSort(arr);

   printf("\nSorted array :\n\n");
   printArray(arr);

   return 0;
}

void printArray(int* arr) {
   int i;

   for (i = 0; i < len; i++) {
     printf("A[%d] = %d \n",i,*(arr + i));
   }
}

void bubbleSort(int* arr) {
   int tmp,i,j;

   for (i = len; i > 0; i--) {
     for (j = 0; j < i; j++) {
        if (*(arr + j) > *(arr + j + 1)) {
          tmp = *(arr + j);
          *(arr + j) = *(arr + j + 1);
          *(arr + j + 1) = tmp;
        }
     }
   }

}
