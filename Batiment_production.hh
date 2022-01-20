#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Batiment.hh"

class Batiment_production: public Batiment{
    public:
        Batiment_production(){};
    /*  virtual std::string info(){
            std::string s="";
            s=s+ "Longueur :" + std::to_string(get_longueur()) + "\0";
            s=s+ "Largeur :" + std::to_string(get_largeur()) + "\0";
            s=s+ "Prix :" + std::to_string(get_prix()) + "\0";
            s=s+ "Consomation électrique :" + std::to_string(get_conso_elec()) + "\0";
            s=s+ "Pollution :" + std::to_string(get_pollution()) + "\0";
            s=s+ "Prod max:" + std::to_string(get_production_max()) + "\0";
            s=s+ "Ouvrier max :" + std::to_string(get_ouvrier_max()) + "\0";
            return s;
        } */
        int get_ouvrier_max(){return _ouvrier_max;};
        int get_production_max(){return _production_max;};
        int get_dechet(){return 0;}
        int get_hab(){return 0;}
    protected:
        int _ouvrier_max;
        int _production_max;
};