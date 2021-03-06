#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Habitation.hh"




Habitation::Habitation(){
      std::cout<<"constructeur de Habitation par defaut"<<std::endl;
}
Habitation::Habitation(int x,int y,int prix,int conso_elec,int pollution,std::string image,int nb_habitant,int dechet)
: _nb_habitant(nb_habitant),_dechet(dechet){
      _x=x;
      _y=y;

      _prix=prix;
      _conso_elect=conso_elec;
      _pollution=pollution;
      _image=image;
      _type="habitation";
}

std::string Habitation::info(){
            std::string s="";
            

            s=s+ "Prix :" + std::to_string(get_prix()) + "\0";
            s=s+ "Consomation électrique :" + std::to_string(get_conso_elec()) + "\0";
            s=s+ "Pollution :" + std::to_string(get_pollution()) + "\0";
            s=s+ "Nombre de résident :" + std::to_string(get_hab()) + "\0";
            s=s+ "Déchets produits :" + std::to_string(get_dechet()) + "\0";
            return s;
        }