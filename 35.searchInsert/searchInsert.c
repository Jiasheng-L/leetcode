

#include <stdio.h>


int searchInsert(int* nums, int numsSize, int target){
    int start = 0, end = numsSize - 1;
    int middle = (start + end) / 2;

    if (nums[start] >= target)
    {
        return start;
    }
    if (nums[end] <= target)
    {
        if (nums[end] == target)
            return end;
        return end + 1;
    }

    while (start < end)
    {
        if (nums[middle] > target)
        {
            if (nums[middle-1]< target)
            {
                return middle;
            }
            end = middle - 1;
        }
        else if (nums[middle] < target)
        {
            if (nums[middle+1] > target)
            {
                return middle + 1;
            }
            start = middle + 1;
        }
        else
        {
            return middle;
        }
        middle = (start + end) / 2;
    }

    return start;
}

int main()
{
    int nums[100] = {0};
    int len = 0;
    int target = 0;
    puts("input length:");
    scanf("%d", &len);
    puts("input sequenced numbers");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &(nums[i]));
    }

    for (int i = 0; i < len; i++)
    {
        printf("%d\t", nums[i]);
    }
    printf("\n");

    puts("input target");
    scanf("%d", &target);

    int pos = searchInsert(nums, len, target);

    printf("target pos = %d\n", pos);

}
