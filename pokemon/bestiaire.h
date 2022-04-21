#ifndef bestiaire_h
#define bestiaire_h

#include "pokemon.h"

void initBestiaire(EspecePokemon bestiaire[]);
void display_bestiaire(EspecePokemon bestiaire[], const char* typesLabel[]);
void tri(EspecePokemon bestiaire[], const char* typesLabel[]);
void display(Pokemon p, EspecePokemon bestiaire[], const char* typesLabel[]);

#endif
