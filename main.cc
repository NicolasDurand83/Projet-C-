#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Habitation.hh"
#include "Production_argent.hh"
#include "Production_electricite.hh"
#include "Gestion_dechet.hh"
#include "Ville.hh"
/*
//Test affichage Habitation
void test1(){
    int x=1;
    int y=3;
    int prix=400;
    int conso_elec=25;
    int pollution=250;
    std::string image="firas";
    int nb_habitant=260;
    int dechet=36;
    Habitation h(x,y,prix,conso_elec, pollution,image,nb_habitant,dechet);
    std::cout<<h.info()<<std::endl;
}

//Test affichage d'un batiment produisant de l'argent 
void test2(){
   int x=1;
      int y=2;
      int longueur=3;
      int largeur=4;
      int prix=200;
      int conso_elec=300;
      int pollution=500;
      std::string image="firas";
      int ouvrier_max=33;
      int nb_ouvrier=55;
      int production_max=654;
     Production_argent a(x,y,prix,conso_elec,pollution,image,ouvrier_max,production_max);
     std::cout<<a.info()<<std::endl;
     
}

//Test affichage d'un batiment produisant de l'électricité
void test3(){
   int x=1;
      int y=2;
      int prix=200;
      int conso_elec=300;
      int pollution=500;
      std::string image="firas";
      int ouvrier_max=33;
      int nb_ouvrier=55;
      int production_max=654;
     Production_electricite a(x,y,prix,conso_elec,pollution,image,ouvrier_max,production_max);
     std::cout<<a.info()<<std::endl;
    }

//Test affichage d'un batiment de gestion de déchet
void test4(){
   int x=1;
      int y=2;

      int prix=200;
      int conso_elec=300;
      int pollution=500;
      std::string image="firas";
      int ouvrier_max=33;
      int production_max=654;
     Gestion_dechet a(x,y,prix,conso_elec,pollution,image,ouvrier_max,production_max);
     std::cout<<a.info()<<std::endl;
     
}*/
void test_same_place(){
    Habitation maison(0,0,1125,34,4,"1",3,6);
    Ville EV("Ecoville",100,1000000);
    EV.create_habitation(maison,0,0);//<<"\n";
    EV.create_habitation(maison,0,0);
    std::cout<<EV;
}


int main(){
    Habitation maison(0,0,1125,34,4,"1",3,6);
    Habitation immeuble(0,0,2700,161,29,"1",35,16);
    Habitation immeuble2(0,0,19575,641,115,"1",52,100);
    Habitation immeuble3(0,0,14616,220,40,"1",35,80);
    Habitation tour(0,0,39150,165,363,"1",131,200);


    Gestion_dechet dechetterrie(0,0,300,250,250,"1",8,553);
    Gestion_dechet incinerateur(0,0,4400,1634,615,"1",40,2028);

    Production_electricite centrale_thermique(0,0,170000,0,17062,"1",40,48750);
    Production_electricite eolienne(0,0,2000,0,6,"1",2,4174);

    Production_argent magasin(0,0,20000,93,680,"1",20,2000);
    Production_argent centre_commercial(0,0,186,93,4790,"1",100,9000);


    Ville EV("Ecoville",100,1000000);
    /*std::cout<<*/EV.create_habitation(maison,0,0);//<<"\n";
    /*std::cout<<*/EV.create_habitation(maison,1,1);//<<"\n";
    //std::cout<<EV.get_argent()<<std::endl;
    //std::cout<<EV.create_habitation(maison,0,1)<<"\n";
    //std::cout<<EV.get_argent();
    //std::cout<<EV.create_production_elec(centrale_thermique,1,0)<<'\n';
    //std::cout<<EV.create_dechet(dechetterrie,2,0)<<'\n';
    //std::cout<<EV.create_production_argent(magasin,3,0)<<'\n';
    EV.update();
        /*
    std::cout<<EV.create_habitation(maison,0,0)<<"\n"; 

    std::cout<<EV.create_habitation(maison,0,0)<<"\n"; 

   
   
    EV.update_pop();*/
    std::cout<<EV;
    return 0;
}