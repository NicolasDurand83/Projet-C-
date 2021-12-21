#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Batiment.hh"

class Batiment_production: public Batiment{
    public:
        Batiment_production();
        
        ~Batiment_production();
    private:
        int _ouvrier_max;
        int _nb_ouvrier;
        int _production_max;
};