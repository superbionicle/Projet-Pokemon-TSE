#include <stdio.h>
#include <string.h>
#include "combat.h"

int hash(const char *str){
    unsigned long hash = 5381;
    long c;
    while(c=*str++){
        hash=((hash<<5)+hash)+c;
    }
    return(hash);
}

void insert(CombatEspece* c, CombatHash* hashtable){
    if(!contains(hashtable, c)){
        int alveole=hashf(c->nature, hashtable);
        CombatEspece* current = hashtable->table[alveole];
        if(current== nullptr){
            hashtable->table[alveole]=c;
        }
        else{
            while(current->next!=nullptr){
                current=current->next;
            }
            current->next=c;
        }
    }
}

int hashf(const char* str, CombatHash* hashtable){
    unsigned long hash = 5381;
    int c;
    while(c=*str++){
        hash=((hash<<5)+hash)+c;
    }
    return hash%hashtable->size;
}

CombatEspece* get(CombatHash* hashtable, const char* key){
    int alveole=hashf(key,hashtable);
    CombatEspece* current = hashtable->table[alveole];
    while(current!=nullptr && strcmp(current->nature,key)!=0){
        current=0;
    }
    return current;
}

bool contains(CombatHash* hashtable, CombatEspece* c){
    CombatEspece* element = get(hashtable,c->nature);
    return(element!=nullptr);
}

const char* pokemon_string_type(PokemonType t) {
    if(t==Normal){
        return("Normal");
    }
    else if(t==Fighting){
        return("Fighting");
    }
    else if(t==Poison){
        return("Poison");
    }
    else if(t==Ground){
        return("Ground");
    }
    else if(t==Rock){
        return("Rock");
    }
    else if(t==Bug){
        return("Bug");
    }
    else if(t==Ghost){
        return("Ghost");
    }
    else if(t==Steel){
        return("Steel");
    }
    else if(t==Fire){
        return("Fire");
    }
    else if(t==Grass){
        return("Grass");
    }
    else if(t==Water){
        return("Water");
    }
    else if(t==Electric){
        return("Electric");
    }
    else if(t==Ice){
        return("Ice");
    }
    else if(t==Dragon){
        return("Dragon");
    }
    else if(t==Dark){
        return("Dark");
    }
    else{
        return("Fairy");
    }
}

