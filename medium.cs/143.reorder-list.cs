/*
 * @lc app=leetcode id=143 lang=csharp
 *
 * [143] Reorder List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution
{
    public void ReorderList(ListNode head)
    {
        List<ListNode> nodes = new List<ListNode>();
        ListNode p = head;
        while (p != null)
        {
            nodes.Add(p);
            p = p.next;
        }
        p = new ListNode(0);
        for (int i = 0; i * 2 < nodes.Count; i++)
        {
            p.next = nodes[i];
            p = p.next;
            if (nodes.Count - i > 1)
            {
                p.next = nodes[nodes.Count - 1 - i];
                p = p.next;
            }
        }
        p.next = null;
    }
}
// @lc code=end

