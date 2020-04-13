/*
 * @lc app=leetcode id=117 lang=csharp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
public class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
}
*/

public class Solution
{
    public Node Connect(Node root)
    {
        Node head = root;
        Node worker;
        Node placeholder = new Node(int.MaxValue);
        Node modifier;
        while (head != null)
        {
            while (head != null && head.left == head.right)
            {
                head = head.next;
            }
            worker = head;
            modifier = placeholder;
            while (worker != null)
            {
                if (worker.left != worker.right)
                {
                    if (worker.left != null)
                    {
                        modifier.next = worker.left;
                        modifier = modifier.next;
                    }
                    if (worker.right != null)
                    {
                        modifier.next = worker.right;
                        modifier = modifier.next;
                    }
                }
                worker = worker.next;
            }
            head = head != null ? head.left != null ? head.left : head.right : null;
        }
        return root;
    }
}
// @lc code=end

