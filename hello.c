#include <stdio.h>

struct student{
    int roll;
    char name[20];
    float marks;
};

typedef struct student asu;

enum numbers {zer, one, two, three, four, five, six, seven, eight, nine, ten};

int main(){
    // for printing hello world, printf is the syntax
    printf("Hello World!\n");

    asu s1;
    s1.roll = 1;
    s1.marks = 90.5;

    // vars
    int x;
    x=10;
    int y=23;
    float f=2.31;
    float res = x*y-f;
    char name[] = "result";
    printf("the %s is %f", name, res);
    // return 0;

    printf("\n%d", one);
    enum numbers n = two;
    n++;
    printf("\n%d", n);

}