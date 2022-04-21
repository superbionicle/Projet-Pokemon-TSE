#include <iostream>
#include "bestiaire.h"
#include "pokedex.h"
#include "utils.h"
#include "historique.h"
#import "combat.h"

using namespace std;

void adhoc(){
    cout << "1. Bestiaire du jeu" << endl;
    cout << "2. Pokemons attrapés, nombre de stardust et mes candies" << endl;
    cout << "3. Attraper un pokemon : attraper un pokemon" << endl;
    cout << "4. Power-up et évolution" << endl;
    //cout << "5. Combat" << endl;
    
    //cout << "7. Zone test" << endl;
    cout << "6. Historique des evolutions" << endl;
    cout << "0. Quitter" << endl;
}

int main(){
    int choix_menu=-1;
    const char* typesLabel[18] = {"Normal","Fighting","Flying","Poison","Ground","Rock","Bug","Ghost","Steel","Fire","Grass","Water","Electric","Psychic","Ice","Dragon","Dark","Fairy"};

    EspecePokemon bestiaire[150];
    initBestiaire(bestiaire);
    
    pokedex* pokedex_test = initPokedex(3);
    ressource pochette;
    pochette.candy=1000;
    pochette.dust=1000;

    historique liste;
    liste.debut = nullptr;
    liste.nombre = 0;
    Evolution evo_temp;
    evo_temp.suivant = nullptr;
  
    
    do{
        adhoc();
        cin>>choix_menu;
        switch(choix_menu){
            case 1: // Bestiaire
                tri(bestiaire,typesLabel);
                break;
            case 2: // Pokedex
                displayPokedex(pokedex_test, bestiaire, typesLabel, pochette);
                break;
            case 3:{// Attraper un pokemon
                int choix_gen=-1;
                do{
                    Pokemon pokemon_choisi = generer_pokemon(bestiaire, typesLabel);
                    display(pokemon_choisi, bestiaire, typesLabel);
                    do {
                        cout << "Quel choix à faire ?" << endl;
                        cout << "1. Capture (40% de chance de réussite)" << endl;
                        cout << "2. Rencontrer nouveau pokemon sauvage (regeneration)" << endl;
                        cout << "0. Fuite" << endl;
                        cout << "Choix : ";
                        cin >> choix_gen;
                    } while (choix_gen < 0 and choix_gen>2);
                    switch (choix_gen) {
                        case 1:{
                            long chance = random_at_most(100);
                            if (chance >= 60) {
                                cout << "Capture réussie" << endl;
                                insertPokemon(pokedex_test, pokemon_choisi);
                                pochette.candy+=3;
                                pochette.dust+=100;
                            }
                            else {
                                cout << "Echec de la capture" << endl;
                            }
                            break;
                            
                        }
                        case 2:
                            cout << "Nouveau pokemon sauvage en vue" << endl;
                            choix_gen=-1;
                            break;
                        case 0:
                            cout << "Fuite" << endl;
                            break;
                    }
                }while(choix_gen!=0);
            }
                
                break;
            case 4:{// Consommables, evo et powerup
                int nb=-1;
                if(pokedex_test->nb_pokemon==0){
                    cout<<"Aucun pokemon à faire évoluer"<<endl;
                    break;
                }
                do{
                    displayPokedex(pokedex_test, bestiaire, typesLabel, pochette);
                    cout<<"Quel numero dans le pokedex à faire évoluer ?"<<endl;
                    cin>>nb;
                }while(nb<0 and nb>pokedex_test->nb_pokemon);
                int choix_pwr_evo=-1;
                do{
                    cout<<"Que faire ?"<<endl;
                    cout<<"1. Amelioration"<<endl;
                    cout<<"2. Evolution"<<endl;
                    cin >> choix_pwr_evo;
                }while(choix_pwr_evo<1 and choix_pwr_evo>2);
                switch(choix_pwr_evo){
                    case 1: // Amelioration
                        powerup(pokedex_test->pokedex_struct[nb], pochette);
                        displayPokedex(pokedex_test, bestiaire, typesLabel, pochette);
                        break;
                    case 2: // Evolution
                        evo_temp.avant = pokedex_test->pokedex_struct[nb].nom;
                        evolve(pokedex_test->pokedex_struct[nb], pochette, bestiaire);
                        evo_temp.avant = pokedex_test->pokedex_struct[nb].nom;
                        insert_evo(&evo_temp, liste);
                        displayPokedex(pokedex_test, bestiaire, typesLabel, pochette);
                        break;
                }
            }
                break;
            case 5:{ // Combat
                int num;
                cout<<"Selectionnez un pokemon de votre équipe"<<endl;
                displayPokedex(pokedex_test, bestiaire, typesLabel, pochette);
                cout<<"Numéro du pokemon : ";
                cin>>num;
                int choix_combat=-1;
                do{
                    cout<<"1. Combat contre pokemon sauvage"<<endl;
                    cout<<""<<endl;
                }while(choix_combat!=1 && choix_combat!=2);
                cout<<"WIP"<<endl;
                break;
                
            }
            case 6: { // historique des évolutions
                if (liste.nombre == 0) {
                    cout << "Aucune evolution n'a eu lieu" << endl;
                }
                else {
                    cout << "Historique des evolutions par ordre antechronologique" << endl;
                    Evolution* parcours;
                    do {
                        parcours = liste.debut;
                        cout << parcours->avant << " a evolue en " << parcours->apres << endl;
                    } while (parcours->suivant != nullptr);
                }
            }
                break;
            case 0: // Quitter
                break;
            default:
                cout<<"Mauvaise entrée : recommencez"<<endl;
                break;
      }
    }while(choix_menu!=6);
}
