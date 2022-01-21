#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Batiment_production.hh"

class Production_electricite: public Batiment_production{
    public:

        Production_electricite(int x,int y,int prix,int conso_elec,int pollution,std::string image,int ouvrier_max,int production_max){
                _ouvrier_max=ouvrier_max;
                _x=x;
                _y=y;
                _conso_elect=conso_elec;
                _pollution=pollution;
                _image=image;
                _production_max=production_max;
                _type="electricite";
                };
        //~Production_electricite();
        std::string info(){
            std::string s="";
            s=s+ "Prix :" + std::to_string(get_prix()) + "\0";
            s=s+ "Consomation électrique :" + std::to_string(get_conso_elec()) + "\0";
            s=s+ "Pollution :" + std::to_string(get_pollution()) + "\0";
            s=s+ "Production électrique max" + std::to_string(get_production_max()) + "\0";
            s=s+ "Ouvrier max :" + std::to_string(get_ouvrier_max()) + "\0";
            return s;
        }
    private:

};