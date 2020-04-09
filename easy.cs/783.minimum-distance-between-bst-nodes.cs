/*
 * @lc app=leetcode id=783 lang=csharp
 *
 * [783] Minimum Distance Between BST Nodes
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution
{
    private int p = int.MaxValue;
    public int MinDiffInBST(TreeNode root)
    {
        int min = int.MaxValue;
        if (root.left != null)
        {
            min = Math.Min(min, MinDiffInBST(root.left));
        }
        min = Math.Min(min, Math.Abs(root.val - p));
        p = root.val;
        if (root.right != null)
        {
            min = Math.Min(min, MinDiffInBST(root.right));
        }
        return min;
    }
}
// @lc code=end

