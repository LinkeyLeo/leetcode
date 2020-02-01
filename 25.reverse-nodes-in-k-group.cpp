/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k < 2 || head == NULL)
        {
            return head;
        }
        ListNode *cnt;
        ListNode *prv;
        ListNode *nxt;
        ListNode *joint = new ListNode(0);
        joint->next = head;
        head = joint;
        int i = 1;
        do
        {
            cnt = joint->next;
            prv = joint->next;
            nxt = joint->next;
            while (i++ < k)
            {
                if (nxt->next == NULL)
                {
                    return head->next;
                }
                nxt = nxt->next;
            }
            joint->next = nxt;
            joint = prv;
            cnt = prv->next;
            while (--i > 1)
            {
                nxt = cnt->next;
                cnt->next = prv;
                prv = cnt;
                cnt = nxt;
            }
            joint->next = nxt;
        } while (cnt != NULL);
        return head->next;
    }
};
// @lc code=end
