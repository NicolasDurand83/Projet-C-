#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Habitation.hh"
#include "Production_argent.hh"
#include "Production_electricite.hh"
#include "Gestion_dechet.hh"
#include "ville.hh"

void test1(){
    int x=1;
    int y=3;
    int longueur=5;
    int largeur=2;
    int prix=400;
    int conso_elec=25;
    int pollution=250;
    std::string image="firas";
    int nb_habitant=260;
    int dechet=36;
    Habitation h(x,y,longueur,largeur,prix,conso_elec, pollution,image,nb_habitant,dechet);
    std::cout<<h.info()<<std::endl;
}
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
     Production_argent a(x,y,longueur,largeur,prix,conso_elec,pollution,image,ouvrier_max,nb_ouvrier,production_max);
     std::cout<<a.info()<<std::endl;
     
}
void test3(){
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
     Production_electricite a(x,y,longueur,largeur,prix,conso_elec,pollution,image,ouvrier_max,nb_ouvrier,production_max);
     std::cout<<a.info()<<std::endl;
     
}
void test4(){
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
     Gestion_dechet a(x,y,longueur,largeur,prix,conso_elec,pollution,image,ouvrier_max,nb_ouvrier,production_max);
     std::cout<<a.info()<<std::endl;
     
}
int main(){
    //Ville v("villeecccccoooo",100000,100);
    Ville v;
    Ville v2("firas",10,100);
    test4();      
    return 1;
}