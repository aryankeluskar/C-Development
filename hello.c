#include <stdio.h>
int main(){
    // for printing hello world, printf is the syntax
    printf("Hello World!\n");

    // vars
    int x;
    x=10;
    int y=23;
    float f=2.31;
    float res = x*y-f;
    char name[] = "result";
    printf("the %s is %f", name, res);
    return 0;
}