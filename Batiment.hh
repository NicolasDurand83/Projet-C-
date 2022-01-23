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
        int get_prix(){return _prix;}
        int get_conso_elec(){return _conso_elect;}
        int get_pollution(){return _pollution;}
        std::string get_image(){return _image;}
        std::string get_type(){return _type;};
        virtual std::string info(){return "";};
        virtual int get_hab(){return 0;};
        virtual int get_ouvrier_max(){return 0;};

        bool operator==(Batiment b){return b.get_image()==_image;} // Voir si les deux batiments construit viennent du même objet (ex: maison (voir main.cc))

    protected:
        int _x;
        int _y;
        int _prix;
        int _conso_elect;
        int _pollution;
        std::string _image;   
        std::string _type;
};
