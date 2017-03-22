#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct {
  int data;
  struct nodeStruct* next;
  struct nodeStruct* prev;
} NODE;

void addToList(NODE** head,int el);
NODE* createNewItem(int el);
//void insertToList(NODE** head,NODE* el);
void deleteElement(NODE** head);
void deleteList(NODE** head);
NODE* searchElement(NODE* head,int el);
int existElement(NODE* head,int el);
int isEmpty(NODE* head);
void printList(NODE* head);

int main() {

   NODE* head = NULL;

   addToList(&head,1);
   //printf("Added 1. \n");
   addToList(&head,3);
   //printf("Added 3. \n");
   addToList(&head,5);
   //printf("Added 5. \n");
   addToList(&head,7);
   //printf("Added 7. \n");
   addToList(&head,5);
 
   printf("Initial list : \n\n");
   printList(head);
/*
   printf("List after deleting last 2 elements : \n\n");
   deleteElement(&head);
   deleteElement(&head);
   printList(head);

*/
   printf("Search for element with value 12 .\n");
   NODE* sea = searchElement(head,12); 
   if (!sea) {
     printf("Exist !. \n");
   }

   deleteList(&head);
/* 
   printf("List after deleting : \n\n");
   printList(head);
*/
   return 0;
}
void printList(NODE* head) {
   if (isEmpty(head)) {
     printf(" HEAD -> NULL \n\n");
     return;
   }

   NODE* curr = head;
   printf(" NULL <-");

   while (curr != NULL) {
     printf("-> %d <-",curr->data);
     curr = curr->next;
   }

   printf("-> NULL \n\n");
}



NODE* searchElement(NODE* head,int el) {
   if (!existElement(head,el)) {
     printf("That element don't exist ! \n");
     return NULL;
   } 

   NODE* curr = head;

   while (curr != NULL) {
     if (curr->data == el) {
        return curr;   
     }
     curr = curr->next;
   }
   
}

int existElement(NODE *head,int el) {
  if (head != NULL) {
    NODE* curr = head;
    while (curr->next != NULL) {
       if (curr->data == el) {
         return 1;
       }
       curr = curr->next;
    }
   
    if (curr->data == el) {
      return 1;
    }  else {
      return 0;
    }
  } else {
    return 0;
  }
}

int isEmpty(NODE* head) {

  if (head == NULL) {
    return 1;
  } else {
    return 0;
  }

}

NODE* createNewItem(int el) {
     
  NODE* new = (NODE*) malloc(sizeof(NODE));

  if (new == NULL) {
    printf("ERROR: Don't enough RAM memory! \n");
    exit(1);
  }
  
  new->data = el;
  new->next = NULL;
  new->prev = NULL;

  return new;
}

void addToList(NODE** head,int el) {

  if (existElement((*head),el)) {
    printf("That element exist ! \n");
    return; 
  }

  NODE* new = createNewItem(el);

  if (isEmpty((*head))) {
     (*head) = new;
  } else {
     NODE* curr = (*head);
     while (curr->next != NULL) {
      curr = curr->next;
     }
     curr->next = new;
     new->prev = curr;
  }

}

void deleteElement(NODE** head) {


  if (isEmpty(*head)) {
    printf("List is empty ! \n");
    return;
  } 

  NODE* curr = (*head); 

  if (curr->next == NULL) {
     (*head) = NULL;
     free(curr);
  } else {
     while ((curr->next)->next != NULL) {
      curr = curr->next;
     }
     free(curr->next);
     curr->next = NULL;    
  }
 
}

void deleteList(NODE** head) {

  if ((*head)->next != NULL) {
     deleteList(&((*head)->next));
  } 

  free((*head)->next);
  *head = NULL;
  
}
