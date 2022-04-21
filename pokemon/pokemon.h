#ifndef pokemon_h
#define pokemon_h

typedef struct {
    int dust;
    int candy;
}ressource;

typedef enum{
    Normal, Fighting, Flying, Poison, Ground, Rock, Bug,Ghost, Steel, Fire, Grass, Water, Electric, Psychic,Ice, Dragon, Dark, Fairy
}PokemonType;

typedef struct{
    const char* nom;
    PokemonType type;
    int nbBonbonsPourEvoluer;
    const char* evolvesTo;
    bool estEvolue;
}EspecePokemon;

typedef struct {
    const char* nom;
    int exp;
    int evo;
    int pv;
    int cp;
}Pokemon;


void evolve(Pokemon& p, ressource pochette,EspecePokemon bestiaire[]);
void powerup(Pokemon& p, ressource pochette);
void affichage(const Pokemon p);


#endif
