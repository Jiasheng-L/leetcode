
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reverse(char *a)
{
    long len = strlen(a);
    char *b = malloc(sizeof(char) * (len + 1));
    memset(b, 0, len + 1);
    for (int i = 0; i < len; i++)
    {
        *(b + i) = *(a + len - i - 1);
    }
    return b;
}

char * addBinary(char * a, char * b)
{
    char *s1 = reverse(a);
    char *s2 = reverse(b);
    long a_len = strlen(s1);
    long b_len = strlen(s2);
    long len = a_len > b_len ? a_len + 1 : b_len + 1;
    char *result = (char *)malloc(sizeof(char) * (len + 1));
    int add = 0, a1, b1;
    memset(result, 0, len + 1);
    long i = 0;
    while (i < a_len || i < b_len)
    {
        if (i < a_len)
        {
            a1 = *(s1 + i) - '0';
        }
        if (i < b_len)
        {
            b1 = *(s2 + i) - '0';
        }

        if (i < a_len && i < b_len)
        {
            result[i] = a1 + b1 + add;
        }
        else if ( i < a_len)
        {
            result[i] = a1 + add;
        }
        else if ( i < b_len )
        {
            result[i] = b1 + add;
        }
        else
        {
            printf("should not come here!");
            exit(-1);
        }
        add = result[i] / 2;
        result[i] %= 2;
        result[i] = result[i] + '0';
        i++;
    }
    if (add)
    {
        result[i] = add + '0';
    }
    char *res = reverse(result);
    free(result);
    free(s1);
    free(s2);
    return res;
}

int main()
{

    // char *a = "this is a string";
    // char *b = reverse(a);
    char *a = "11";
    char *b = "1";
    printf("a=%s\n", a);
    printf("b=%s\n", b);

    char *c = addBinary(a, b);

    printf("%s", c);
    return 0;
}