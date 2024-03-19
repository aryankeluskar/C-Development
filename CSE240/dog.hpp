#ifndef Dog_hpp
#define Dog_hpp

#include <iostream>
#include <string>
#include "pet.hpp"

using namespace std;

// derived class Dog from the base class Pet
class Dog: public Pet{
    public:
        // overloaded constructor
        Dog(string name, int weight):Pet(name, weight){
            this->name = name;
            this->weight = weight;
        };
        int CalculateFee(){
            // since the rate is 2 for dogs, the fee is calculated by multiplying the weight by 2 and returned
            return weight * 2;
        };
    private:
        string name;
        int weight;
};

#endif

