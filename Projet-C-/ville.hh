#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include "Production_argent.hh"
#include "Production_electricite.hh"
#include "Gestion_dechet.hh"
#include "Habitation.hh"
class Ville{
    public:
        Ville(){_nom="firas";};
        Ville(std::string nom,int limite_pollution,int argent):
                _nom(nom),_limite_pollution(limite_pollution),_argent(argent)
            {
                _pollution=0;
                _solde_electricite=0;
            };
        int get_pollution(){return _pollution;}
        std::string get_name(){return _nom;};
        void set_name(std::string s){_nom=s;};
        /*std::string check_electricite(){
            int elec=0;
            std::size_t i;
            for (i=0;i<_batiments.size();i++){
                elec=elec - _batiments[i].get_conso_elec();
                if (typeid(_batiments[i])==typeid(Production_electricite)){
                    elec=elec + _batiments[i].get_production();
                }
            };
            _solde_electricite=elec;
            if (elec<0){
                //      La ville est en déficit énergétique. Cela entraine des malus.        
                return "La ville ne produit pas assez d'electricité";
            }
            else{
                return "La ville produit assez d'electricité"; 
            }
        };*/
        /*std::string check_pollution();*/
    private:
        std::vector<Batiment>  _batiments;
        std::string _nom;
        int _limite_pollution;
        int _argent;
        int _pollution;
        int _solde_electricite;
};