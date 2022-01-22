#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
#include "Ville.hh"
 


std::string Ville::check_pollution(){
    int pol=0;
    int i;
    /*for (i=0;i<(int)_batiments.size();i++){
        pol=pol + _batiments[i].get_pollution();
    };*/
    for (i=0;i<(int)_habitation.size();i++){
        pol=pol + _habitation[i].get_pollution();
    };
    for (i=0;i<(int)_Gestion_dechet.size();i++){
        pol=pol + _Gestion_dechet[i].get_pollution();
    };
    for (i=0;i<(int)_production_electricite.size();i++){
        pol=pol + _production_electricite[i].get_pollution();
    };
    for (i=0;i<(int)_production_argent.size();i++){
        pol=pol + _production_argent[i].get_pollution();
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
int elec=0;
std::string Ville::check_electricite(){
    _solde_electricite=0;
    int i;
    /*for (i=0;i<(int)_batiments.size();i++){
        _solde_electricite=_solde_electricite - _batiments[i].get_conso_elec();
        if ((_batiments[i].get_type()).compare("electricite")==0){
            _solde_electricite=_solde_electricite + _batiments[i].get_production_max()*_taux_d_emploi;
        };
    };*/
    for (i=0;i<(int)_habitation.size();i++){
        _solde_electricite=_solde_electricite - _habitation[i].get_conso_elec();
    };
    for (i=0;i<(int)_Gestion_dechet.size();i++){
        _solde_electricite=_solde_electricite - _Gestion_dechet[i].get_conso_elec();
    };
    for (i=0;i<(int)_production_argent.size();i++){
        _solde_electricite=_solde_electricite - _production_argent[i].get_conso_elec();
    };
    for (i=0;i<(int)_production_electricite.size();i++){
        _solde_electricite=_solde_electricite + _production_electricite[i].get_production_max()*_taux_d_emploi;   
    };

    if (_solde_electricite<0){
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
    /*for (i=0;i<(int)_batiments.size();i++){
        if ((_batiments[i].get_type()).compare("dechet")==0){
            solde_dechet=solde_dechet + _batiments[i].get_production_max()*_taux_d_emploi;
        }
        if ((_batiments[i].get_type()).compare("habitation")==0){
            solde_dechet=solde_dechet - _batiments[i].get_dechet();
        }
    };*/
    for (i=0;i<(int)_habitation.size();i++){
        solde_dechet=solde_dechet - _habitation[i].get_dechet();    
    };
    for (i=0;i<(int)_Gestion_dechet.size();i++){
        solde_dechet=solde_dechet + _Gestion_dechet[i].get_dechet();
    };

    if (solde_dechet<0){
    //La ville est en déficit dechet. Cela entraine des malus.        
        return "La ville ne traite pas tous les déchets qu'elle produit";
    }
    else{
        return "Tous les déchets peuvent être traités"; 
    }
}


int Ville::get_revenue(){
    int cash=0;
    int i;
   /* for (i=0;i<(int)_batiments.size();i++){
        if ((_batiments[i].get_type()).compare("argent")==0){
            cash=cash + _batiments[i].get_production_max()*_taux_d_emploi;
        }
    };*/
    for (i=0;i<(int)_production_argent.size();i++){
        cash=cash + _production_argent[i].get_production_max()*_taux_d_emploi;
    }
    return cash;
}
int effacer=0;//si effacer =1 donc on a effacer le batiment
std::string Ville::delete_batiment(int x, int y){  
    int effacer=0;//si effacer =1 donc on a effacer le batiment    
    for (int i=0;(int)_habitation.size();i++){
        if (_habitation[i].get_x()==x && _habitation[i].get_y()==y){
            _population=_population-_habitation[i].get_hab();
            _habitation.erase(_habitation.begin()+i);    
        }
    }
    for (int i=0;(int)_Gestion_dechet.size();i++){
        if (_Gestion_dechet[i].get_x()==x && _Gestion_dechet[i].get_y()==y){
            _nb_emploi=-_nb_emploi-_Gestion_dechet[i].get_ouvrier_max();
            _Gestion_dechet.erase(_Gestion_dechet.begin()+i);
        }
    }  
    for (int i=0;(int)_production_electricite.size();i++){
        if (_production_electricite[i].get_x()==x && _production_electricite[i].get_y()==y){
            _nb_emploi=-_nb_emploi-_production_electricite[i].get_ouvrier_max();
            _production_electricite.erase(_production_electricite.begin()+i);
        }
    }  
    for (int i=0;(int)_production_argent.size();i++){
        if (_production_argent[i].get_x()==x && _production_argent[i].get_y()==y){
            _nb_emploi=-_nb_emploi-_production_argent[i].get_ouvrier_max();
            _production_argent.erase(_production_argent.begin()+i);
        }
    }  
    if (effacer==1){
        _taux_d_emploi=std::min((_population*1.0)/_nb_emploi,1.0);
        update();
        return "Batiment supprimé '\n";
    }
    return "Il n'y a pas de batiment ici'\n";
}


void Ville::update(){
    _taux_d_emploi=std::min((_population*1.0)/_nb_emploi,1.0);;
    _argent+=get_revenue();
    std::cout<<check_pollution()<<'\n'<<check_electricite()<<'\n'<<check_dechet()<<'\n';

}

std::string Ville::create_habitation(Habitation B, int x, int y){
    int i;
    Habitation B_copy(x,y,B.get_prix(),B.get_conso_elec(),B.get_pollution(),B.get_image(),B.get_hab(),B.get_dechet());
    if (B_copy.get_prix()>_argent){return "Vous n'avez pas assez d'argent pour construire ce batiment";}

    for (i=0;i<(int)_Gestion_dechet.size();i++){
        if (_Gestion_dechet[i].get_x()==x &&_Gestion_dechet[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    for (i=0;i<(int)_production_electricite.size();i++){
        if (_production_electricite[i].get_x()==x &&_production_electricite[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    for (i=0;i<(int)_production_argent.size();i++){
        if (_production_argent[i].get_x()==x &&_production_argent[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    for (i=0;i<(int)_habitation.size();i++){
        if (_habitation[i].get_x()==x &&_habitation[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    for (i=0;i<(int)_batiments.size();i++){
        if (_batiments[i].get_x()==x &&_batiments[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    _taux_d_emploi=std::min((_population*1.0)/_nb_emploi,1.0);
    _population=_population+B_copy.get_hab();
    _argent=_argent-B.get_prix();
    _batiments.push_back(B_copy);
    _habitation.push_back(B_copy);
    this->update();
    return "Le batiment a été construit";
}


std::string Ville::create_production_argent(Production_argent B, int x, int y){
    int i;
    Production_argent B_copy(x,y,B.get_prix(),B.get_conso_elec(),B.get_pollution(),B.get_image(),B.get_ouvrier_max(),B.get_production_max());
    if (B_copy.get_prix()>_argent){return "Vous n'avez pas assez d'argent pour construire ce batiment";}
    for (i=0;i<(int)_batiments.size();i++){
        if (_batiments[i].get_x()==x &&_batiments[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    for (i=0;i<(int)_Gestion_dechet.size();i++){
        if (_Gestion_dechet[i].get_x()==x &&_Gestion_dechet[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    for (i=0;i<(int)_production_electricite.size();i++){
        if (_production_electricite[i].get_x()==x &&_production_electricite[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    for (i=0;i<(int)_production_argent.size();i++){
        if (_production_argent[i].get_x()==x &&_production_argent[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    for (i=0;i<(int)_habitation.size();i++){
        if (_habitation[i].get_x()==x &&_habitation[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
_nb_emploi=_nb_emploi+B_copy.get_ouvrier_max();
    _taux_d_emploi=std::min((_population*1.0)/_nb_emploi,1.0);
    _argent=_argent-B.get_prix();
    _batiments.push_back(B_copy);
    _production_argent.push_back(B_copy);
    update();
    return "Le batiment a été construit";
}



std::string Ville::create_production_elec(Production_electricite B, int x, int y){
    int i;
    Production_electricite B_copy(x,y,B.get_prix(),B.get_conso_elec(),B.get_pollution(),B.get_image(),B.get_ouvrier_max(),B.get_production_max());
    if (B_copy.get_prix()>_argent){return "Vous n'avez pas assez d'argent pour construire ce batiment";}
    for (i=0;i<(int)_Gestion_dechet.size();i++){
        if (_Gestion_dechet[i].get_x()==x &&_Gestion_dechet[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    for (i=0;i<(int)_production_electricite.size();i++){
        if (_production_electricite[i].get_x()==x &&_production_electricite[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    for (i=0;i<(int)_production_argent.size();i++){
        if (_production_argent[i].get_x()==x &&_production_argent[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    for (i=0;i<(int)_habitation.size();i++){
        if (_habitation[i].get_x()==x &&_habitation[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };    
    for (i=0;i<(int)_batiments.size();i++){
        if (_batiments[i].get_x()==x &&_batiments[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    _nb_emploi=_nb_emploi+B_copy.get_ouvrier_max();
    _taux_d_emploi=std::min((_population*1.0)/_nb_emploi,1.0);
    _argent=_argent-B_copy.get_prix();
    _batiments.push_back(B_copy);
    _production_electricite.push_back(B_copy);
    
    this->update();
    return "Le batiment a été construit";
}
  

std::string Ville::create_dechet(Gestion_dechet B, int x, int y){
    int i;
    Gestion_dechet B_copy(B.get_x(),B.get_y(),B.get_prix(),B.get_conso_elec(),B.get_pollution(),B.get_image(),B.get_ouvrier_max(),B.get_production_max());
    if (B_copy.get_prix()>_argent){
        return "Vous n'avez pas assez d'argent pour construire ce batiment";
    }
    B_copy.set_x(x);B_copy.set_y(y);
    for (i=0;i<(int)_Gestion_dechet.size();i++){
        if (_Gestion_dechet[i].get_x()==x &&_Gestion_dechet[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    for (i=0;i<(int)_production_electricite.size();i++){
        if (_production_electricite[i].get_x()==x &&_production_electricite[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    for (i=0;i<(int)_production_argent.size();i++){
        if (_production_argent[i].get_x()==x &&_production_argent[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    for (i=0;i<(int)_habitation.size();i++){
        if (_habitation[i].get_x()==x &&_habitation[i].get_y()==y){return "Impossible de construire ce bâtiment sur un autre bâtiment existant";}
    };
    _nb_emploi=_nb_emploi+B_copy.get_ouvrier_max();
    _taux_d_emploi=std::min((_population*1.0)/_nb_emploi,1.0);
    _argent=_argent-B.get_prix();
    _batiments.push_back(B_copy);
    _Gestion_dechet.push_back(B_copy);
    
    this->update();
    return "Le batiment a été construit";
}

std::ostream& operator<<(std::ostream& os,const Ville &V){
            os<<V._nom<<" : \n"<<"Pollution générée : "<<V._pollution<<" tonnes de CO2 sur les "<<V._limite_pollution<<" maximales autorisées.\n";
            os<<"Population actuelle : "<<V._population<<"\nBudget restant : "<<V._argent<<"\nBilan électrique : "<<V._solde_electricite;
            os<<"\nNombres d'emplois max : "<<V._nb_emploi<<"\nTaux d'emploi : "<<V._taux_d_emploi<<'\n';
            return os;
};