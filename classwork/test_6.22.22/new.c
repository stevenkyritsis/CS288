#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] ) // ignore envp
{
    printf( "%d command line args passed.\n", argc );
    while( --argc > 0 ) { // pre-decrement skips a.out
      printf( "arg %d = \"%s\"\n", argc, argv[ argc ] );
    } 
}
