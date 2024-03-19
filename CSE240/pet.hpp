#ifndef Pet_hpp
#define Pet_hpp

#include <iostream>
#include <string>
using namespace std;

// base class Pet that has getName function which is common to all the derived classes
// and CalculateFee as pure virtual functions since the fee calculation is different for each derived class (Dog and Cat)
class Pet{
    public:
        string GetName(){return name;};

        // pure virtual function as instructed in the A9.pdf
        virtual int CalculateFee() = 0;
        Pet(string name, int weight){
            this->name = name;
            this->weight = weight;
        };
    private:
        string name;
        int weight;
};

#endif