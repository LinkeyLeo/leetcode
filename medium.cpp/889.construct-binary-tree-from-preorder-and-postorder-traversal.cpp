/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
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
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {
        TreeNode *root;
        switch (pre.size())
        {
        case 0:
            break;
        case 1:
            root = new TreeNode(pre[0]);
            break;
        case 2:
            root = new TreeNode(pre[0]);
            root->left = new TreeNode(pre[1]);
            break;
        default:
            root = new TreeNode(pre[0]);
            vector<int> subpre;
            vector<int> subpost;
            int k = 0;
            while (post[k] != pre[1])
            {
                k++;
            }
            subpre.insert(subpre.begin(), pre.begin() + 1, pre.begin() + k + 2);
            subpost.insert(subpost.begin(), post.begin(), post.begin() + k + 1);
            root->left = constructFromPrePost(subpre, subpost);
            if (k < post.size() - 2)
            {
                subpre.clear();
                subpre.insert(subpre.begin(), pre.begin() + k + 2, pre.end());
                subpost.clear();
                subpost.insert(subpost.begin(), post.begin() + k + 1, post.end() - 1);
                root->right = constructFromPrePost(subpre, subpost);
            }
            break;
        }
        return root;
    }
};
// @lc code=end
