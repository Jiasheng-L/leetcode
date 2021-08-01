
#include <stdio.h>
#include <stdbool.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode * deleteDuplicates(struct ListNode *head)
{
    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    while (cur)
    {
        if (pre)
        {
            if (cur->val == pre->val)
            {
                pre->next = cur->next;
                free(cur);
                cur = pre->next;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
    return head;
}

int main()
{

}
