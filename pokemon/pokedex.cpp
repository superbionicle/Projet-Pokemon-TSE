#include "pokedex.h"
#include "bestiaire.h"
#include "utils.h"
#include <iostream>
using namespace std;


pokedex* initPokedex(const int size) {
    pokedex* pokedex_init = new pokedex;

    pokedex_init->capacity=size;
    pokedex_init->nb_pokemon=0;
    pokedex_init->pokedex_struct=new Pokemon[size];
    return pokedex_init;
}

void insertPokemon(pokedex* pokedex_travail, Pokemon p) {

    if (pokedex_travail->capacity == pokedex_travail->nb_pokemon) { // on teste la capacité
        int n = (pokedex_travail->capacity) * 1.5; // on initialise la nouvelle capacité
        pokedex* new_pokedex = initPokedex(n); // on crée le pokedex augmenté mais temporaire
        // Pokemon* new_p = new Pokemon[n]; // methode alternative

        for (int i = 0; i < pokedex_travail->nb_pokemon; i++) {
            new_pokedex->pokedex_struct[i] = pokedex_travail->pokedex_struct[i];
            // new_p[i] = pokedex_travail->pokedex_struct[i];
        } // on transfere les pokemons dans le nouveau pointeur
        pokedex_travail->pokedex_struct = new_pokedex->pokedex_struct; // changement de pointeur
        // pokedex_travail->pokedex_struct = new_p; // méthode alternative
    } // on augmente la capacité de 50% en cas de pokedex rempli

    pokedex_travail->pokedex_struct[pokedex_travail->nb_pokemon] = p; // ajout pokemon
    pokedex_travail->nb_pokemon++; // augmentation du nb de pokemon dans la structure du pokedex

    }

void displayPokedex(pokedex* pokedex, EspecePokemon bestiaire[],const char* typesLabel[], ressource pochette){
    cout<<"Poussière dispo : "<<pochette.dust<<endl;
    cout<<"Bonbons dispo : "<<pochette.candy<<endl;
    cout<<"Contenu du pokedex "<<endl;
    cout<<"Nombre de pokemons : "<<pokedex->nb_pokemon<<endl;
    for (int i = 0; i < pokedex->nb_pokemon; i++){
        cout<<i<<". ";
        display(pokedex->pokedex_struct[i], bestiaire, typesLabel);    
        }
    
}

Pokemon generer_pokemon(EspecePokemon bestiaire[], const char* typeLabel[]) {
    // tirage aleatoire parmi les pokemons de 1ere espece
    int l[9];
    int j = 0;
    for (int i = 0; i < 9; i++) {
        if (not bestiaire[i].estEvolue) {
            l[j] = i;
            j++;
        }
    }
    long chx_pokemon = random_at_most(j);
    //initialisation pokemon
    Pokemon pokemon_choisi;
    pokemon_choisi.nom=bestiaire[chx_pokemon].nom;
    pokemon_choisi.exp=0;
    pokemon_choisi.evo=1;
    //int random=0;
    /*do {
        random_at_most(1000);
    } while (random < 200); //pc entre 200 et 1000
    cout<<random<<endl;
    pokemon_choisi.cp=random;
    do {
        random_at_most(500);
    } while (random < 30); //pv entre 30 et 500
    cout<<random<<endl;*/
    int pv=random_at_most(800)+200;
    int cp=random_at_most(470)+30;
    pokemon_choisi.pv=pv;
    pokemon_choisi.cp=cp;
    
    return(pokemon_choisi);
        
}
