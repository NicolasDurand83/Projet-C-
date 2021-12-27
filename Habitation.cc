#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Batiment.hh"
#include "Habitation.hh"

  std::string info(){
            std::string s="";
            s=s+ "Longueur :" + std::to_string(get_longeur()) + "\0";
            s=s+ "Largeur :" + std::to_string(get_largeur()) + "\0";
            s=s+ "Prix :" + std::to_string(get_prix()) + "\0";
            s=s+ "Consomation électrique :" + std::to_string(get_conso_elec()) + "\0";
            s=s+ "Pollution :" + std::to_string(get_pollution()) + "\0";
            s=s+ "Nombre de résident :" + std::to_string(get_hab()) + "\0";
            s=s+ "Déchets produits :" + std::to_string(get_dechet()) + "\0";
            return s;
        }