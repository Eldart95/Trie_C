#ifndef _FIND_H_
#define _FIND_H_
#include <stdbool.h>
#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
//converts key of current character into index
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])


struct TrieNode* getNode(void);

void insert(struct TrieNode *root,char *key);
_Bool search(struct TrieNode *root,char *key);
bool isLeafNode(struct TrieNode* root);
void display(struct TrieNode* root, char str[], int level);
void displayR(struct TrieNode* root, char str[], int level);
void freeALL(struct TrieNode* root);











#endif
