/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *half = head->next;
        ListNode *p = half->next;
        ListNode *connecter = head;
        ListNode *end = half;
        while (p != NULL)
        {
            connecter->next = p;
            connecter = p;
            p = connecter->next;
            if (p != NULL)
            {
                end->next = p;
                end = p;
                p = end->next;
            }
        }
        connecter->next = half;
        end->next = NULL;
        return head;
    }
};
// @lc code=end
