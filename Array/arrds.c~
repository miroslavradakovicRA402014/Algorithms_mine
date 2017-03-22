#include <stdio.h>

void insertElement(int* arr,int pos,int el);
void deleteElement(int* arr,int pos);
int searchElement(int* arr,int el);
void printArray(int* arr);

static int len = 5; 

int main() {

   int arr[] = {1,2,3,4,5};

   printf("\n\n");

   printf("Array before operations : \n");
   printArray(arr);

   
   printf("After adding 6 on pos 2 : \n");
   insertElement(arr,2,6);
   printArray(arr);
   

   
   printf("After deleting element on pos 3 :\n");
   deleteElement(arr,3);
   printArray(arr);
   

   
   printf("Search for element with value 2 : \n");
   if (searchElement(arr,2) == -1) {
      printf("Don't exist that element ! \n");
   } else {
      printf("This element is on position %d .\n",searchElement(arr,2));
   }
   

   return 0;
}

void printArray(int *arr) {

  int i ;

  for (i = 0; i < len ; i++) {
      printf("Array[%d] = %d \n",i,*(arr + i));
  }

  printf("\n\n");
}

void insertElement(int *arr,int pos,int el) {

  if (pos > len || pos < 0) {
     printf("ERROR:Can't insert element to %d position !",pos);
     return;
  }

  int i;

  for (i = len; i > pos ; i-- ) {
    *(arr + i) = *(arr + i -1);
  }

  *(arr + pos) = el;
  len++; 

}

void deleteElement(int *arr,int pos) {

  if (pos >= len || pos < 0) {
     printf("ERROR:Can't delete element form %d position !",pos); 
     return;
  }

  int i ;

  for (i = pos ; i < len - 1 ; i++) {
    *(arr + i) = *(arr + i + 1);
  }

  len--;
}

int searchElement(int *arr,int el) {
  
  int ind = -1,i;

  for (i = 0; i < len ; i++) {
     if (*(arr + i) == el) {
      ind = i;
      return ind;
     }
  }
  
  return ind;
}
