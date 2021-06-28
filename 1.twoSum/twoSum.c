#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    int *result = NULL;
    *returnSize = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] >= target)
        {
            continue;
        }
        for (j=i+1; j<numsSize; j++)
        {
            if (*(nums+i) + *(nums+j) == target)
            {
                if (result == NULL)
                {
                    result = (int *)malloc(sizeof(int) * 2);
                }
                if (result)
                {
                    *(result) = i;
                    *(result + 1) = j;
                    *returnSize = 2;
                }
            }
        }
    }
    return result;
}

#define NUM 10

int main()
{
    int nums[NUM] = {0};
    int i = 0, target=0;
    int size = 0, returnsize=0;
    int *result=NULL;
    puts("input size:");
    scanf("%d", &size);
    if (size > NUM)
    {
        puts("errors in input");
    }
    puts("input a number");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &nums[i]);
    }
    puts("input target:");
    scanf("%d", &target);

    result = twoSum(nums, size, target, &returnsize);
    if (result)
    {
        printf("[%d, %d]", *result, *(result+1));
        free(result);
    }
    putchar('\n');
    return 0;
}
