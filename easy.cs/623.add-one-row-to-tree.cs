/*
 * @lc app=leetcode id=623 lang=csharp
 *
 * [623] Add One Row to Tree
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
    public TreeNode AddOneRow(TreeNode root, int v, int d)
    {
        if (d == 1)
        {
            TreeNode nroot = new TreeNode(v);
            nroot.left = root;
            return root = nroot;
        }
        else if (root != null)
        {
            if (d == 2)
            {
                TreeNode lroot = new TreeNode(v);
                lroot.left = root.left;
                root.left = lroot;
                TreeNode rroot = new TreeNode(v);
                rroot.right = root.right;
                root.right = rroot;
            }
            else
            {
                root.left = AddOneRow(root.left, v, d - 1);
                root.right = AddOneRow(root.right, v, d - 1);
            }
        }
        return root;
    }
}
// @lc code=end

