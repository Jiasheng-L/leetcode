
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define NUM_STRS        200
#define LEN_STR         200

static int _getCommPrefixLen(char *s1, char *s2)
{
    int len = 0;
    while(*s1!= '\0' && *s2 != '\0' && *s1 == *s2)
    {
        len++;
        s1++;
        s2++;
    }
    return len;
}

char * longestCommonPrefix(char ** strs, int strsSize){
    int len = 0, len_temp = strlen(*strs);
    char *s;
    if (strsSize == 0)
    {
        return "";
    }
    if (strsSize == 1)
    {
        return *strs;
    }

    for (int i = 0; i < strsSize - 1; i++)
    {
        len = _getCommPrefixLen(*(strs + i), *(strs + i + 1));
        if (len > len_temp)
        {
            len = len_temp;
        }
        else
        {
            len_temp = len;
        }
    }
    if (len)
    {
        s = (char *)malloc(len + 1);
        memset(s, 0, len + 1);
        memcpy(s, *strs, len);
        return s;
    }
    else
    {
        return "";
    }
}

int main()
{
    int num_str = 0;
    char *strs[NUM_STRS];
    char str[LEN_STR];
    printf("how many strings do you want to input");
    scanf("%d", &num_str);
    for (int i = 0; i < num_str;i++)
    {
        puts("input the first string");
        scanf("%s", str);
        strs[i] = (char *)malloc(strlen(str) + 1);
        memset(strs[i], 0, strlen(str) + 1);
        strncpy(strs[i], str, strlen(str));
    }

    memset(str, 0, LEN_STR);
    char *prefix = longestCommonPrefix((char **)&strs, num_str);

    printf("prefix = %s", prefix);

    return 0;
}
