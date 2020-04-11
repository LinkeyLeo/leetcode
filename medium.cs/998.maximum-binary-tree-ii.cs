/*
 * @lc app=leetcode id=998 lang=csharp
 *
 * [998] Maximum Binary Tree II
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
    public TreeNode InsertIntoMaxTree(TreeNode root, int val)
    {
        TreeNode virtualRoot = new TreeNode(0);
        TreeNode vrb = virtualRoot;
        vrb.right = root;
        while (vrb.right != null && val < vrb.right.val)
        {
            vrb = vrb.right;
        }
        TreeNode nNode = new TreeNode(val);
        nNode.left = vrb.right;
        vrb.right = nNode;
        return virtualRoot.right;
    }
}
// @lc code=end

