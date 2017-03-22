#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct {

int key;
struct nodeStruct* left;
struct nodeStruct* right;

} NODE;

NODE* createNewNode(int el);
void insertToHeap(NODE** root,NODE* new);
void deleteHeap(NODE** root);
NODE* searchNode(NODE* root,int el);
void printHeap(NODE* root,int level);
void addToHeap(NODE** root,int el);
//void insertToTree(NODE** root,NODE* new);

static NODE* root = NULL;

int main() {

   addToHeap(&root,5);
   addToHeap(&root,1);
   addToHeap(&root,7);
   addToHeap(&root,3);
   addToHeap(&root,9);
   addToHeap(&root,2);
/*
   printf("Initial heap: \n\n");
   printHeap(root,0);
   printf("\n\n");
*/


   deleteHeap(&root);


   return 0;
}

NODE* createNewNode(int el) {

   NODE* new = (NODE*) malloc(sizeof(NODE));
   new->key = el;
   new->left = NULL;
   new->right = NULL;
  
   if (new == NULL) {
     printf("ERROR:Don't enough RAM!");
     exit(1);   
   } 

   return new;

}

void deleteHeap(NODE** root) {

    if (*root != NULL) {
      deleteHeap(&((*root)->left));
      deleteHeap(&((*root)->right));
      free(*root);
    }

}

void addToHeap(NODE** root,int el) {

  if (!searchNode((*root),el)) {
    NODE* new = createNewNode(el);
    insertToHeap(root,new);
  } else {
    printf("\n%d exists can't add to heap! \n",el);
    return;
  }
}

NODE* searchNode(NODE* root,int el) {
  
    if (root != NULL) {
     if (root->key == el) {
       return root;
     } else if (root->key < el) {
       searchNode(root->right,el);
     } else {
       searchNode(root->left,el); 
     }
    } else {
     return NULL;
    }
}
/*
void insertToTree(NODE** root,NODE* new) {

    if (*root == NULL) {
      *root = new;
    } else if ((*root)->key > new->key) {
      insertToTree(&((*root)->left),new); 
    } else {
      insertToTree(&((*root)->right),new); 
    }
}
*/
void insertToHeap(NODE** root,NODE* new) {

    if (*root == NULL) {
      *root = new;
    } else if ((*root)->key > new->key) {
      insertToTree(&((*root)->left),new); 
    } else {
      insertToTree(&((*root)->right),new);
       if ((*root)->right > ) 
    }

}

