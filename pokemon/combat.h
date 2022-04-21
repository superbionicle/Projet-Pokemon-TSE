#ifndef combat_h
#define combat_h
#include "pokemon.h"

typedef struct CombatEspece{
    const char* nature;
    const char* strongAgainst[5];
    const char* weakAgainst[5];
    CombatEspece *next;
}CombatEspece;

typedef struct CombatHash{
    CombatEspece* table[26];
    int size;
}CombatHash;

int hash(const char* str);
void insert(CombatHash* hastable, char* key);
int hashf(const char* str, CombatHash* hastable);
CombatEspece* get(CombatHash* hashtable,const char* key);
bool contains(CombatHash* hastable, CombatEspece* c);
const char* pokemon_string_type(PokemonType t);
CombatHash* initCombatHash();


#endif /* combat_h */
