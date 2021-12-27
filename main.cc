#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Ville.hh"
/*
void test_batiment(){
    Batiment b1();
    Batiment b2(1,2,3,4,5,6,"fazef");
    
}*/

int main(){
    Ville v("newville",10,10);
 
    //switch ((typeid(T)) { case typeid(myClassA): // handle that case break; 
    //case typeid(myClassB): // handle that case break;
    std::cout<<v.get_name()<<std::endl;
    std::cout<<v.check_electricite()<<std::endl;


}
