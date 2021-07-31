
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne1(int* digits, int digitsSize, int* returnSize){
    int add = 0;
    int *result = (int *)malloc(sizeof(int) * digitsSize);
    int *res = NULL;
    if (result == NULL)
    {
        return NULL;
    }
    memset(result, 0, digitsSize);
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        if (i == digitsSize-1)
        {
            result[i] = (digits[i] + 1 ) % 10;
            add = (digits[i] + 1 ) / 10;
        }
        else
        {
            result[i] = (digits[i] + add) % 10;
            add = (digits[i] + add) / 10;
        }
    }
    
    if (add)
    {
        // result = (int *)realloc(result, sizeof(int) * (digitsSize + 1));
        *returnSize = digitsSize+1;
        res = (int *)malloc(sizeof(int) * (digitsSize + 1));
        for(int i=0; i<*returnSize; i++)
        {
            *(res+i) = 0;
        }
        memset(res, 0x0, digitsSize + 1);
        memcpy(res + 1, result, digitsSize);
        res[0] = add;
        free(result);
        result = NULL;
        return res;
    }
    *returnSize = digitsSize;
    return result;
}

int main()
{
    int digit[1] = { 9 };
    int *result = NULL;
    int len = sizeof(digit) / sizeof(digit[0]);
    int size = 0;
    result = plusOne1(digit, len, &size);
    printf("size = %d\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", result[i]);
    }
    return 0;
}
