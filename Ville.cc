#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include "Ville.hh"
 

std::string check_pollution(){
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
std::string check_electricite(){
    int elec=0;
    int i;
    for (i=0;i<_batiments.size();i++){
        elec=elec - _batiments[i].get_conso_elec();
        if (typeof(_batiment[i])==Production_electricite){
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




