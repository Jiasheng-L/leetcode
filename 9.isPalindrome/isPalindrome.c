
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(int x){
    bool rc = true;
    char num_str[50] = {0};
    sprintf(num_str, "%d", x);
    int len = strlen(num_str);
    int i = 0;
    while (i<len && len > 0)
    {
        if (num_str[i] == num_str[len-1])
        {
            i++;
            len--;
            continue;
        }
        else
        {
            rc = false;
            break;
        }
    }

    return rc;
}


bool isPalindrome_no_str(int x){
    bool rc = true;
    if (x < 0)
    {
        rc = false;
    }
    else if (x == 0)
    {
        rc = true;
    }
    else
    {
        long i = 10, j = 1;
        while (x / i)
        {
            i *= 10;
            j++;
        }
        i = i / 10;
        j /= 2;
        while (j--)
        {
            if (x%10 == x/i)
            {
                x = x - (x / i) * i;
                x /= 10;
                i /= 100;
                continue;
            }
            else
            {
                rc = false;
                break;
            }
        }
    }
    return rc;
}



int main()
{

    int num;

    char ch = 'y';
    do
    {
        puts("input a num");
        scanf("%d", &num);

        if (isPalindrome_no_str(num))
        {
            puts("yes\n");
        }
        else
        {
            puts("no\n");
        }
        {
            do
            {
                printf("continue? [y]");
                ch = getchar();
                if (ch == '\r' || ch == '\n')
                {
                    ch = getchar();
                }
            } while (ch != 'n' && ch != 'y' && ch != 'N' && ch != 'Y');
        }
    } while (ch == 'y' || ch == 'Y');
    return 0;
}