#include <stdio.h>

void printArray(int* arr);
void mergeSort(int* arr,int n);
void merge(int* arr,int* leftArr,int* rightArr,int nRight,int nLeft);


static int len = 9;

int main() {

   int arr[] = {14,33,27,35,10,19,42,44,11};

   printf("Unsorted array : \n\n");
   printArray(arr);
 
   mergeSort(arr,len);

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

void merge(int* arr,int* leftArr,int* rightArr,int nRight,int nLeft) {
  int i = 0,j = 0,k = 0;

  while (i < nLeft && j < nRight) {
    if (*(leftArr + i) > *(rightArr + j)) {
      *(arr + k) = *(leftArr + i);
      i++;
    } else {
      *(arr + k) = *(rightArr + j);
      j++;
    }
    k++;
  }

  while (i < nLeft) {
    *(arr + k) = *(leftArr + i);
    i++;
    k++;  
  }

  while (j < nRight) {
    *(arr + k) = *(rightArr + j);
    j++;
    k++;  
  }
}

void mergeSort(int* arr,int n) {

   if (n == 1 || n == 0) {
     return;
   }

   int i,j,leftSA[n - n/2],rightSA[n/2];

   for (i = 0; i < n - n/2; i++) {
     *(leftSA + i) = *(arr + i);
   }
  
   for (j = 0,i = n - n/2; i < n; i++,j++) {
     *(rightSA + j) = *(arr + i);
   }

   mergeSort(leftSA,n - n/2);
   mergeSort(rightSA,n/2);
   merge(arr,leftSA,rightSA,n/2,n - n/2);
}
