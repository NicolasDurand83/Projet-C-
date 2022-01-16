#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include "Ville.hh"
 

std::string Ville::check_pollution(){
    int pol=0;
    int i;
    for (i=0;i<_batiments.size();i++){
        pol=pol + _batiments[i].get_pollution();
    };
    _pollution=pol;
    if (pol>_limite_pollution){
        // Il faut arrêter la partie
        return "La ville a depassé le seuil de pollution authorisé";
    }
    else{
        return "La ville est en dessous du seuil de pollution"; 
    }
}
std::string Ville::check_electricite(){
    int elec=0;
    int i;
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
}

std::string Ville::check_electricite(){
    int solde_dechet=0;
    int i;
    for (i=0;i<_batiments.size();i++){
        if (typeid(_batiments[i])==typeid(Gestion_dechet)){
            solde_dechet=solde_dechet + _batiments[i].get_production();
        }
        if (typeid(_batiments[i])==typeid(Habitation)){
            solde_dechet=solde_dechet - _batiments[i].get_dechet();
        }
    };
    if (solde_dechet<0){
//      La ville est en déficit énergétique. Cela entraine des malus.        
        return "La ville ne traite pas tous les déchets qu'elle produit";
    }
    else{
        return "Tous les déchets peuvent être traités"; 
    }
}


int Ville::get_revenue(){
    int cash=0;
    int i;
    for (i=0;i<_batiments.size();i++){
        if (typeid(_batiments[i])==typeid(Production_argent)){
            cash=cash + _batiments[i].get_production();
        }
    };
    return cash;
}
template<typename T>
std::string Ville::create_batiment(T& B, int x, int y){
    int i;
    B.set_x(x);B.set_y(y);
    if (B.get_prix()>this._argent){
        return "Vous n'avez pas assez d'argent pour construire ce batiment";
    }
    for (i=0;i<_batiments.size();i++){
        if ((B.get_x() < _batiments[i].get_x() +_batiments[i].get_largeur()) && ( B.get_x()+B.get_largeur()>_batiments[i].get_x()) && (B.get_y() > _batiments[i].get_y() +_batiments[i].get_longueur()) && (B.get_y() + B.get_longueur()< _batiments[i].get_y() ))
        {
            return "Impossible de construire ce bâtiment sur un autre bâtiment existant";
        }
    };
    (this->_batiments).push_back(B);
    return "Le batiment a été construit";
    
}


std::string Ville::delete_batiment(int x, int y){
    int i;
    int tempx,tempy,templong,templarg;
    for (i=0;(this->_batiments).size();i++){
        tempx=(this->_batiments[i]).get_x();
        tempy=(this->_batiments[i]).get_y();
        templong=(this->_batiments[i]).get_longueur();
        templarg=(this->_batiments[i]).get_largeur();
        if (tempx>=x && tempy>=y && x<=tempx+templong && y<=tempy +templarg){
            (this->_batiments).erase(i);
            return "Batiment supprimé";
        }
    }
    return "Il n'y a pas de batiment ici";
}

void Ville::update(){
    this->check_pollution();
    this->check_electricite();
    this->check_dechet();
    this->_argent+=this->get_revenue();
}
