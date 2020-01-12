#include "trie.h"



//initiate Node:
Node* newNode(){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode -> endOfWord = FALSE;
    newNode -> counter = 0;
    newNode -> parent = NULL;
    for (int i=0;i<ALPHABET;i++){
        newNode -> children[i] = NULL;
    }
    return newNode;
}
//make Tree from string
void insertNode(Node* tree, char* word){
   if (checkChar(word)){
    Node* currentNode = tree;
    while (*word != '\0' && *word != '\t' && *word != '\n' && *word != ' '){
        if (*word >= 65 && *word <= 122){  //checks if charachter is a letter
            *word = tolower(*word);
            if (currentNode -> children[*word - CASE] == NULL){
            currentNode -> children[*word - CASE] = newNode();
            currentNode -> children[*word - CASE] -> parent = currentNode;
            }
            currentNode = currentNode -> children[*word - CASE];
        }
        word++;
    }
    currentNode -> counter++;
    currentNode -> endOfWord = TRUE;
   }
}
//print in a-z order
void printLexicography(Node* root, char str[], int level){
    
    if (root -> endOfWord){
        str[level] ='\0';
        printf("%s", str);
        printf(" %lu\n", root -> counter);
    }
    int i;
    for(i = 0; i < ALPHABET; i++){
        if (root -> children[i]){
            str[level] = i + 'a';
            printLexicography((root -> children[i]),str,level + 1);
        }
    }
}
//print in z-a order
void printReverse(Node* root, char str[], int level){
    
    if (root -> endOfWord){
        str[level] ='\0';
        printf("%s", str);
        printf(" %lu\n", root -> counter);
    }
    int i;
    for(i = ALPHABET-1; i >= 0; i--){
        if (root -> children[i]){
            str[level] = i + 'a';
            printReverse((root -> children[i]),str,level + 1);
        }
    }
}
void freeTrie(Node* root){
    for (int i = 0; i < ALPHABET; i++ ){
        if(root -> children[i] != NULL){
            freeTrie(root -> children[i]);
        }
    }
    if (root != NULL){
        free(root);
    }
}
//checks if the letter is a valid one (from a-z)
boolean checkChar(char* c){
    if (*c != '\0' && *c != '\t' && *c != '\n' && *c != ' ' && *c != '_'){
        //if (*c>= 65 && *c <= 122){
            return TRUE;
      //  }
    }
    return FALSE;
}
