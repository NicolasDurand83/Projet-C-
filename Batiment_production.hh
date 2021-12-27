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
                _production=production_max*(nb_ouvrier/ouvrier_max);
                };
        ~Batiment_production();
        int get_ouvrier_max(){return _ouvrier_max;};
        int get_ouvrier(){return _nb_ouvrier;};
        int get_production(){return _production;};
        int get_production_max(){return _production_max;};
    protected:
        int _ouvrier_max;
        int _nb_ouvrier;
        int _production_max;
        int _production;
};