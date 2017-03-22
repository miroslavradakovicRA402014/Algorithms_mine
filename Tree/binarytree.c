#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct {

int key;
struct nodeStruct* left;
struct nodeStruct* right;

} NODE;

NODE* createNewNode(int el);
void insertToTree(NODE** root,NODE* new);
void deleteTree(NODE** root);
NODE* searchNode(NODE* root,int el);
void printTree(NODE* root,int level);
void addToTree(NODE** root,int el);
void inorderTransversal(NODE* root);
void preorderTransversal(NODE* root);
void postorderTransversal(NODE* root);

static NODE* root = NULL;

int main() {

   addToTree(&root,5);
   addToTree(&root,1);
   addToTree(&root,7);
   addToTree(&root,3);
   addToTree(&root,9);
   addToTree(&root,2);
/*
   printf("Initial tree: \n\n");
   printTree(root,0);
   printf("\n\n");
/*
   if (searchNode(root,3)) {
     printf("Element exist. \n");
   } else {
     printf("Element don't exist. \n");
   }
*/  
   printf("Inorder transversal : \n\n");
   inorderTransversal(root);
   printf("\n\n");

   printf("Preorder transversal : \n\n");
   preorderTransversal(root);
   printf("\n\n");

   printf("Postorder transversal : \n\n");
   postorderTransversal(root);
   printf("\n\n");

   deleteTree(&root);


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

void insertToTree(NODE** root,NODE* new) {

    if (*root == NULL) {
      *root = new;
    } else if ((*root)->key > new->key) {
      insertToTree(&((*root)->left),new); 
    } else {
      insertToTree(&((*root)->right),new); 
    }

}

void addToTree(NODE** root,int el) {

  if (!searchNode((*root),el)) {
    NODE* new = createNewNode(el);
    insertToTree(root,new);
  } else {
    printf("\n%d exists can't add to tree! \n",el);
    return;
  }
}

void printTree(NODE* root,int level) {

    if (root != NULL) {
       printf("Level %d,element %d. \n",level,root->key);
       printTree(root->left,level+1);
       printTree(root->right,level+1);
    }
}

void deleteTree(NODE** root) {

    if (*root != NULL) {
      deleteTree(&((*root)->left));
      deleteTree(&((*root)->right));
      free(*root);
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

void inorderTransversal(NODE* root) {

   if (root != NULL) {
    inorderTransversal(root->left);
    printf(" %d ",root->key);
    inorderTransversal(root->right);
   }
}

void preorderTransversal(NODE* root) {

   if (root != NULL) {
     printf(" %d ",root->key);
     preorderTransversal(root->left);
     preorderTransversal(root->right);
   }

}

void postorderTransversal(NODE* root) {

   if (root != NULL) {
     postorderTransversal(root->left);
     postorderTransversal(root->right);
     printf(" %d ",root->key);
   }
}
