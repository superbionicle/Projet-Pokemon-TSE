#include <iostream>
#include "bestiaire.h"
#include <cstddef>
#include <string>
using namespace std;

void initBestiaire(EspecePokemon bestiaire[]){
    
    bestiaire[0].nom = "Bulbasaur";
    bestiaire[0].type = Grass;
    bestiaire[0].nbBonbonsPourEvoluer = 25;
    bestiaire[0].evolvesTo = "Ivysaur";
    
    bestiaire[1].nom = "Ivysaur";
    bestiaire[1].type = Grass;
    bestiaire[1].nbBonbonsPourEvoluer = 100;
    bestiaire[1].evolvesTo = "Venusaur";
    
    bestiaire[2].nom = "Venusaur";
    bestiaire[2].type = Grass;
    bestiaire[2].nbBonbonsPourEvoluer = 0;
    bestiaire[2].evolvesTo = nullptr;
    
    bestiaire[3].nom = "Charmander";
    bestiaire[3].type = Fire;
    bestiaire[3].nbBonbonsPourEvoluer = 25;
    bestiaire[3].evolvesTo = "Charmeleon";
    
    bestiaire[4].nom = "Charmeleon";
    bestiaire[4].type = Fire;
    bestiaire[4].nbBonbonsPourEvoluer = 100;
    bestiaire[4].evolvesTo = "Charizard";
    
    bestiaire[5].nom = "Charizard";
    bestiaire[5].type = Fire;
    bestiaire[5].nbBonbonsPourEvoluer = 0;
    bestiaire[5].evolvesTo = nullptr;
    
    bestiaire[6].nom = "Squirtle";
    bestiaire[6].type = Water;
    bestiaire[6].nbBonbonsPourEvoluer = 25;
    bestiaire[6].evolvesTo = "Wartortle";
    
    bestiaire[7].nom = "Wartortle";
    bestiaire[7].type = Water;
    bestiaire[7].nbBonbonsPourEvoluer = 100;
    bestiaire[7].evolvesTo = "Blastoise";
    
    bestiaire[8].nom = "Blastoise";
    bestiaire[8].type = Water;
    bestiaire[8].nbBonbonsPourEvoluer = 0;
    bestiaire[8].evolvesTo = nullptr;

    for (int i = 0; i < 9; i++) {
        bestiaire[i].estEvolue = false;
    }
    bestiaire[0].estEvolue = true;
    bestiaire[3].estEvolue = true;
    bestiaire[6].estEvolue = true;
    bestiaire[9].estEvolue = true;
};

void display_bestiaire(EspecePokemon bestiaire[],const char* typesLabel[]){
    
    for(int i=0;i<9;i++){
        cout<<"Nom : "<<bestiaire[i].nom<<endl;
        cout << "Carac :" << "      " << "Type : " << typesLabel[bestiaire[i].type]<<"      ";
        if (bestiaire[i].evolvesTo == nullptr) {
            cout << "Evolution : aucune" << endl;
        }
        else {
            cout << "Evolution : " << bestiaire[i].evolvesTo << "     " << "Nombre de bonbons pour évoluer : " << bestiaire[i].nbBonbonsPourEvoluer << endl;
        }
    }
    cout << endl;
};

void display(Pokemon p, EspecePokemon bestiaire[], const char* typesLabel[]) {

    cout << endl;
    cout << p.nom;
    cout << "  | ";
    cout << " | ";

    cout << "  (Evolution : " << p.evo << ")" << endl;
    cout << "PV : " << p.pv << "   |   XP : " << p.exp << "   |   CP " << p.cp << endl;
}
void tri(EspecePokemon bestiaire[], const char* typesLabel[]){

    int k;
    EspecePokemon temp;
    for (int i = 0; i < 9; i++) {
        k = i;
        for (int j = i + 1; j < 9; j++) {
            if (strcmp(bestiaire[k].nom, bestiaire[j].nom) > 0) {
                temp = bestiaire[j];
                bestiaire[j] = bestiaire[k];
                bestiaire[k] = temp;
            }
        }
    }

    int chx=-1; // on va demander à l'utilisateur quel affichage il souhaite avoir : avec ou sans tri
    do{
        cout<<"Choix d'affichage :"<<endl;
        cout<<"1. Non trié"<<endl;
        cout<<"2. Tri alphabétique"<<endl;
        cin>>chx;
    }while(chx!=1 && chx!=2); // on boucle tant qu'il n'a pas choix une des deux bonnes reponses
    if(chx==1){
        initBestiaire(bestiaire);
        display_bestiaire(bestiaire, typesLabel); // 1er cas : on affiche le bestiaire normal
    }
    else{
        display_bestiaire(bestiaire,typesLabel); // 2e cas : on affiche le bestiaire trié
    }
};



