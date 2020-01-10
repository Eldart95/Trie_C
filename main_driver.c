#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

		





int main() {
	char ** word_array = NULL;
	char input[9090];
	char fixed[9090]; //NEED TO BE DYNAMICLLY ALLOCATED
	printf("Enter words:\n");
  	scanf ("%[^\n]%*c", input);
		//MAKE FUNC OUT OF THIS CARP
	int j=0;
	for(int i=0;i<9090;i++) {
			if(input[i]>96 && input[i]<123) { 
			fixed[j]=input[i];
                        j++; }
			if(input[i]>64 && input[i]<91)  {
			fixed[j]=input[i]+32;
			j++; }
			if(input[i]==' ') { 
			fixed[j] = ' ';
			j++; }		
	}
	
	
    	size_t n = string_parser( fixed, &word_array );

   	//for ( size_t i = 0; i < n; i++ ) puts( word_array[i] ); //prints the array 
	for(int i=0;i<n;i++) {
		char *a = word_array[i];
	
		for(int i=0;i<strlen(a);i++) {
			char b = a[i];
			printf("%c\n",b);
		}
	}
    	for ( size_t i = 0; i < n; i++ ) free( word_array[i] );
    	free( word_array );


	


return 0;
}
