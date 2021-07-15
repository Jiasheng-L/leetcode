

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH      10000

bool check_match(char *str1, int pos1, char * c1, char c2)
{

}


bool isValid(char * s){

    bool rc = true;
    int len = strlen(s);
    if (len % 2 )
        return false;

    int i = 0, j = 0;
    char *str = (char *)malloc(len / 2 + 1);
    memset(str, 0, len / 2 + 1);

    while(i<len && rc)
    {
        switch (*(s+i))
        {
        case '(':
        case '[':
        case '{':
            *(str + j) = *(s + i);
            j++;
            break;
        case ')':
            if (j==0)
            {
                rc = false;
            }
            else
            {
                if (*(str+j - 1) != '(')
                {
                    rc = false;
                }
                else
                {
                    *(str + j - 1) = 0;
                    j--;
                }
            }
            break;
        case ']':
            if (j==0)
            {
                rc = false;
            }
            else
            {
                if (*(str+j - 1) != '[')
                {
                    rc = false;
                }
                else
                {
                    *(str + j - 1) = 0;
                    j--;
                }
            }
            break;
        case '}':
            if (j==0)
            {
                rc = false;
            }
            else
            {
                if (*(str+j - 1) != '{')
                {
                    rc = false;
                }
                else
                {
                    *(str + j - 1) = 0;
                    j--;
                }
            }
            break;
        default:
            break;
        }

        if (!rc)
        {
            break;
        }
        i++;
    }
    free(str);
    if (j != 0)
    {
        rc = false;
    }
    return rc;
}

bool check(char *s)
{
    while(*s != '\0')
    {
        if (*s == '(' || *s == ')' || 
            *s == '[' || *s == ']' || 
            *s == '{' || *s == '}'
            )
            {
                s++;
            }
        else
        {
            break;
        }
    }
    return (*s == '\0' ? true : false);
}

int main()
{
    char str[MAX_LENGTH] = {0};
    char ch = 'y';
    do
    {
        puts("input (, ), [, ], {, }");
        scanf("%s", str);

        if (!check(str))
        {
            continue;
        }

        if (isValid(str))
        {
            puts("yes");
        }
        else
        {
            puts("no");
        }

        do
        {
            puts("continue [y] ");
            ch = getchar();
            if (ch == '\n' || ch == '\r')
            {
                ch = getchar();
            }
        } while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
