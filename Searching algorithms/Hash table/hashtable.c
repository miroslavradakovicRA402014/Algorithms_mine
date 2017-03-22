#include <stdio.h>
#include <stdlib.h>
#define HASH_SIZE 10

typedef struct hashItem {
 int key;
 int data;
} HASH_ITEM;


void createHashTable();
void insertInHashTable(int data,int key);
HASH_ITEM* searchHashTable(int key);
int hashMethod(int key);
HASH_ITEM* createHashItem(int data,int key);
void printHashTable();
HASH_ITEM* deleteItem(int key);
//void destroyHashTable();

static HASH_ITEM** hashTable = NULL;

int main() {

   createHashTable();

   insertInHashTable(3,11);
   insertInHashTable(44,45); 
   insertInHashTable(11,30);

   deleteItem(45); 

   printHashTable();
/*
   HASH_ITEM* itm = searchHashTable(45);
   if (itm) {
     printf("Element with key 45 exist and value is %d. \n",itm->data);
   } else {
     printf("Element with key 45 don't exist.");
   }
*/
   return 0;
}

void printHashTable() {

   int i = 0;

   for (; i < HASH_SIZE; i++) {
    if (*(hashTable + i) && (*(hashTable + i))->key != -1) {
      printf(" (%d,%d) ",(*(hashTable + i))->key,(*(hashTable + i))->data);
    } else {
      printf(" empty ");
    }
   }
}

HASH_ITEM* createHashItem(int data,int key) {

  HASH_ITEM* item = (HASH_ITEM*) malloc(sizeof(HASH_ITEM));

  if (item == NULL) {
   printf("ERROR:Don't enough RAM for item! \n");
   exit(2); 
  }
  item->key = key;
  item->data = data;

  return item;
}

void createHashTable() {

  hashTable = (HASH_ITEM**) calloc(HASH_SIZE,sizeof(HASH_ITEM*));

  if (hashTable == NULL) {
    printf("ERROR:Don't enough RAM for hash table!\n");
    exit(1);
  }

  int i;
  for (i = 0; i < HASH_SIZE ; i++) {
    *(hashTable + i) = NULL;
  }

}

int hashMethod(int key) {
   return key % HASH_SIZE;
}

HASH_ITEM* searchHashTable(int key) {

  int hashIndex = hashMethod(key);

  while (*(hashTable + hashIndex) != NULL) {
    if ((*(hashTable + hashIndex))->key == key) {
      return *(hashTable + hashIndex);
    }
    hashIndex++;
    hashIndex %= HASH_SIZE;
   }

   return NULL;
}

void insertInHashTable(int data,int key) {
 
  HASH_ITEM* hashItm = createHashItem(data,key);
  
  int hashIndex = hashMethod(key);

  while (*(hashTable + hashIndex) != NULL && (*(hashTable + hashIndex))->key != -1) {
    hashIndex++;
    hashIndex %= HASH_SIZE;
  }
  
  *(hashTable + hashIndex) = hashItm;
}

HASH_ITEM* deleteItem(int key) {

  HASH_ITEM* deletedItem = searchHashTable(key);

  if (!deletedItem) {
    printf("Can't delete element because don't exist! \n");
    return NULL;
  } else {
    deletedItem->key = -1;
  }
  
  return deletedItem;
}
