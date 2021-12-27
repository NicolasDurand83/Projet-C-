#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>


class Batiment{
    public:
        Batiment();
        Batiment(int x,int y,int longueur,int largeur,int prix,int conso_elec,int pollution,std::string image):_x(x), _y(y),_longueur(longueur),_largeur(largeur),
                _prix(prix),_conso_elect(conso_elec),_image(image),_id(unique_id++)
                {};

        int get_x(){return _x;}
        int get_y(){return _y;}

        int get_longeur(){return _longueur;}
        int get_largeur(){return _largeur;}
        int get_prix(){return _prix;}
        int get_conso_elec(){return _conso_elect;}
        int get_pollution(){return _pollution;}
        std::string get_image(){return _image;}
        virtual std::string info()=0;
        
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