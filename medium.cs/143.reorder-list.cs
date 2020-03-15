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
        Queue<ListNode> q = new Queue<ListNode>();
        Stack<ListNode> s = new Stack<ListNode>();
        int count = 0;
        ListNode p = head;
        while (p != null)
        {
            count++;
            q.Enqueue(p);
            s.Push(p);
            p = p.next;
        }
        p = new ListNode(0);
        for (int i = 0; i < count; i += 2)
        {
            p.next = q.Dequeue();
            p = p.next;
            if (count - i > 1)
            {
                p.next = s.Pop();
                p = p.next;
            }
        }
        p.next = null;
    }
}
// @lc code=end

