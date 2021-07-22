
#include <stdio.h>
#include <string.h>



int strStr(char * haystack, char * needle)
{
    if (*needle == '\0')
    {
        return 0;
    }
    else if (*haystack == '\0')
    {
        return -1;
    }
    int pos = -1;
    int i = 0, j = 0;
    while (*(haystack+i) != '\0' && *(needle+j) != '\0')
    {
        if (*(haystack+i) == *(needle+j))
        {
            if (j==0)
            {
                pos = i;
            }
            j++;
        }
        else
        {
            if (pos != -1)
            {
                i = pos;
            }
            j = 0;
            pos = -1;
        }
        i++;
    }
    if (*(needle+j) != '\0')
    {
        pos = -1;
    }
    return pos;
}

int main()
{
    char haystack[1000] = {0};
    char needle[1000] = {0};
    puts("input a string for haystack:");
    char ch;
    int pos = 0;
    while ((ch = getchar()) != '\n')
    {
        haystack[pos++] = ch;
    }
    haystack[pos] = '\0';
    puts("input a needle:");
    pos = 0;
    while ((ch = getchar()) != '\n')
    {
        needle[pos++] = ch;
    }
    needle[pos] = '\0';
    pos = strStr(haystack, needle);
    printf("pos=%d", pos);
}
