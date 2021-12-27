#pragma once
#include <stdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Batiment.hh"
#include "Habitation.hh"

  std::string info(Habitation H){
            std::string s="";
            s=s+ "Longueur :" + std::to_string(H.get_longeur()) + "\0";
            s=s+ "Largeur :" + std::to_string(H.get_largeur()) + "\0";
            s=s+ "Prix :" + std::to_string(H.get_prix()) + "\0";
            s=s+ "Consomation électrique :" + std::to_string(H.get_conso_elec()) + "\0";
            s=s+ "Pollution :" + std::to_string(H.get_pollution()) + "\0";
            s=s+ "Nombre de résident :" + std::to_string(H.get_hab()) + "\0";
            s=s+ "Déchets produits :" + std::to_string(H.get_dechet()) + "\0";
            return s;
        }