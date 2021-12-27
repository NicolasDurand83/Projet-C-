#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Batiment.hh"



class Habitation :public Batiment{
    public:
        Habitation();
        Habitation(int x,int y,int longueur,int largeur,int prix,int conso_elec,int pollution,std::string image,int nb_habitant,int dechet):
                _nb_habitant(nb_habitant),_dechet(dechet)
                {_x=x;
                _y=y;
                _longueur=longueur;
                _largeur=largeur;
                _conso_elect=conso_elec;
                _pollution=pollution;
                _image=image;
                _nb_habitant=nb_habitant;
                _dechet=dechet;       };
        ~Habitation();
        std::string info(){};
        int get_hab(){return _nb_habitant;};
        int get_dechet(){return _dechet};
        
    private:
        int _nb_habitant;
        int _dechet;
};