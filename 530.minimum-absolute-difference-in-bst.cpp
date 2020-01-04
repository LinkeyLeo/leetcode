/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    int getMinimumDifference(TreeNode *root)
    {
        stack<TreeNode *> back;
        vector<int> val;
        int minimum = INT_MAX;
        int previous = root->val - INT_MAX;
        TreeNode *p = root;
        while (p != NULL)
        {
            if (p->left != NULL)
            {
                back.push(p->right);
                val.push_back(p->val);
                p = p->left;
            }
            else
            {
                if (p->val - previous < minimum)
                {
                    minimum = p->val - previous;
                }
                previous = p->val;
                if (p->right != NULL)
                {
                    p = p->right;
                }
                else
                {
                    if (!back.empty())
                    {
                        do
                        {
                            p = back.top();
                            back.pop();
                            if (val.back() - previous < minimum)
                            {
                                minimum = val.back() - previous;
                            }
                            previous = val.back();
                            val.pop_back();
                        } while (!back.empty() && p == NULL);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return minimum;
    }
};
// @lc code=end
