#include <iostream>
#include <string>
#include <vector>

#include "pet.hpp"
#include "cat.hpp"
#include "dog.hpp"
// using inheritance to create a polymorphic vector of pets by including the required header files

using namespace std;

int main(){
    // instantiating objects of the derived classes
    Dog dog1("Bob", 65);
    Dog dog2("Stan", 37);
    Cat cat1("Tom", 12);

    // creating a vector of pointers to the base class
    vector<Pet*> pvec;
    pvec.push_back(&dog1);
    pvec.push_back(&dog2);
    pvec.push_back(&cat1);
    
    // code exactly as given in the A9.pdf
    float total_fee = 0;
    for (int i = 0; i < pvec.size(); i++)
    {
        cout << pvec[i]->GetName() << ' ' << pvec[i]->CalculateFee() << endl;
        total_fee = total_fee + pvec[i]->CalculateFee();
    }
    cout << "total licensing fee = " << total_fee << endl;    

}

