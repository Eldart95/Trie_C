#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>



#define NUM_LETTERS ((int)26)
int drop(const char* x);
typedef enum { FALSE=0,TRUE=1} boolean;

typedef struct node {
char letter;
long unsigned int count;
struct node* children[NUM_LETTERS];
} node;

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






int main() {
	char ** word_array = NULL;
	char input[909090];
	char fixed[909090];
	printf("Enter words:\n");
  	scanf ("%[^\n]%*c", input);
		//MAKE FUNC OUT OF THIS CARP
	for(int i=0;i<909090;i++) {
			if(input[i]>96 && input[i]<123) fixed[i]=input[i];
			if(input[i]>64 && input[i]<91) fixed[i]=input[i]+32;
			if(input[i]==32) fixed[i]==32;
			if(input[i]==' ') fixed[i] = ' ';
	}
	
	
    	size_t n = string_parser( fixed, &word_array );

   	for ( size_t i = 0; i < n; i++ ) puts( word_array[i] );
    	for ( size_t i = 0; i < n; i++ ) free( word_array[i] );
    	free( word_array );


	


return 0;
}
