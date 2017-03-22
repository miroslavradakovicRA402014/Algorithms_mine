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
 
   //addToList(&head,5);
 
   printf("Initial list : \n\n");
   printList(head);

   printf("List after deleting last 2 elements : \n\n");
   deleteElement(&head);
   deleteElement(&head);
   printList(head);



   printf("Search for element with value 5 .\n");
   NODE* sea = searchElement(head,5); 
   if (sea) {
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
  //S printf(" HEAD -> %d ",(head->prev)->data);

   while (curr->next != head) {
     printf(" %d <--> ",curr->data);
     curr = curr->next;
   }
   printf(" %d \n\n",head->prev->data);
   //SSprintf("-> %d \n\n",head->data);
}



NODE* searchElement(NODE* head,int el) {
/*
   if (!existElement(head,el)) {
     printf("That element don't exist ! \n");
     return NULL;
   } 
*/
   NODE* curr = head->prev;

   while (curr != head) {
     if (curr->data == el) {
        return curr;   
     }
     curr = curr->prev;
   }
   
}

int existElement(NODE *head,int el) {
  if (head != NULL) {
    NODE* curr = head;
    while (curr->next != head) {
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
  new->next = new;
  new->prev = new;

  return new;
}

void addToList(NODE** head,int el) {
/*
  if (existElement((*head),el)) {
    printf("That element exist ! \n");
    return; 
  }
*/
  NODE* new = createNewItem(el);

  if (isEmpty((*head))) {
     (*head) = new;
     //printf("Checkpoint0. \n");
  } else {
     //printf("Checkpoint1. \n");
     NODE* curr = (*head);
     while (curr->next != (*head)) {
      curr = curr->next;
     }
     //printf("Checkpoint2. \n");
     curr->next->prev = new;
     curr->next = new;
     new->prev = curr;
     new->next = (*head);
   
  }
  //printf("Checkpoint3. \n");

}

void deleteElement(NODE** head) {


  if (isEmpty(*head)) {
    printf("List is empty ! \n");
    return;
  } 

  NODE* curr = (*head); 

  if (curr->next == (*head) && curr->prev == (*head)) {
     (*head) = NULL;
     free(curr);
  } else {
     while ((curr->next)->next != (*head)) {
      curr = curr->next;
     }
     (*head)->prev = curr;
     free(curr->next);
     curr->next = (*head);    
  }
 
}

void deleteList(NODE** head) {

   while ((*head)->next != (*head)) {
     (*head) = (*head)->next;
     (*head)->prev = ((*head)->prev)->prev;
     free(((*head)->prev)->next);
     ((*head)->prev)->next = (*head);
   }
   free(*head);
   *head = NULL;
  
}
