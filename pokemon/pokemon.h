
typedef enum{
    Normal, Fighting, Flying, Poison, Ground, Rock, Bug,Ghost, Steel, Fire, Grass, Water, Electric, Psychic,Ice, Dragon, Dark, Fairy
}PokemonType;

typedef struct{
    char* nom;
    PokemonType type;
    int nbBonbonsPourEvoluer;
    char* evolvesTo;
}EspecePokemon;

typedef struct {
    const char* nom;
    int exp;
    int evo;
    int pv;
    int cp;
}Pokemon;


void evolve(Pokemon& p);
void powerup(Pokemon& p);
void affichage(const Pokemon p);
