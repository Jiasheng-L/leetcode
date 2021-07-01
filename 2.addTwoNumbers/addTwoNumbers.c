/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *sum = NULL, *header= NULL;
    struct ListNode *p = NULL;
    unsigned char add = 0;

    while (l1 != NULL || l2 != NULL)
    {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next = NULL;
        if (l1 != NULL && l2 != NULL)
        {
            p->val = l1->val + l2->val + add;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1 !=NULL)
        {
            p->val = l1->val + add;
            l1 = l1->next;
        }
        else if (l2 !=NULL)
        {
            p->val = l2->val + add;
            l2 = l2->next;
        }
        if (p->val >= 10)
        {
            add = p->val / 10;
            p->val = p->val % 10;
        }
        else
        {
            add = 0;
        }
        if (sum == NULL)
        {
            sum = p;
            header = p;
        }
        else
        {
            sum->next = p;
            sum = sum->next;
        }
        p = NULL;
    }

    if(add)
    {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next = NULL;
        sum->next = p;
        sum = sum->next;
        p->val = add;
    }
    return header;
}

int main()
{

    struct ListNode *l1[2];
    struct ListNode *p = NULL, *now = NULL;
    char ch;

    for (int i = 0; i < 2; i++)
    {
        printf("input number[%d] backward:", i);
        l1[i] = NULL;
        while ((ch = getchar()))
        {
            printf("%c", ch);
            if (!(ch >='0' && ch <= '9'))
            {
                if (ch == 'a')
                {
                    break;
                }
                else
                {
                    continue;
                }
            }

            p = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->val = (int)(ch-'0');
            p->next = NULL;
            if (l1[i] == NULL)
            {
                l1[i] = p;
                now = p;
            }
            else
            {
                now->next = p;
                now = now->next;
            }
        }
        now = NULL;
        p = NULL;
    }

    p = addTwoNumbers(l1[0], l1[1]);
    while(p)
    {
        printf("%d", p->val);
        p = p->next;
    }

    return 0;
}