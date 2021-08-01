
#include <stdio.h>


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if (nums1Size < m+n)
    {
        return;
    }
    if (n == 0)
    {
        return;
    }
    if (m == 0)
    {
        for (int k = 0; k < n;k++)
        {
            nums1[k] = nums2[k];
        }
        return;
    }

    int i = m - 1, j = n - 1;
    int cur = n + m - 1;

    while(i>=0 || j>=0)
    {
        if (i>=0 && j>=0)
        {
            if (nums1[i]> nums2[j])
            {
                nums1[cur--] = nums1[i--];
            }
            else
            {
                nums1[cur--] = nums2[j--];
            }
        }
        else if(i>=0 && j < 0)
        {
            nums1[cur--] = nums1[i--];
        }
        else if(i<0 && j>= 0)
        {
            nums1[cur--] = nums2[j--];
        }
    }
}


int main()
{
    int nums1[6] = {4, 0, 0, 0, 0, 0};
    int nums2[5] = {1, 2, 3, 5, 6};
    merge(nums1, 6, 1, nums2, 5, 5);
    for (int i = 0; i < sizeof(nums1) / sizeof(nums1[0]); i++)
    {
        printf("%d\t", nums1[i]);
    }
}
