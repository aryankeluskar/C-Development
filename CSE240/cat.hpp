#ifndef Cat_hpp
#define Cat_hpp

#include <iostream>
#include <string>
#include "pet.hpp"

using namespace std;

class Cat: public Pet{
    public:
        Cat(string name, int weight):Pet(name, weight){
            this->name = name;
            this->weight = weight;
        };
        int CalculateFee(){
            return weight * 1.5;
        };
    private:
        string name;
        int weight;
};

#endif