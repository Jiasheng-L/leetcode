
#include <stdio.h>
#include <string.h>

char roman_char[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int roman_num[] = {1, 5, 10, 50, 100, 500, 1000};

static int _get_pos_roman_char(char ch)
{
    int pos = -1;
    for (int i = 0; i < sizeof(roman_char); i++)
    {
        if (ch == roman_char[i])
        {
            pos = i;
            break;
        }
    }
    return pos;
}


int romanToInt(char * s)
{
    int pos = 0, pos_next = 0;
    int num = 0;
    char ch_next, ch;
    while(*s != '\0')
    {
        ch = *s;
        ch_next = *(s + 1);
        pos_next = _get_pos_roman_char(ch_next);
        pos = _get_pos_roman_char(ch);
        if (pos_next > pos)
        {
            num += roman_num[pos_next] - roman_num[pos];
            s++;
        }
        else
        {
            num += roman_num[pos];
        }
        s++;
    }
    return num;
}

int check_value(char *s)
{
    int flag = 1;
    while (*s != '\0' && flag)
    {
        if (_get_pos_roman_char(*s) < 0)
        {
            flag = 0;
            break;
        }
        s++;
    }
    return flag;
}

int main()
{
    char reman[20] = {0};
    char input = 'y';
    while(input == 'y' || input == 'Y')
    {
        do
        {
            puts("input a string (length <= 15)");
            scanf("%s", reman);
            if (check_value(reman) != 0)
            {
                break;
            }
            else
            {
                puts("wrong num");
            }
        } while (1);

        int num = romanToInt(reman);
        printf("output num = %d\n", num);

        do
        {
            printf("\ncontinue [y]?");
            scanf("%c", &input);
            if (input == '\n' || input == '\r')
            {
                scanf("%c", &input);
            }
        } while (input != 'y' && input != 'Y' && input != 'n' && input != 'N');
    }

    return 0;
}