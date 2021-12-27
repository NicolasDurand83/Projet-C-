#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include "Batiment.hh"
#include "Production_argent.hh"
#include "Production_electricite.hh"
#include "Gestion_dechet.hh"
class Ville{
    public:
        Ville();
        std::string get_name(){return _nom;};
        std::string check_pollution(){
            int pol=0;
            for (i=0;i<_batiments.length();i++){
                pol=pol + _batiments[i].get_pol();
            };
            if (pol>_limite_pollution){
                return "La ville a depassé le seuil de pollution authorisé";
            }
            else{
               return "La ville est en dessous du seuil de pollution"; 
            }
        }
    private:
        std::vector<Batiment> _batiments;
        std::string _nom;
        int _limite_pollution;

};