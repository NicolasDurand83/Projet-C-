#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Habitation.hh"




Habitation::Habitation(){
      std::cout<<"constructeur de Habitation par defaut"<<std::endl;
}
Habitation::Habitation(int x,int y,int longueur,int largeur,int prix,int conso_elec,int pollution,std::string image,int nb_habitant,int dechet)
: _nb_habitant(nb_habitant),_dechet(dechet){
      _x=x;
      _y=y;
      _longueur=longueur;
      _largeur=largeur;
      _prix=prix;
      _conso_elect=conso_elec;
      _pollution=pollution;
      _image=image;
      
}

Habitation::Habitation(Habitation &B){
      _x=B.get_x();
      _y=B.get_y();
      _longueur=B.get_longueur();
      _largeur=B.get_largeur();
      _prix=B.get_prix();
      _conso_elect=B.get_conso_elec();
      _pollution=B.get_pollution();
      _image=B.get_image();
      _nb_habitant=B.get_hab();
      _dechet=B.get_dechet();
};
std::string Habitation::info(){
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