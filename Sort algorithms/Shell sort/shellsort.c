#include <stdio.h>

void printArray(int* arr);
void shellSort(int* arr);


static int len = 9;

int main() {

   int arr[] = {14,33,27,35,10,19,42,44,11};

   printf("Unsorted array : \n\n");
   printArray(arr);
 
   shellSort(arr);

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

void shellSort(int* arr) {

  int j,i,interval = 1,key;
  
  while (interval < len/3) {
    interval = interval*3 + 1;
  }

  while (interval > 0) {
   for (i = interval; i < len ; i++) {
     key = *(arr + i);
     j = i;
     while (j > interval - 1 && *(arr + j - interval) > key ) {
        *(arr + j) = *(arr + j - interval);
        j -= interval;
     }
     *(arr + j) = key;
   }
   interval = (interval - 1)/3;
  }

}
