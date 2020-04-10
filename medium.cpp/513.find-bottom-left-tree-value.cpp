/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
private:
    int bottom = 0;
    int value;
    void findBottomLeftValue(TreeNode *root, int depth)
    {
        if (root->left == root->right && depth > bottom)
        {
            bottom = depth;
            value = root->val;
        }
        if (root->left != NULL)
        {
            findBottomLeftValue(root->left, depth + 1);
        }
        if (root->right != NULL)
        {
            findBottomLeftValue(root->right, depth + 1);
        }
    }

public:
    int findBottomLeftValue(TreeNode *root)
    {
        findBottomLeftValue(root, 1);
        return value;
    }
};
// @lc code=end
