#ifndef _FIND_H_
#define _FIND_H_
#include <stdbool.h>
#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
//converts key of current character into index
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
int drop( char* key);
typedef enum{FALSE=0, TRUE=1}boolean;
typedef struct node* node;
node *getNode(); 
void insert(struct node *root, char *key);
_Bool search(struct node *root, char *key);
void printWord(char cahrs[],int len);













#endif
