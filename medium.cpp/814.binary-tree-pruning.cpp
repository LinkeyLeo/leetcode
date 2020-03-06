/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
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
    TreeNode *pruneTree(TreeNode *root)
    {
        if (root != NULL)
        {
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);
            if (root->left == root->right && root->val == 0)
            {
                return NULL;
            }
        }
        return root;
    }
};
// @lc code=end
