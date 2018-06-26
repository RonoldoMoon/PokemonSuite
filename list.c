#include <stdio.h>
#include "PokemonFunctions.c"

int main()  {

  int x;
    printf("Index\t---\t  Pokemon\n\n");
  for ( x = 0 ; x < 56 ; x++ )  {
    
    printf("%X %s\t\t%X %s\t\t%X %s\t\t%X %s\n", x+1, Pokemon[x], x+49, Pokemon[x+48], x+97, Pokemon[x+96], x+135, Pokemon[x+134]);
  }

  return 0;
}
