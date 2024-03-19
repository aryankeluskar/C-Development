#ifndef Pet_hpp
#define Pet_hpp

#include <iostream>
#include <string>
using namespace std;

class Pet{
    public:
        string GetName(){return name;};
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