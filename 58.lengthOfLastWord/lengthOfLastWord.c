
#include <stdio.h>

int lengthOfLastWord(char * s){
    int len = 0, last = 0;
    while (*s != '\0')
    {
        if (*s != ' ')
        {
            len++;
        }
        else
        {
            if (len)
            {
                last = len;
                len = 0;
            }
        }
        s++;
    }

    return (len?len:last);
}

int main()
{
    char *s = "hello  ";

    int len = lengthOfLastWord(s);

    printf("len = %d", len);

    return 0;
}