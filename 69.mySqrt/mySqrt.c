
#include <stdio.h>
#include <stdlib.h>
// #include <math.h>

// to use sqrt(), need to add link parameter for math.lib
// int mySqrt1(int x)
// {
//     double d = sqrt(x);
//     return ((int)d);
// }

int mySqrt2(int x)
{
    long i;
    for (i = 0; i * i <= x; i++)
        ;
    return (int)(i - 1);
}

int main()
{
    int x = 5;
    int i = mySqrt2(x);
    printf("result=%d", i);
}
