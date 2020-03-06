/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode *root)
    {
        if (root != NULL)
        {
            TreeNode *f;
            TreeNode *s;
            stack<pair<TreeNode *, TreeNode *>> back;
            back.push({root->left, root->right});
            while (!back.empty())
            {
                f = back.top().first;
                s = back.top().second;
                back.pop();
                if (f != s)
                {
                    if (f == NULL || s == NULL || f->val != s->val)
                    {
                        return false;
                    }
                    back.push({f->left, s->right});
                    back.push({f->right, s->left});
                }
            }
        }
        return true;
    }
};
// @lc code=end
