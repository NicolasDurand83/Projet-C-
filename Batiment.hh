#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>


class Batiment{
    public:
        Batiment();
        int get_x(){return _x;}
        int get_y(){return _y;}
        void set_x(int x){_x=x;}
        void set_y(int y){_y=y;}
        int get_longueur(){return _longueur;}
        int get_largeur(){return _largeur;}
        int get_prix(){return _prix;}
        int get_conso_elec(){return _conso_elect;}
        int get_pollution(){return _pollution;}
        std::string get_image(){return _image;}
        virtual std::string info()=0;
        virtual int get_production()=0;
        virtual int get_dechet()=0;
    protected:
        int _x;
        int _y;
        int _longueur;
        int _largeur;
        int _prix;
        int _conso_elect;
        int _pollution;
        std::string _image; 
        int _id;
        static int unique_id;     
};
