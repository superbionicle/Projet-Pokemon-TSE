#include "historique.h"
#include "pokemon.h"

void insert_evo(Evolution* evo, historique liste) {
	evo->suivant = liste.debut;
	liste.debut = evo;
	liste.nombre++;
}