#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Trie.h"

#include <stdbool.h>







//prases the string and makes an array of VALID strings
size_t string_parser( const char *input, char ***word_array) {
    size_t n = 0;
    const char *p = input;

    while(*p) {
        while(isspace((unsigned char)*p)) ++p;
        n += *p != '\0';
        while(*p && !isspace((unsigned char)*p)) ++p;
    }

    if (n) {
        size_t i = 0;
        *word_array = malloc(n*sizeof(char *)); 
        p = input;
        while (*p) {
            while(isspace((unsigned char)*p)) ++p;
            if (*p)  {

                const char *q = p;
                while(*p && !isspace((unsigned char)*p)) ++p;

                size_t length = p - q;

                (*word_array)[i] = (char *)malloc(length + 1);
		
                strncpy((*word_array)[i],q,length);
                (*word_array)[i][length] = '\0';

                ++i;
            }
        }           
    }

    return n;
}  
void cleaner(char* input){
	int j=0;	
	//clean the input and validting it.
	for(int i=0;i<strlen(input);i++) {
			if(input[i]=='\0') break;
			if(input[i]=='\n') {
				input[j]='\n';
				j++;
			}	
			if(input[i]>96 && input[i]<123) { 
				input[j]=input[i];
                        	j++; 
                        }
			if(input[i]>64 && input[i]<91)  {
				input[j]=input[i]+32;
				j++; 
			}
			if(input[i]==' ') { 
				input[j] = ' ';
				j++; 
			}		
	}
	input[j]='\0';
}

int main(int argc, char* argv[]) {
	//init trie.
	struct TrieNode *root = getNode();
	if(root == NULL) exit(1); 

	//init strings that will help us deal with invalid chars.
	char ** word_array = NULL;
	char* input=NULL;
	char c;
	input = (char*)malloc(sizeof(char));
	
	
	//printf("Enter words:\n");
	int i=0; 
	int k=1;
	
 	while((c = fgetc(stdin)) != EOF) {
    	 	//realloc memory as string gets longer and longer.
   	 	input = (char*)realloc(input, k+ sizeof(char));
   	 	input[i] = c;
	
  	  	i++;
  	  	k++;
  	  	
  	}
  	

	//ends and makes the string a string.
  	input[i] = '\0'; 
	
	//cleans the input from invalid chars.
	cleaner(input);	
	
	//puts the input in a word array.
    	size_t n = string_parser(input, &word_array);
    	
    	//as we dont need the input anymore- we release the memory.
	free(input);
   	
   	//for ( size_t i = 0; i < n; i++ ) puts( word_array[i] ); 
	
	//each word in the array is inserted to the trie.
	for(int i=0;i<n;i++) {
		char *a = word_array[i];
		insert(root,a);

	}
	
	int l=0;
	char temp[n];
	if(argc!=2) display(root,temp,l);
	if(argc==2 && *argv[1]=='r') displayR(root,temp,l);
	printf("\n");
	
	//now all that is left is to clean the memory we used.
    	for ( size_t i = 0; i < n; i++ ) free ( word_array[i] );
    	free( word_array );
	freeALL(root);

	


return 0;
}
