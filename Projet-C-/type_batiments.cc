#include "Habitation.hh"
#include "Gestion_dechet.hh"
#include "Production_argent.hh"
#include "Production_electricite.hh"


Habitation maison(0,0,1,1,1125,34,4,"",3,6);

Habitation immeuble(0,0,2,1,2700,161,29,"",35,16);

Habitation immeuble2(0,0,2,1,19575,641,115,"",52,100);
Habitation immeuble3(0,0,2,1,14616,220,40,"",35,80);

Habitation tour(0,0,2,1,39150,165,363,"",131,200);


Gestion_dechet dechetterrie(0,0,1,1,300,250,250,"",8,0,553);
Gestion_dechet incinerateur(0,0,2,2,4400,1634,615,"",40,0,2028);

Production_electricite centrale_thermique(0,0,2,3,170000,0,17062,"",40,0,48750);
Production_electricite eolienne(0,0,1,1,2000,0,6,"",2,0,4174);

Production_argent magasin(0,0,1,1,20000,93,680,"",20,0,2000);
Production_argent centre_commercial(0,0,3,2,186,93,4790,"",100,0,9000);