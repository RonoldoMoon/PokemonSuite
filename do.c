//do.c
#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

int main()  {

  char pop[128];

  printf("%s%s%s%s%s%s%s%s",
  
    "\n\tWelcome to the \e[96mPokemonCompiler \e[0mpc-V0.1\n",
    "\tChanges will remain in memory only, until you decide to write them.\n\n",
    "File pokemon.bin: 44 bytes\n",
    "Disklabel type: Twat\n",
    "Trainer identifier: 5000\n\n",
    "\e[92mSpecies          Experience   Level   Size Id Type\e[0m\n",
    "Pikachu               10000   999     -     - Grass\n\n\n",
    "Command (m for help):" // no new line
    );
    
  gets(pop);

return 0;
}
