#include <stdio.h>
#include <stdint.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

int main()
{
   int x;
   printf("Enter a number: ");
   scanf("%d", &x);
   printf("The absolute value of %d is %d\n", x, ABS(x));
}