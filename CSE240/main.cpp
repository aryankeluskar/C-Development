#include <iostream>
#include <string>
#include <vector>

#include "pet.hpp"
#include "cat.hpp"
#include "dog.hpp"


using namespace std;

int main(){
    Dog dog1("Bob", 65);
    Dog dog2("Stan", 37);
    Cat cat1("Tom", 12);

    vector<Pet*> pvec;
    pvec.push_back(&dog1);
    pvec.push_back(&dog2);
    pvec.push_back(&cat1);
    
    float total_fee = 0;
    for (int i = 0; i < pvec.size(); i++)
    {
        cout << pvec[i]->GetName() << ' ' << pvec[i]->CalculateFee() << endl;
        total_fee = total_fee + pvec[i]->CalculateFee();
    }
    cout << "total licensing fee = " << total_fee << endl;    

}

