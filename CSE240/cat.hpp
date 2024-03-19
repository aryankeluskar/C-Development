#ifndef Cat_hpp
#define Cat_hpp

#include <iostream>
#include <string>
#include "pet.hpp"

using namespace std;

// derived class Cat from the base class Pet
class Cat: public Pet{
    public:
        // overloaded constructor
        Cat(string name, int weight):Pet(name, weight){
            this->name = name;
            this->weight = weight;
        };
        int CalculateFee(){
            // since the rate is 1.5 for dogs, the fee is calculated by multiplying the weight by 2 and returned
            return weight * 1.5;
        };
    private:
        string name;
        int weight;
};

#endif