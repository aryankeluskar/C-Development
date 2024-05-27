#include <iostream>
#include <string>

using namespace std;

class goofy{
    private:
        string name;
        int age;

    public:
        goofy(string nmIn, int agIn){
            this->name = nmIn;
            this->age = agIn;
        }

        goofy(string n):name("hi lol"),age(10) {};

        void goofaround(){
            cout << "I am " << name << " and I am " << age << " years old." << endl;
        }

        void design();

        void setname(string x){
            name = x;
        }

        void setage(int x){
            age = x;
        }

        string getname(){
            return name;
        }

        int getage(){
            return age;
        }


};

void goofy::design()
{
    cout << "Haha, i design \n";
    try
    {
        stof("hi");
    }
    catch(const std::exception& e)
    {
        std::cerr << "error caught" << '\n';
    }

    try
    {
        stof("5.5");
        cout << "success" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "error caught" << '\n';
    }
    

}

int main() {
    string sent = "Hello World!";
    int chage = 55;

    goofy g1("Soham", 23);

    g1.goofaround();
    cout << "Name: " << g1.getname() << endl;

    cout << "Enter a new name haha: " << endl;
    string newName;
    cin >> newName;
    // getline(cin, newName);
    cout << newName << endl;
    
    g1.setname(newName);

    g1.design();

    g1.goofaround();

    goofy g2("hi");
    g2.goofaround();


}