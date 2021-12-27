#pragma once
#include <stdlib>
#include <string>
#include <iostream>
#include <vector>
#include "Production_argent.hh"
#include "Production_electricite.hh"
#include "Gestion_dechet.hh"
#include "Habitation.hh"
class Ville{
    public:
        Ville(std::string nom,int limite_pollution,int argent):
                _nom(nom),_limite_pollution(limite_pollution),_argent(argent)
            {
                _pollution=0;
                _solde_electricite=0;
            };
        int get_pollution(){return _pollution;}
        std::string get_name(){return _nom;};
        void set_name(std::string s){_nom=s;};
    private:
        std::vector<Batiment> _batiments;
        std::string _nom;
        int _limite_pollution;
        int _argent;
        int _pollution;
        int _solde_electricite;
};