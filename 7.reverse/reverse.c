
#include <stdio.h>
#include <limits.h>


int reverse(int x)
{
    long r = 0, y = x;
    char sign = 1;
    if (y < 0)
    {
        sign = -1;
        y = (long)x * sign;
    }

    while(y>=10)
    {
        r += y % 10;
        r *= 10;
        y /= 10;
    }
    r += y;
    r *= sign;

    if ((r < INT_MIN) || (r > INT_MAX))
    {
        r = 0;
    }
    return (int)r;
}

int main()
{
    int num;
    puts("input a number");
    scanf("%d", &num);

    int ret = reverse(num);
    printf("num=%d,\nret=%d", num, ret);
}
