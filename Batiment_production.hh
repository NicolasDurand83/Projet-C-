#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Batiment.hh"

class Batiment_production: public Batiment{
    public:
        Batiment_production(){};
       /* Batiment_production(int x,int y,int longueur,int largeur,int prix,int conso_elec,int pollution,std::string image,int ouvrier_max,int nb_ouvrier,int production_max):
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
        ~Batiment_production();*/
        Batiment_production(Batiment_production &B){
            _x=B.get_x();
            _y=B.get_y();
            _longueur=B.get_longueur();
            _largeur=B.get_largeur();
            _prix=B.get_prix();
            _conso_elect=B.get_conso_elec();
            _pollution=B.get_pollution();
            _image=B.get_image();
            _ouvrier_max=B.get_ouvrier_max();
            _production_max=B.get_production_max();
        };
        std::string info(){
            std::string s="";
            s=s+ "Longueur :" + std::to_string(get_longueur()) + "\0";
            s=s+ "Largeur :" + std::to_string(get_largeur()) + "\0";
            s=s+ "Prix :" + std::to_string(get_prix()) + "\0";
            s=s+ "Consomation électrique :" + std::to_string(get_conso_elec()) + "\0";
            s=s+ "Pollution :" + std::to_string(get_pollution()) + "\0";
            s=s+ "Prod max:" + std::to_string(get_production_max()) + "\0";
            s=s+ "Ouvrier max :" + std::to_string(get_ouvrier_max()) + "\0";
            return s;
        }
        int get_ouvrier_max(){return _ouvrier_max;};
        int get_production_max(){return _production_max;};
        int get_dechet(){return 0;}
        int get_hab(){return 0;}
    protected:
        int _ouvrier_max;
        int _production_max;
};