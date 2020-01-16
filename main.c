#include "trie.h"
#include <string.h>
int main(int argc, char *argv[]){
    Node* root = newNode();
    int index = 0;
    int max = 0;
    char* word = (char*)malloc(sizeof(char)*2); 
    *word = 0;
    *(word+ 1) = 0;  
    char letter;
        while (scanf("%c",&letter) == 1 ){
        if(letter != '\0' && letter != '\t' && letter != '\n' && letter != ',' && letter != ' '){
            word[index] = letter;
            index++;   
            word = (char*)realloc(word,index + 2);  
            for (int i = index; i < index + 2; i++){
                *(word + i) = 0;
            }       
        }else{
            insertNode(root,word);
            free(word);
            word = (char*)malloc(sizeof(char)*2);
                *word = 0;
             *(word+ 1) = 0; 
            if (index >= max){
                max = index;
            }
            index = 0;
        } 
      }
        if (index > 0){
            insertNode(root,word);
            free(word);
        }
        if (index == 0){
            free(word);
        }
        char length[max];
    if (argc == 1){
        printLexicography(root,length,0);
    }else if(argc == 2){
         if (strcmp(argv[1],"r")==0){
         printReverse(root,length,0);
         }
    }
         freeTrie(root);
    return 0;
}