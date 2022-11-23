#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pokemon.h"

struct pokemon pokedex[POKEMONS];

void show_pokemon(int position){
    struct pokemon pokemon = pokedex[position];
    printf("\n============================= \n");
    printf("==  id: %d \n",  pokemon.id);
    printf("==  name: %s \n",  pokemon.name);
    printf("==  attack: %d \n",  pokemon.attack);
    printf("==  defense: %d \n",  pokemon.defense);
    printf("============================= \n");
}

void init_pokedex(void){

  FILE* f = fopen("./pokedex.csv", "r");
  char * buffer = malloc(151);
  char * info;
  if(!f) {
    perror("fopen");
    exit(1);
  }
  //@TODO
  while(fgets(buffer, POKEMONS, f) != NULL){

    struct pokemon p;

    info = strtok(buffer, ",");
    int id = atoi(info);
    p.id = id;

    info = strtok(NULL, ",");
    strcpy(p.name, info);

    info = strtok(NULL, ",");
    strcpy(p.type[0], info);

    

  }
}
