#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Batiment.hh"

class Batiment_production: public Batiment{
    public:
        Batiment_production();
        Batiment_production(int x,int y,int longueur,int largeur,int prix,int conso_elec,int pollution,std::string image,int ouvrier_max,int nb_ouvrier,int production_max):
                _ouvrier_max(ouvrier_max),_nb_ouvrier(nb_ouvrier),_production_max(production_max)
                {_x=x;
                _y=y;
                _longueur=longueur;
                _largeur=largeur;
                _conso_elect=conso_elec;
                _pollution=pollution;
                _image=image;
                };
        ~Batiment_production();
    private:
        int _ouvrier_max;
        int _nb_ouvrier;
        int _production_max;
};