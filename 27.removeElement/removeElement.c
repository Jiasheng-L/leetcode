
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    int i=0;
    int temp;
    while (i < numsSize)
    {
        if(*(nums+i) == val)
        {
            if (*(nums+numsSize-1) != val)
            {
                temp = *(nums + i);
                *(nums + i) = *(nums + numsSize - 1);
                *(nums + numsSize - 1) = temp;
                i++;
            }
            numsSize--;
        }
        else
        {
            i++;
        }
    }
    return i;
}

int main()
{
    int num[100] = {0};
    int len = 0;
    int val = 0;
    puts("input int array len:");
    scanf("%d", &len);
    puts("input a int array:");
    for (int i = 0; i < len;i++)
    {
        scanf("%d", num + i);
    }
    puts("original array:");
    for (int i = 0; i < len;i++)
    {
        printf("%4d\t", num[i]);
    }
    puts("\n");
    puts("input the wanted value:");
    scanf("%d", &val);

    int len_ = removeElement(num, len, val);
    printf("output len_=%d\n", len_);
    puts("output array:");
    for (int i = 0; i < len;i++)
    {
        printf("%4d\t", num[i]);
    }
}
