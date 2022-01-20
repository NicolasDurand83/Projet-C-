#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include "Ville.hh"
 

std::string Ville::check_pollution(){
    int pol=0;
    int i;
    for (i=0;i<(int)_batiments.size();i++){
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
    for (i=0;i<(int)_batiments.size();i++){
        elec=elec - _batiments[i].get_conso_elec();
        if (typeid(_batiments[i])==typeid(Production_electricite)){
            elec=elec + _batiments[i].get_production_max()*_taux_d_emploi;
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

std::string Ville::check_dechet(){
    int solde_dechet=0;
    int i;
    for (i=0;i<(int)_batiments.size();i++){
        if (typeid(_batiments[i])==typeid(Gestion_dechet)){
            solde_dechet=solde_dechet + _batiments[i].get_production_max()*_taux_d_emploi;
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
    for (i=0;i<(int)_batiments.size();i++){
        if (typeid(_batiments[i])==typeid(Production_argent)){
            cash=cash + _batiments[i].get_production_max()*_taux_d_emploi;
        }
    };
    return cash;
}



void Ville::erase(int i){
    int j;
    for (j=i;j<(int)_batiments.size()-1;j++){
        _batiments[j]=_batiments[i+1];
    }
    _batiments.pop_back();
}

void Ville::update_pop(){
    int hab=0,i;
    for (i=0;i<(int)_batiments.size()-1;i++){
        if (typeid(_batiments[i])==typeid(Habitation)){
            hab=hab + _batiments[i].get_hab();
        }
    } 
    _population=hab;

}

void Ville::efficacite(){
    int ouvrier=0,i;
    for (i=0;i<(int)_batiments.size()-1;i++){
        if (typeid(_batiments[i])==typeid(Batiment_production)){
            ouvrier=ouvrier + _batiments[i].get_ouvrier_max();
        }
    } 
    _taux_d_emploi=(_population*1.0)/ouvrier;
}

std::string Ville::delete_batiment(int x, int y){
    int i;
    int tempx,tempy,templong,templarg;
    for (i=0;(int)_batiments.size();i++){
        tempx=_batiments[i].get_x();
        tempy=_batiments[i].get_y();
        templong=_batiments[i].get_longueur();
        templarg=_batiments[i].get_largeur();
        if (tempx>=x && tempy>=y && x<=tempx+templong && y<=tempy +templarg){
            erase(i);
            return "Batiment supprimé";
        }
    }
    return "Il n'y a pas de batiment ici";
}


void Ville::update(){
    this->update_pop();
    this->efficacite();
    this->_argent+=this->get_revenue();
    std::cout<<this->check_pollution()<<'\n'<<this->check_electricite()<<'\n'<<this->check_dechet()<<'\n';

}



std::string Ville::create_habitation(Habitation B, int x, int y){
    int i;
    Habitation B_copy(B.get_x(),B.get_y(),B.get_longueur(),B.get_largeur(),B.get_prix(),B.get_conso_elec(),B.get_pollution(),B.get_image(),B.get_hab(),B.get_dechet());
    if (B_copy.get_prix()>_argent){
        return "Vous n'avez pas assez d'argent pour construire ce batiment";
    }
    B_copy.set_x(x);B_copy.set_y(y);
    for (i=0;i<(int)_batiments.size();i++){
        if ((B_copy.get_x() <= _batiments[i].get_x() +_batiments[i].get_largeur()) && ( B_copy.get_x()+B_copy.get_largeur()>=_batiments[i].get_x()) && (B_copy.get_y() >= _batiments[i].get_y() +_batiments[i].get_longueur()) && (B_copy.get_y() + B_copy.get_longueur()<= _batiments[i].get_y() ))
        {
            return "Impossible de construire ce bâtiment sur un autre bâtiment existant";
        }
    };
    _argent=_argent-B.get_prix();
    (this->_batiments).push_back(B_copy);
    this->update();
    return "Le batiment a été construit";
}
std::string Ville::create_production_argent(Production_argent B, int x, int y){
    int i;
    Production_argent B_copy(B.get_x(),B.get_y(),B.get_longueur(),B.get_largeur(),B.get_prix(),B.get_conso_elec(),B.get_pollution(),B.get_image(),B.get_ouvrier_max(),B.get_production_max());
    if (B_copy.get_prix()>_argent){
        return "Vous n'avez pas assez d'argent pour construire ce batiment";
    }
    B_copy.set_x(x);B_copy.set_y(y);
    for (i=0;i<(int)_batiments.size();i++){
        if ((B_copy.get_x() < _batiments[i].get_x() +_batiments[i].get_largeur()) && ( B_copy.get_x()+B_copy.get_largeur()>_batiments[i].get_x()) && (B_copy.get_y() > _batiments[i].get_y() +_batiments[i].get_longueur()) && (B_copy.get_y() + B_copy.get_longueur()< _batiments[i].get_y() ))
        {
            return "Impossible de construire ce bâtiment sur un autre bâtiment existant";
        }
    };
    _argent=_argent-B.get_prix();
    (this->_batiments).push_back(B_copy);
    this->update();
    return "Le batiment a été construit";
}
std::string Ville::create_production_elec(Production_electricite B, int x, int y){
    int i;
    Production_electricite B_copy(B.get_x(),B.get_y(),B.get_longueur(),B.get_largeur(),B.get_prix(),B.get_conso_elec(),B.get_pollution(),B.get_image(),B.get_ouvrier_max(),B.get_production_max());
    if (B_copy.get_prix()>_argent){
        return "Vous n'avez pas assez d'argent pour construire ce batiment";
    }
    B_copy.set_x(x);B_copy.set_y(y);
    for (i=0;i<(int)_batiments.size();i++){
        if ((B_copy.get_x() < _batiments[i].get_x() +_batiments[i].get_largeur()) && ( B_copy.get_x()+B_copy.get_largeur()>_batiments[i].get_x()) && (B_copy.get_y() > _batiments[i].get_y() +_batiments[i].get_longueur()) && (B_copy.get_y() + B_copy.get_longueur()< _batiments[i].get_y() ))
        {
            return "Impossible de construire ce bâtiment sur un autre bâtiment existant";
        }
    };
    _argent=_argent-B.get_prix();
    (this->_batiments).push_back(B_copy);
    this->update();
    return "Le batiment a été construit";
}
std::string Ville::create_dechet(Gestion_dechet B, int x, int y){
    int i;
    Gestion_dechet B_copy(B.get_x(),B.get_y(),B.get_longueur(),B.get_largeur(),B.get_prix(),B.get_conso_elec(),B.get_pollution(),B.get_image(),B.get_ouvrier_max(),B.get_production_max());
    if (B_copy.get_prix()>_argent){
        return "Vous n'avez pas assez d'argent pour construire ce batiment";
    }
    B_copy.set_x(x);B_copy.set_y(y);
    for (i=0;i<(int)_batiments.size();i++){
        if ((B_copy.get_x() < _batiments[i].get_x() +_batiments[i].get_largeur()) && ( B_copy.get_x()+B_copy.get_largeur()>_batiments[i].get_x()) && (B_copy.get_y() > _batiments[i].get_y() +_batiments[i].get_longueur()) && (B_copy.get_y() + B_copy.get_longueur()< _batiments[i].get_y() ))
        {
            return "Impossible de construire ce bâtiment sur un autre bâtiment existant";
        }
    };
    _argent=_argent-B.get_prix();
    (this->_batiments).push_back(B_copy);
    this->update();
    return "Le batiment a été construit";
}