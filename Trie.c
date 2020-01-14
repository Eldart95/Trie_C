#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE 26

//converts key of current character into index
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef enum{FALSE=0, TRUE=1}boolean;
int drop(char* key);

typedef struct node{
char letter;
long unsigned int count;
struct node* children[ALPHABET_SIZE];
_Bool isEndOfWord;
}node;

///Initialized to NULLs 
node *getNode() 
{	
	
	node *getNode;
    getNode = (node*) malloc(100*sizeof(node));
	if(getNode==NULL) exit(1);
	
	getNode->isEndOfWord = false;
    int i = 0;
    while(i<ALPHABET_SIZE){
        getNode->children[i] = NULL;
        i++;
	
    }
	
    return getNode; 
}

//if its not present , inserts key into trie
//if the key is present , just marks leaf node
void insert(struct node *root, char *key){
	
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
	p->isEndOfWord = 1;
	p->count++;
}

//checks if the word is in the trie or not
_Bool search(struct node *root, char *key){
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
	return (p != NULL && p->isEndOfWord);
	
}

//prints the word that we are looking for
void printWord(char cahrs[],int len, int count){
	for(int i =0; i<len ;i++){
		printf("%c",i);
	}
	printf("%d ", count);
	printf("\n");
}
