/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        stack<TreeNode *> nodes({root});
        TreeNode *cnt;
        while (!nodes.empty())
        {
            cnt = nodes.top();
            nodes.pop();
            cnt->left = (TreeNode *)((ulong)cnt->right ^ (ulong)cnt->left);
            cnt->right = (TreeNode *)((ulong)cnt->left ^ (ulong)cnt->right);
            cnt->left = (TreeNode *)((ulong)cnt->right ^ (ulong)cnt->left);
            if (cnt->left != NULL)
            {
                nodes.push(cnt->left);
            }
            if (cnt->right != NULL)
            {
                nodes.push(cnt->right);
            }
        }
        return root;
    }
};
// @lc code=end
