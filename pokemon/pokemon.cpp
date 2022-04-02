#include "pokemon.h"
#include <iostream>
using namespace std;

void evolve(Pokemon& p){
    cout<<"Blop évolution"<<endl;
    p.evo++;
}

void powerup(Pokemon& p){
    cout<<"Blop powerup"<<endl;
    p.cp*=1.25;
}

void affichage(const Pokemon p){
    cout<<"Blop affichage"<<endl;
    cout<<"PV : "<<p.pv<<endl;;
    cout<<"Exp : "<<p.exp<<endl;
    cout<<"Evo : "<<p.evo<<endl;
    cout<<"CP : "<<p.cp<<endl;
}


