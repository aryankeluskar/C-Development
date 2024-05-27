#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream f1;
    f1.open("./hi.txt");
    
    f1 << "Hello World!";
    f1.close();
    // return 0;

    ifstream f2("./hi.txt");
    if(f2.is_open()){
        string line;
        while(getline(f2, line))
            cout << line << endl;
        f2.close();
    }
}