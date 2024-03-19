#ifndef Dog_hpp
#define Dog_hpp

#include <iostream>
#include <string>
#include "pet.hpp"

using namespace std;

class Dog: public Pet{
    public:
        Dog(string name, int weight):Pet(name, weight){
            this->name = name;
            this->weight = weight;
        };
        int CalculateFee(){
            return weight * 2;
        };
    private:
        string name;
        int weight;
};

#endif

