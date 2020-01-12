#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHABET 26
#define CASE 'a'
typedef enum {FALSE = 0, TRUE = 1} boolean;
//structor for Node:
typedef struct Node {
   boolean endOfWord ;
   long unsigned int counter;
   struct Node* parent;
   struct Node* children[ALPHABET];

}Node;

Node* newNode();
void insertNode(Node* tree, char* word);
void printLexicography(Node* root, char str[], int level);
void printReverse(Node* root, char str[], int level);
void freeTrie(Node* root);
boolean checkChar(char* c);