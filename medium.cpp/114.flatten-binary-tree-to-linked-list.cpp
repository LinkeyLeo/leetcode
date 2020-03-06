/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode *root)
    {
        stack<TreeNode *> next;
        TreeNode *p = root;
        while (p != NULL)
        {
            if (p->left == NULL)
            {
                while (p->right == NULL && !next.empty())
                {
                    p->right = next.top();
                    next.pop();
                }
                p = p->right;
            }
            else
            {
                next.push(p->right);
                p->right = p->left;
                p->left = NULL;
            }
        }
    }
};
// @lc code=end
