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
        Ville(std::string nom,int limite_pollution,float argent):
                _nom(nom),_limite_pollution(limite_pollution),_argent(argent)
            {
                _pollution=0;
                _solde_electricite=0;
                _population=0;
                _taux_d_emploi=0;
            };
        float get_pollution(){return _pollution;}
        std::string get_name(){return _nom;};
        void set_name(std::string s){_nom=s;};
        float get_argent(){return _argent;};
        int get_pop(){return _population;};
        void update_pop();
        std::string check_pollution();
        std::string check_electricite();
        std::string check_dechet();
        int get_revenue();
       
        std::string delete_batiment(int x, int y);
        void erase(int i);
        void update();
    
        std::string create_habitation(Habitation B, int x, int y);
        std::string create_production_argent(Production_argent B, int x, int y);
        std::string create_production_elec(Production_electricite B, int x, int y);
        std::string create_dechet(Gestion_dechet B, int x, int y);
        friend std::ostream& operator<<(std::ostream& os,const Ville &V);
        
    private:
        std::vector<Batiment>  _batiments;
        std::vector<Habitation> _habitation;
        std::vector<Gestion_dechet> _Gestion_dechet;
        std::vector<Production_electricite> _production_electricite;
        
        std::vector<Production_argent> _production_argent;
        std::string _nom;
        float _limite_pollution;
        float _argent;
        float _taux_d_emploi;
        float _nb_emploi;
        float _pollution;
        float _solde_electricite;
        int _population;

};