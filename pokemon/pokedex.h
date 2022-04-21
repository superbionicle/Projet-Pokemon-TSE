#ifndef pokedex_h
#define pokedex_h

#include "pokemon.h"


typedef struct{
    Pokemon *pokedex_struct;
    int capacity;
    int nb_pokemon;
}pokedex;

pokedex* initPokedex(const int size);
void insertPokemon(pokedex* monPokedex, Pokemon p);
void displayPokedex(pokedex* pokedex, EspecePokemon bestiaire[],const char* typesLabel[], ressource pochette);
Pokemon generer_pokemon(EspecePokemon bestiaire[150], const char* typeLabel[18]);

#endif
