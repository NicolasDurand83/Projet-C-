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
                _x(x), _y(y),_longueur(longueur),_largeur(largeur),
                _prix(prix),_conso_elect(conso_elec),_image(image),_id(unique_id++),_nb_habitant(nb_habitant),_dechet(dechet)
                {};
        ~Habitation();
        std::string info(){
        }


    private:
        /*int _x;
        int _y;
        int _longueur;
        int _largeur;
        int _prix;
        int _conso_elect;
        int _pollution;
        std::string _image; 
        int _id;
        static int unique_id;*/
        int _nb_habitant;
        int _dechet;
};