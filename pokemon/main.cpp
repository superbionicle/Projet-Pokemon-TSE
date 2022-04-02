#include <iostream>
#include "bestiaire.h"

using namespace std;

void adhoc(){
    cout<<"1. Bestiaire du jeu"<<endl;
    cout<<"2. Pokemons attrapés, nombre de stardust et mes candies"<<endl;
    cout<<"3. Attraper un pokemon : attraper un pokemon"<<endl;
    cout<<"4. Power-up et évolution"<<endl;
    cout<<"5. Combat"<<endl;
    cout<<"6. Quitter"<<endl;
}


//

int main(){
    int choix=-1;
    
    EspecePokemon bestiaire[9];
    initBestiaire(bestiaire);
    
    Pokemon blop;
    blop.pv =100;
    blop.exp=10;
    blop.cp=10;
    blop.evo=1;
    
    do{
        adhoc();
        cin>>choix;
        switch(choix){
            case 1: // Bestiaire
                //display(bestiaire);
                tri(bestiaire);
                break;
            case 2: // Pokedex
                cout<<"WIP"<<endl;
                break;
            case 3: // Attraper un pokemon
                cout<<"WIP"<<endl;
                break;
            case 4: // Consommables, evo et powerup
                cout<<"WIP"<<endl;
                //powerup(blop);
                //evolve(blop);
                break;
            case 5: // Combat
                cout<<"WIP"<<endl;
                break;
            case 6: // Quitter
                break;
            default:
                cout<<"Mauvaise entrée : recommencez"<<endl;
                break;
      }
    }while(choix!=6);
}
