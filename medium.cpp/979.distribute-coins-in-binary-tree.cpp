/*
 * @lc app=leetcode id=979 lang=cpp
 *
 * [979] Distribute Coins in Binary Tree
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
    int distributeCoins(TreeNode *root)
    {
        int coins = 0;
        int moves = 0;
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            if (root->left != NULL)
            {
                moves += distributeCoins(root->left);
                coins += root->left->val - 1;
                moves += abs(root->left->val - 1);
            }
            if (root->right != NULL)
            {
                moves += distributeCoins(root->right);
                coins += root->right->val - 1;
                moves += abs(root->right->val - 1);
            }
            root->val += coins;
        }
        return moves;
    }
};
// @lc code=end
