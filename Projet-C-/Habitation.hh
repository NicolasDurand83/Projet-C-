#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Batiment.hh"



class Habitation: public Batiment{
    public:
        Habitation();
        Habitation(int x,int y,int longueur,int largeur,int prix,int conso_elec,int pollution,std::string image,int nb_habitant,int dechet);
        std::string info();
        int get_hab(){return _nb_habitant;};
        int get_dechet(){return _dechet;};
        
    private:
        int _nb_habitant;
        int _dechet;
};