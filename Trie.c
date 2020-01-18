#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
  
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) 
  
// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (26) 
  
// Converts key current character into index 
// use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
    int count;
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 

void reverseString(char* str) 
{ 
  
    if (str == 0)
    {
        return; // if empty - return
    }

    
    if (*str == 0)
    {
        return; // if empty - return
    }

  
    char *start = str;
    char *end = start + strlen(str) - 1; 
    char temp;

    /* reverse */
    while (end > start)
    {
        /* swap */
        temp = *start;
        *start = *end;
        *end = temp;

        /* move */
        ++start;
        --end;
    }

}
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode = NULL; 
  
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode)); 
  
    if (pNode) 
    { 
        int i; 
  
        pNode->isEndOfWord = false; 
  
        for (i = 0; i < ALPHABET_SIZE; i++) 
            pNode->children[i] = NULL; 
    } 
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just marks leaf node 
void insert(struct TrieNode *root,char *key) 
{ 
    int level; 
    int length = strlen(key); 
    int index; 
  
    struct TrieNode *temp_node = root; 
  
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(key[level]); 
        if (!temp_node->children[index]) 
            temp_node->children[index] = getNode(); 
  
        temp_node = temp_node->children[index]; 
    } 
  
    // mark last node as leaf 
    temp_node->isEndOfWord = true; 
    // increment value of word that ends
    temp_node->count+=1;
} 
bool search(struct TrieNode *root,char *key) 
{ 
    int level; 
    	
    int length = strlen(key); 
    int index; 
    struct TrieNode *temp_node = root; 
  
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(key[level]); 
  
        if (!temp_node->children[index]) 
            return false; 
  
        temp_node = temp_node->children[index]; 
	
	
    } 
  
    return (temp_node != NULL && temp_node->isEndOfWord); 
} 

bool isLeafNode(struct TrieNode* root) 
{ 
    return root->isEndOfWord != false; 
} 
void display(struct TrieNode* root, char str[], int level) 
{ 
    // If node is leaf node, it indicates end 
    // of string, so a null character is added 
    // and string is displayed 
    if (isLeafNode(root))  
    { 
	
        str[level] = '\0'; 
        printf("%s %d\n",str,root->count); 
    } 
  
    int i; 
    for (i = 0; i < ALPHABET_SIZE; i++)  
    { 
        // if NON NULL child is found 
        // add parent key to str and 
        // call the display function recursively 
        // for child node 
        if (root->children[i])  
        { 
            str[level] = i + 'a'; 
            display(root->children[i], str, level + 1); 
        } 
    } 
} 
//display in reverse
void displayR(struct TrieNode* root, char str[], int level) 
{ 
	
  // If node is leaf node, it indicates end 
    // of string, so a null character is added 
    // and string is displayed 
    if (isLeafNode(root))  
    { 
	
        str[level] = '\0'; 
	char str2[strlen(str)];
	strcpy(str2,str);
	reverseString(str2); // manipulation on the string
        printf("%s %d\n",str2,root->count);
	
	
    } 
  
    int i; 
    for (i = 0; i < ALPHABET_SIZE; i++)  
    { 
        // if NON NULL child is found 
        // add parent key to str and 
        // call the display function recursively 
        // for child node 
        if (root->children[i])  
        { 
            str[level] = i + 'a'; 
            displayR(root->children[i], str, level + 1); 
        } 
    } 
} 
//free all memory and delete tree
void freeALL(struct TrieNode* root) { 
	if(!root) return;
	for(int i=0;i<ALPHABET_SIZE;i++) {
		freeALL(root->children[i]);
	}
	free(root);
}


