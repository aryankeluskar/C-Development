#include <stdio.h>
#include <stdint.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

struct class{
   char[] dept;
   int code;
   char[] faculty;
   
}

int main()
{
   char c;
   short s;
   int i;
   long l;
   long long ll;
   float f;
   double d;
   long double ld;
   printf("char: %lu\n", sizeof(c));
   printf("short: %lu\n", sizeof(s));
   printf("int: %d\n", sizeof(i));
   printf("long: %lu\n", sizeof(l));
   printf("long long: %lu\n", sizeof(ll));
   printf("float: %lu\n", sizeof(f));
   printf("double: %lu\n", sizeof(d));
   printf("long double: %lu\n", sizeof(ld));

   int x[2];
   x[0] = 5;
   x[1] = 6;
   printf("Enter a number: ");
   scanf("%d", &x[0]);
   int *p = &x[0];
   printf("The ptr is %d\n", p);
   printf("The number is %d\n", *(p + 1));
}