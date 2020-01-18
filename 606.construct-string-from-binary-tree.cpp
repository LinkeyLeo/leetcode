/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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
    string tree2str(TreeNode *t)
    {
        if (t == NULL)
        {
            return "";
        }
        string result = to_string(t->val);
        if (t->left != NULL || t->right != NULL)
        {
            if (t->left == NULL)
            {
                result += "()(";
                result += tree2str(t->right);
            }
            else
            {
                result += "(";
                result += tree2str(t->left);
                if (t->right != NULL)
                {
                    result += ")(";
                    result += tree2str(t->right);
                }
            }
            result += ")";
        }
        return result;
    }
};
// @lc code=end
