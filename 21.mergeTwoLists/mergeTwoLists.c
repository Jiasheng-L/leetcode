
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * leetcode error:
 * member access within misaligned address 0x000000000031 for type 'struct ListNode', which requires 8 byte alignment
 * 
 * when mallocing (struct ListNode), it also malloc struct ListNode *next which is not pointed to anywhere.
 * to fix this, need to give a value to next, for example node->next=NULL;
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *node, *cur;
    struct ListNode *head = NULL;

    while(l1 != NULL || l2 != NULL)
    {
        node = (struct List *)malloc(sizeof(struct ListNode));
        if (l1 != NULL && l2 != NULL)
        {
            if (l1->val > l2->val)
            {
                node->val = l2->val;
                l2 = l2->next;
            }
            else
            {
                node->val = l1->val;
                l1 = l1->next;
            }
        }
        else if (l1 == NULL && l2 != NULL)
        {
            node->val = l2->val;
            l2 = l2->next;
        }
        else if (l1 != NULL && l2 == NULL)
        {
            node->val = l1->val;
            l1 = l1->next;
        }

        if (head == NULL)
        {
            head = node;
            cur = node;
        }
        else
        {
            cur->next = node;
            cur = cur->next;
        }
    }

    return head;
}


int main()
{
    struct ListNode *head[2] = {NULL, NULL};
    struct ListNode *l = NULL;
    struct ListNode *cur = NULL;

    puts("input first link");
    int i = 0;
    for (; i < 2;i++)
    {
        while (1)
        {
            l = (struct ListNode *)malloc(sizeof(struct ListNode));
            scanf("%d", &(l->val));
            l->next = NULL;
            if (l->val == 200)
            {
                free(l);
                break;
            }
            if (head[i] == NULL)
            {
                head[i] = l;
                cur = l;
            }
            else
            {
                cur->next = l;
                cur = cur->next;
            }
        }
    }
    cur = mergeTwoLists(head[0], head[1]);
    while(cur!=NULL)
    {
        printf("%d,", cur->val);
        cur = cur->next;
    }
}
