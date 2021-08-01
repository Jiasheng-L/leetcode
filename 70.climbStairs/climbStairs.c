

#include <stdio.h>

/*
2  3  4  5
2, 3, 5, 8

4
1 1 1 1
1 1 2
1 2 1
2 1 1
2 2

5
1 1 1 1 1
1 1 1 2
1 1 2 1
1 2 1 1
2 1 1 1
1 2 2
2 1 2
2 2 1
*/


// 斐波那契数列
// 用递归，需要注意 callstack deepth.
int climbStairs(int n)
{
    if (n == 2 || n == 3 || n== 1)
    {
        return n;
    }
    else
    {
        return (climbStairs(n - 1) + climbStairs(n - 2));
    }
}


int climbStairs2(int n)
{
    int a=1, b=2;
    int nums = 0;

    if (n == 1 || n == 2)
    {
        return n;
    }
    for (int i = 3; i <= n;i++)
    {
        nums = a + b;
        a = b;
        b = nums;
    }
    return nums;
}

int main()
{
    int n = climbStairs2(5);
    printf("nums=%d\n", n);
}
