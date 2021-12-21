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
    
    private:
        std::vector<Batiment> _batiments;
        std::string _nom;
        int _limite_pollution;

};