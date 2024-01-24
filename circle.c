#include <stdio.h>
#define PI 3.1416
#define AREA_CALC(rad) PI*rad*rad


int main()
{
float radius, area;
printf("Enter the radius: ");
scanf("%f", &radius);
area = AREA_CALC(radius);
printf("Area = %f\n", area);
}
