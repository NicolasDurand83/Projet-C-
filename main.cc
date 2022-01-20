#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Habitation.hh"
#include "Production_argent.hh"
#include "Production_electricite.hh"
#include "Gestion_dechet.hh"
#include "Ville.hh"
/*
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
    //test4();      
    return 1;
}*/
int main(){
    Habitation maison(0,0,1,1,1125,34,4,"1",3,6);
    Habitation immeuble(0,0,2,1,2700,161,29,"1",35,16);
    Habitation immeuble2(0,0,2,1,19575,641,115,"1",52,100);
    Habitation immeuble3(0,0,2,1,14616,220,40,"1",35,80);
    Habitation tour(0,0,2,1,39150,165,363,"1",131,200);


    Gestion_dechet dechetterrie(0,0,1,1,300,250,250,"1",8,553);
    Gestion_dechet incinerateur(0,0,2,2,4400,1634,615,"1",40,2028);

    Production_electricite centrale_thermique(0,0,2,3,170000,0,17062,"1",40,48750);
    Production_electricite eolienne(0,0,1,1,2000,0,6,"1",2,4174);

    Production_argent magasin(0,0,1,1,20000,93,680,"1",20,2000);
    Production_argent centre_commercial(0,0,3,2,186,93,4790,"1",100,9000);


    Ville EV("Ecoville",100000,100000);
    std::cout<<EV.create_habitation(maison,0,0)<<"\n";
    return 0;
}