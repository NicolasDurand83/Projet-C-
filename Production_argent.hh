#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Batiment_production.hh"

class Production_argent: public Batiment_production{
    public:
        Production_argent(){_x=5;};
        Production_argent(int x,int y,int longueur,int largeur,int prix,int conso_elec,int pollution,std::string image,int ouvrier_max,int nb_ouvrier,int production_max){
                _production_max=production_max;
                _ouvrier_max=ouvrier_max;
                _nb_ouvrier=nb_ouvrier;
                _x=x;
                _y=y;
                _prix=prix;
                _longueur=longueur;
                _largeur=largeur;
                _conso_elect=conso_elec;
                _pollution=pollution;
                _image=image;
                _production=production_max*(nb_ouvrier/ouvrier_max);
               std::cout<<_ouvrier_max<<"nnnnnn\n"<<std::endl;
                };
        //~Production_argent();
        std::string info(){
            std::string s="";
            s=s+ "Longueur :" + std::to_string(get_longueur()) + "\0";
            s=s+ "Largeur :" + std::to_string(get_largeur()) + "\0";
            s=s+ "Prix :" + std::to_string(get_prix()) + "\0";
            s=s+ "Consomation électrique :" + std::to_string(get_conso_elec()) + "\0";
            s=s+ "Pollution :" + std::to_string(get_pollution()) + "\0";
            s=s+ "Argent produit:" + std::to_string(get_production()) + "\0";
            s=s+ "Argent produit max :" + std::to_string(get_production_max()) + "\0";
            s=s+ "Nombre Ouvrier :" + std::to_string(get_ouvrier()) + "\0";
            s=s+ "Ouvrier max :" + std::to_string(get_ouvrier_max()) + "\0";
            return s;
        }
    private:
        /*   int _ouvrier_max;
        int _nb_ouvrier;
        int _production_max;
        int _production;*/
};