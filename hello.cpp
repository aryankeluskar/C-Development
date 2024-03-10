#include <iostream>
#include <string>

using namespace std; // Add missing namespace

class Student {
    public:
    Student(){}
    Student(string name, int gpa){
        this->name = name;
        this->gpa = gpa;
    }
    string getNam(){
        return name;
    }
    int getGpa(){
        return gpa;
    }
    private:
    string name;
    int gpa;
}; 

class Shape {
    public:
    int area(){return this->height * this->width;}
    int perimeter(){return 2 * (this->height + this->width);};
    int setHeight(int h){this->height = h;}
    int setWidth(int w){this->width = w;}
    private:
    int height;
    int width;
};

int main(int argc, char *argv[]) {
    cout << "Hello World!\n" << endl;
    int i;
    cin >> i;
    Student s("John", i);
    cout << s.getNam() << "'s GPA is " << s.getGpa() << endl;

    Shape shape;
    int h, w;
    cin >> h >> w;
    shape.setHeight(h);
    shape.setWidth(w);
    cout << "Area: " << shape.area() << endl;
    cout << "Perimeter: " << shape.perimeter() << endl;

    return 0;
}