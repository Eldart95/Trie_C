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

    while ( *p ) {
        while ( isspace( ( unsigned char )*p ) ) ++p;
        n += *p != '\0';
        while ( *p && !isspace( ( unsigned char )*p ) ) ++p;
    }

    if ( n ) {
        size_t i = 0;

        *word_array = malloc( n * sizeof( char * ) ); 

        p = input;

        while ( *p ) {
            while ( isspace( ( unsigned char )*p ) ) ++p;
            if ( *p )  {
		
		
		
		
                const char *q = p;
                while ( *p && !isspace( ( unsigned char )*p ) ) ++p;

                size_t length = p - q;

                ( *word_array )[i] = ( char * )malloc( length + 1 );
		
                strncpy( ( *word_array )[i], q, length );
                ( *word_array )[i][length] = '\0';

                ++i;
            }
        }           
    }

    return n;
}  

		





int main(int argc, char* argv[]) {
	node* root=NULL;
	root=getNode();
	if(root == NULL) exit(1);
	if(argc==2) { 
	char T = *argv[1];
	//printf("%s",a);
	} 
	if(argc>2) {
	printf("Error");
	exit(1);
	}
	
	char ** word_array = NULL;
	char* input=NULL;
	char c;
	input = (char*)malloc(sizeof(char));
	
	
	printf("Enter words:\n");
	int i=0; int k=1;
 	 while (c != '\n' ) {
    // read the input from keyboard standard input
   	 c = getc(stdin);
	
    // re-allocate (resize) memory for character read to be stored
   	 input = (char*)realloc(input, k * sizeof(char));

    // store read character by making pointer point to c
   	 input[i] = c;
	
  	  i++;
  	  k++;
  }
	
  	input[i] = '\0'; 
	
	
		//MAKE FUNC OUT OF THIS CARP
	int j=0;	
	//clean the input and validting it.
	for(int i=0;i<strlen(input);i++) {
			if(input[i]=='\0' || input[i]=='\n') break;
			if(input[i]>96 && input[i]<123) { 
			input[j]=input[i];
                        j++; }
			if(input[i]>64 && input[i]<91)  {
			input[j]=input[i]+32;
			j++; }
			if(input[i]==' ') { 
			input[j] = ' ';
			j++; }		
	}
	input[j]='\0';
	
	
    	size_t n = string_parser( input, &word_array );
	 free(input);
   	//for ( size_t i = 0; i < n; i++ ) puts( word_array[i] ); //prints the array 
	//cut the array to strings and each string to chars.
	//each char goes into the trie 
	for(int i=0;i<n;i++) {
		char *a = word_array[i];
	
		for(int i=0;i<strlen(a);i++) {
			
			char b = a[i];
			//printf("%c\n",b);
			//HERE: SEND EACH CHAR TO THE TRIE
			//LET ALEX DO HIS MAGIC
			
			insert(*root,&b);
			
			
		}
	}
	//printWord(*word_array,n);
    	for ( size_t i = 0; i < n; i++ ) free( word_array[i] );
    	free( word_array );
	free(root);

	


return 0;
}
