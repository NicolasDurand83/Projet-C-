#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Batiment.hh"



class Habitation: public Batiment{
    public:
        Habitation();
        Habitation(Habitation &B);
        Habitation(int x,int y,int longueur,int largeur,int prix,int conso_elec,int pollution,std::string image,int nb_habitant,int dechet);
        std::string info();
        int get_hab(){return _nb_habitant;};
        int get_dechet(){return _dechet;};
        int get_production_max(){return 0;}
        int get_ouvrier_max(){return 0;}
    private:
        int _nb_habitant;
        int _dechet;
};