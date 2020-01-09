#include <stadio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE 26

//converts key of current character into index
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef enum{FALSE=0, TRUE=1}boolean;
int drop(const char* key);

typedef struct node{
char letter;
long unsigned int count;
struct node* children[ALPHABET_SIZE];
bool isEndOfWord;
}node;

///Initialized to NULLs 
struct node *getNode(void){
	struct node *pNode = NULL;
	pNode = (struct node *)malloc(sizeof(struct node));
	
	if(pNode){
	int i;
	pNode->isEndOfWord = 0;
		for(i=0; i<ALPHABET_SIZE; I++){
			pNode->cilderen[i] = NULL;
		}
	}
	return pNode;

//if its not present , inserts key into trie
//if the key is present , just marks leaf node
void insert(struct node *root , const char* key){
	int level;
	int length = strlen(key);
	int index;

	struct node *p = root;

	for(level = 0;level < length ; level++ ){
		index = CHAR_TO_INDEX(key[level]);
			if(!p->children[index]){
				p->children[index] = getNode();
			}
		p = p->children[index];
	}
	//marks last node as leaf
	p->isEndOfWork = 1;
}

//checks if the word is in the trie or not
bool search(struct node *root, const char *key){
	int level;
	int length = strlen(key);
	int index;

	struct node *p = root;
	
	for(level = 0;level < length ; level++ ){
		index = CHAR_TO_INDEX(key[level]);
			if(!p->children[index]){
				return 0;
			}
		p = p->children[index];
	}
	return (p ! = NULL && p->isEndOfWord);
	
}
