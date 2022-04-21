#include "pokemon.h"
#include <iostream>
#include "pokedex.h"
using namespace std;

void evolve(Pokemon& p, ressource pochette, EspecePokemon bestiaire[]){
    int j=-1;
    for(int i=0;i<9;i++){
        if(strcmp(p.nom,bestiaire[i].nom)==0){
            j=i;
        }
    }
    if(pochette.candy>=bestiaire[j].nbBonbonsPourEvoluer and bestiaire[j].evolvesTo!=nullptr){
        pochette.candy-=bestiaire[j].nbBonbonsPourEvoluer;
        p.nom=bestiaire[j].evolvesTo;
        p.evo++;
        cout << "Evolution réussie";
    }
    else {
        cout << "Echec de l'evolution : ressources insuffisantes ou évolution max atteinte" << endl;
    }
}

void powerup(Pokemon& p, ressource pochette){
    if(pochette.candy>=10 and pochette.dust>=500){
        p.cp*=1.25;
        cout<<"Amelioration réussie"<<endl;
    }
    else{
        cout<<"Echec amelioration : ressources insuffisantes"<<endl;
    }

}

void affichage(const Pokemon p){
    cout<<"Blop affichage"<<endl;
    cout<<"PV : "<<p.pv<<endl;;
    cout<<"Exp : "<<p.exp<<endl;
    cout<<"Evo : "<<p.evo<<endl;
    cout<<"CP : "<<p.cp<<endl;
}

