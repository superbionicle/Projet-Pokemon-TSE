#include <iostream>
#include "bestiaire.h"
#include <cstddef>
#include <string>
using namespace std;

void swap(EspecePokemon& p1, EspecePokemon& p2){
    EspecePokemon temp;
    temp.nom=p1.nom;
    temp.type=p1.type;
    temp.evolvesTo=p1.evolvesTo;
    temp.nbBonbonsPourEvoluer=p1.nbBonbonsPourEvoluer;
    
    p1.nom=p2.nom;
    p1.type=p2.type;
    p1.evolvesTo=p2.evolvesTo;
    p1.nbBonbonsPourEvoluer=p2.nbBonbonsPourEvoluer;
    
    p2.nom=temp.nom;
    p2.type=temp.type;
    p2.evolvesTo=temp.evolvesTo;
    p2.nbBonbonsPourEvoluer=temp.nbBonbonsPourEvoluer;
};

void initBestiaire(EspecePokemon bestiaire[9]){
    
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
};

void display(EspecePokemon bestiaire[]){
    /*cout<<bestiaire[0].nom<<endl;
    cout<<bestiaire[0].type<<endl;
    cout<<bestiaire[0].nbBonbonsPourEvoluer<<endl;
    cout<<bestiaire[0].evolvesTo<<endl;*/
    
    for(int i=0;i<9;i++){
        cout<<bestiaire[i].nom<<endl;
        cout<<bestiaire[i].type<<endl;
        cout<<bestiaire[i].nbBonbonsPourEvoluer<<endl;
        cout<<bestiaire[i].evolvesTo<<endl;
        cout<<endl;
    }
};

void tri(EspecePokemon bestiaire[9]){
    /*
     1. Initialise un entier i à 0
     2. Tant que i est inférieur ou égale à n − 1 :
     (a) Parcours de T[i] à T[n-1] à la recherche de la plus petite valeur,
     (b) Un fois trouvée (soit l’indice k de cette plus petite valeur), permuter T[i] et T[k],
     (c) Incrémenter i de 1.
     int strcmp(const char *str1, const char *str2)
    */
    /*int i=0;
    while(i<150){
        int j=i+1;
        int cmp=strcmp(bestiaire[i].nom,bestiaire[j].nom);
        while(j<150 && cmp<=0){
            j++;
            cmp=strcmp(bestiaire[i].nom,bestiaire[j].nom);
        }
        swap(bestiaire[i],bestiaire[j]);
        i++;
    }*/
    EspecePokemon trip[9];
    int i=0;
    while(i<150){
        int j=i+1;
        int cmp=strcmp(bestiaire[i].nom,bestiaire[j].nom);
        while(j<150 && cmp<=0){
            j++;
            cmp=strcmp(bestiaire[i].nom,bestiaire[j].nom);
        }
        trip[i]=bestiaire[j];
        i++;
    }
    int chx=-1;
    do{
        cout<<"Choix d'affichage :"<<endl;
        cout<<"1. Non trié"<<endl;
        cout<<"2. Tri alphabétique"<<endl;
        cin>>chx;
    }while(chx!=1 && chx!=2);
    if(chx==1){
        display(bestiaire);
    }
    else{
        display(trip);
    }
};



