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
  char *buffer = malloc(151);
  char *info;
  if(!f) {
    perror("fopen");
    exit(1);
  }
  while(fgets(buffer, POKEMONS,f)!=NULL){
    struct pokemon p;
    info = strtok(NULL, ",");
    int c = 0; //Index de la columna.
    while(info){
      if(c==0) p.id = atoi(info);
      if(c == 1) strcpy(p.name, info);
      if(c==2) strcpy(p.type[0], info);
      if(c==3) strcpy(p.type[1], info);
      if(c==4) p.total = atoi(info);
      if(c==5) p.hp = atoi(info);
      if(c==6) p.attack = atoi(info);
      if(c==7) p.defense = atoi(info);
      if(c==8) p.spAttack = atoi(info);
      if(c==9) p.spDefense = atoi(info);
      if(c==10) p.speed = atoi(info);
      if(c==11) p.generation = atoi(info);
      if(c==12) p.legendary = atoi(info);
      c++;
      info = strtok(NULL, ",");
  }
  pokedex[p.id-1] = p;
}
  free(buffer);
  fclose(f);
}
