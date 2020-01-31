/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
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
    TreeNode *addOneRow(TreeNode *root, int v, int d)
    {
        TreeNode *nroot;
        switch (d)
        {
        case 1:
            nroot = new TreeNode(v);
            nroot->left = root;
            root = nroot;
            break;
        case 2:
            nroot = new TreeNode(v);
            nroot->left = root->left;
            root->left = nroot;
            nroot = new TreeNode(v);
            nroot->right = root->right;
            root->right = nroot;
            break;
        default:
            if (root->left != NULL)
            {
                addOneRow(root->left, v, d - 1);
            }
            if (root->right != NULL)
            {
                addOneRow(root->right, v, d - 1);
            }
            break;
        }
        return root;
    }
};
// @lc code=end
