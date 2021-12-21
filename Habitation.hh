#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "Batiment.hh"


class Habitation :public Batiment{
    public:
        Habitation();
        //Habitation();
        ~Habitation();
    private:
        int _nb_habitant;
        int _dechet;
};