/*
 * @lc app=leetcode id=107 lang=csharp
 *
 * [107] Binary Tree Level Order Traversal II
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
    private int depth;
    private IList<IList<int>> data;
    private void LevelOrderBottom(TreeNode root, int level)
    {
        if (root == null)
        {
            return;
        }
        if (level > depth)
        {
            data.Insert(0, new List<int>());
            depth = level;
        }
        data[depth - level].Add(root.val);
        LevelOrderBottom(root.left, level + 1);
        LevelOrderBottom(root.right, level + 1);
    }
    public IList<IList<int>> LevelOrderBottom(TreeNode root)
    {
        depth = 0;
        data = new List<IList<int>>();
        LevelOrderBottom(root, 1);
        return data;
    }
}
// @lc code=end

