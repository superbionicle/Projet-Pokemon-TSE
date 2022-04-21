#ifndef historique_h
#define historique_h
#include "pokemon.h"

typedef struct Evolution{
	const char* avant;
	const char* apres;
	Evolution* suivant;
}Evolution;

typedef struct {
	int nombre;
	Evolution* debut;
} historique;
#endif /* historique_h */

void insert_evo(Evolution* evo, historique liste);