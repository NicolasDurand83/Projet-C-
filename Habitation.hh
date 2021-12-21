#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Batiment.hh"
#include <string.h>


class Habitation :public Batiment{
    public:
        Habitation();
        Habitation(int nb_habitant,int dechet):Batiment(){}
        
        ~Habitation();
        std::string info(){
            std::string s="";
            s=s+ "Longueur :" + to_string()
            
        }


    private:
        int _nb_habitant;
        int _dechet;
};