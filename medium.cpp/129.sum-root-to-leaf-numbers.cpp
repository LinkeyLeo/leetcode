/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sum;
    void sumNumbers(TreeNode *root, int sum)
    {
        if (root->left == root->right)
        {
            this->sum += 10 * sum + root->val;
        }
        else
        {
            if (root->left != NULL)
            {
                sumNumbers(root->left, 10 * sum + root->val);
            }
            if (root->right != NULL)
            {
                sumNumbers(root->right, 10 * sum + root->val);
            }
        }
    }

public:
    int sumNumbers(TreeNode *root)
    {
        this->sum = 0;
        if (root != NULL)
        {
            sumNumbers(root, 0);
        }
        return this->sum;
    }
};
// @lc code=end
