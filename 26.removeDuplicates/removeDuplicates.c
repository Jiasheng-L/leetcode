
#include <stdio.h>

int checkDuplicate(int *nums, int len, int val)
{
    while(--len>=0)
    {
        if(nums[len] == val)
        {
            return len;
        }
    }
    return len;
}

int removeDuplicates(int* nums, int numsSize)
{
    int i = 0, j = 0;
    int temp;

    while(i<numsSize)
    {
        if (checkDuplicate(nums, j, nums[i]) < 0)
        {
            nums[j++] = nums[i];
        }
        i++;
    }
    return j;
}

int main()
{
    int nums[100] = {0};
    int len = 0;
    puts("input num len:");
    scanf("%d", &len);
    puts("input nums by asc");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", nums + i);
    }
    puts("original array:");
    for (int i = 0; i < len;i++)
    {
        printf("%4d\t", nums[i]);
    }
    putchar('\n');
    int len_ = removeDuplicates(nums, len);
    printf("output length=%d\n", len_);
    puts("now arrays:");
    for (int i = 0; i < len_;i++)
    {
        printf("%4d\t", nums[i]);
    }
}