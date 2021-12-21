#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Batiment.hh"

Batiment::~Batiment(){
    //definir si on a besoin
}

Batiment::Batiment(){
    //definir si on  a besoin
}

Batiment::Batiment(int x,int y,int grandeur,int prix,int conso_elec,int pollution,std::string image){
    _x=x;
    _y=y;
    _grandeur=grandeur;
    _prix=prix;
    _conso_elect=conso_elec;
    _grandeur=grandeur;
    _image=image;
}