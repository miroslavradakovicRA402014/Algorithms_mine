#include <stdio.h>

void printArray(int* arr);
int interpolationSearch(int* arr,int el,int low,int high);
void sortArray(int* arr);

static int len = 10;
int main() {

   int arr[] = {10,14,19,26,27,31,33,35,42,44};

   printArray(arr);
   sortArray(arr);

   int ind;

   if ((ind = interpolationSearch(arr,31,0,9)) == -1) {
     printf("%d don't exist!",31);
   } else {
     printf("%d is on index %d. \n",31,ind - 1);
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

void sortArray(int* arr) {

  int i,j;

  for (i = len; i > 0 ; i--) {
    for (j = 0; j < i; j++) {
      if (*(arr + j) > *(arr + j + 1)) {
        int tmp = *(arr + j);
        *(arr + j) = *(arr + j + 1);
        *(arr + j + 1) = tmp;
      }
    }
  }

}

int interpolationSearch(int* arr,int el,int low,int high) {
  
   int mid = low + ((high - low)/(*(arr + high) - *(arr + low)))*(el - *(arr + low));

   if (*(arr + mid) == el) {
      return mid;
   } else if (*(arr + mid) < el) {
      return interpolationSearch(arr,el,mid + 1,high);
   } else {
      return interpolationSearch(arr,el,low,mid - 1);
   }
   return -1;
}