CombatHash* initCombatHash() {
    
    CombatHash* hashtable = new CombatHash;
    hashtable->size = 18;
    
    CombatEspece* bug = new CombatEspece;
    bug->nature = "Bug";
    bug->next = nullptr;
    bug->strongAgainst[0] = "Dark";
    bug->strongAgainst[1] = "Grass";
    bug->strongAgainst[2] = "Psychic";
    bug->weakAgainst[0] = "Fire";
    bug->weakAgainst[1] = "Flying";
    bug->weakAgainst[2] = "Rock";
    insert(bug, hashtable);
    
    CombatEspece* dark = new CombatEspece;
    dark->nature = "Dark";
    dark->next = nullptr;
    dark->strongAgainst[0] = "Ghost";
    dark->strongAgainst[1] = "Psychic";
    dark->weakAgainst[0] = "Bug";
    dark->weakAgainst[1] = "Fairy";
    dark->weakAgainst[2] = "Fight";
    insert(dark, hashtable);
    
    CombatEspece* dragon = new CombatEspece;
    dragon->nature = "Dragon";
    dragon->next = nullptr;
    dragon->strongAgainst[0] = "Dragon";
    dragon->weakAgainst[0] = "Dragon";
    dragon->weakAgainst[1] = "Fairy";
    dragon->weakAgainst[2] = "Ice";
    insert(dragon, hashtable);
    
    CombatEspece* electric = new CombatEspece;
    electric->nature = "Electric";
    electric->next = nullptr;
    electric->strongAgainst[0] = "Flying";
    electric->strongAgainst[1] = "Water";
    electric->weakAgainst[0] = "Ground";
    insert(electric, hashtable);
    
    CombatEspece* fairy = new CombatEspece;
    fairy->nature = "Fairy";
    fairy->next = nullptr;
    fairy->strongAgainst[0] = "Dark";
    fairy->strongAgainst[1] = "Dragon";
    fairy->strongAgainst[2] = "Fight";
    fairy->weakAgainst[0] = "Poison";
    fairy->weakAgainst[1] = "Steel";
    insert(fairy, hashtable);
    
    CombatEspece* fighting = new CombatEspece;
    fighting->nature = "Fighting";
    fighting->next = nullptr;
    fighting->strongAgainst[0] = "Dark";
    fighting->strongAgainst[1] = "Ice";
    fighting->strongAgainst[2] = "Normal";
    fighting->strongAgainst[3] = "Rock";
    fighting->strongAgainst[4] = "Steel";
    fighting->weakAgainst[0] = "Fairly";
    fighting->weakAgainst[1] = "Flying";
    fighting->weakAgainst[2] = "Psychic";
    insert(fighting, hashtable);
    
    CombatEspece* fire = new CombatEspece;
    fire->nature = "Fire";
    fire->next = nullptr;
    fire->strongAgainst[0] = "Bug";
    fire->strongAgainst[1] = "Grass";
    fire->strongAgainst[2] = "Ice";
    fire->strongAgainst[3] = "Steel";
    fire->weakAgainst[0] = "Ground";
    fire->weakAgainst[1] = "Rock";
    fire->weakAgainst[2] = "Water";
    insert(fire, hashtable);
    
    CombatEspece* flying = new CombatEspece;
    flying->nature = "Flying";
    flying->next = nullptr;
    flying->strongAgainst[0] = "Bug";
    flying->strongAgainst[1] = "Fight";
    flying->strongAgainst[2] = "Grass";
    flying->weakAgainst[0] = "Electric";
    flying->weakAgainst[1] = "Ice";
    flying->weakAgainst[2] = "Rock";
    insert(flying, hashtable);
    
    CombatEspece* ghost = new CombatEspece;
    ghost->nature = "Ghost";
    ghost->next = nullptr;
    ghost->strongAgainst[0] = "Ghost";
    ghost->strongAgainst[1] = "Psychic";
    ghost->weakAgainst[0] = "Dark";
    ghost->weakAgainst[1] = "Ghost";
    insert(ghost, hashtable);
    
    CombatEspece* grass = new CombatEspece;
    grass->nature = "Grass";
    grass->next = nullptr;
    grass->strongAgainst[0] = "Ground";
    grass->strongAgainst[1] = "Rock";
    grass->strongAgainst[2] = "Water";
    grass->weakAgainst[0] = "Bug";
    grass->weakAgainst[1] = "Fire";
    grass->weakAgainst[2] = "Flying";
    grass->weakAgainst[3] = "Ice";
    grass->weakAgainst[4] = "Poison";
    insert(grass, hashtable);
    
    CombatEspece* ground = new CombatEspece;
    ground->nature = "Ground";
    ground->next = nullptr;
    ground->strongAgainst[0] = "Electric";
    ground->strongAgainst[1] = "Fire";
    ground->strongAgainst[2] = "Poison";
    ground->strongAgainst[3] = "Rock";
    ground->strongAgainst[4] = "Steel";
    ground->weakAgainst[0] = "Grass";
    ground->weakAgainst[1] = "Ice";
    ground->weakAgainst[2] = "Water";
    insert(ground, hashtable);
    
    CombatEspece* ice = new CombatEspece;
    ice->nature = "Ice";
    ice->next = nullptr;
    ice->strongAgainst[0] = "Dragon";
    ice->strongAgainst[1] = "Flying";
    ice->strongAgainst[2] = "Grass";
    ice->strongAgainst[3] = "Ground";
    ice->weakAgainst[0] = "Fight";
    ice->weakAgainst[1] = "Fire";
    ice->weakAgainst[2] = "Rock";
    ice->weakAgainst[3] = "Steel";
    insert(ice, hashtable);
    
    CombatEspece* normal = new CombatEspece;
    normal->nature = "Normal";
    normal->next = nullptr;
    normal->weakAgainst[0] = "Fight";
    insert(normal, hashtable); // correction ici.
    
    CombatEspece* poison = new CombatEspece;
    poison->nature = "Poison";
    poison->next = nullptr;
    poison->strongAgainst[0] = "Fairy";
    poison->strongAgainst[1] = "Grass";
    poison->weakAgainst[0] = "Ground";
    poison->weakAgainst[1] = "Psychic";
    insert(poison, hashtable);
    
    CombatEspece* psychic = new CombatEspece;
    psychic->nature = "Psychic";
    psychic->next = nullptr;
    psychic->strongAgainst[0] = "Fight";
    psychic->strongAgainst[1] = "Poison";
    psychic->weakAgainst[0] = "Bug";
    psychic->weakAgainst[1] = "Dark";
    psychic->weakAgainst[2] = "Ghost";
    insert(psychic, hashtable);
    
    CombatEspece* rock = new CombatEspece;
    rock->nature = "Rock";
    rock->next = nullptr;
    rock->strongAgainst[0] = "Bug";
    rock->strongAgainst[1] = "Fire";
    rock->strongAgainst[2] = "Flying";
    rock->strongAgainst[3] = "Ice";
    rock->weakAgainst[0] = "Fight";
    rock->weakAgainst[1] = "Grass";
    rock->weakAgainst[2] = "Ground";
    rock->weakAgainst[3] = "Steel";
    rock->weakAgainst[3] = "Water";
    insert(rock, hashtable);
    
    CombatEspece* steel = new CombatEspece;
    steel->nature = "Steel";
    steel->next = nullptr;
    steel->strongAgainst[0] = "Fairy";
    steel->strongAgainst[1] = "Ice";
    steel->strongAgainst[2] = "Rock";
    steel->weakAgainst[0] = "Fight";
    steel->weakAgainst[1] = "Fire";
    steel->weakAgainst[2] = "Ground";
    insert(steel, hashtable);
    
    
    CombatEspece* water = new CombatEspece;
    water->nature = "Water";
    water->next = nullptr;
    water->strongAgainst[0] = "Fire";
    water->strongAgainst[1] = "Ground";
    water->strongAgainst[2] = "Rock";
    water->weakAgainst[0] = "Electric";
    water->weakAgainst[1] = "Grass";
    insert(water, hashtable);
    
    return hashtable;
    
}


























