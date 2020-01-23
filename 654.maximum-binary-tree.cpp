/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        int s;
        int e;
        TreeNode *root;
        TreeNode **node;
        stack<int> start({0});
        stack<int> end({nums.size()});
        stack<TreeNode **> nodes({&root});
        while (!nodes.empty())
        {
            s = start.top();
            e = end.top();
            node = nodes.top();
            start.pop();
            end.pop();
            nodes.pop();
            int max = INT_MIN;
            int idx = INT_MIN;
            for (int i = s; i < e; i++)
            {
                if (nums[i] > max)
                {
                    max = nums[i];
                    idx = i;
                }
            }
            if (idx > INT_MIN)
            {
                *node = new TreeNode(max);
                start.push(idx + 1);
                end.push(e);
                nodes.push(&((*node)->right));
                start.push(s);
                end.push(idx);
                nodes.push(&((*node)->left));
            }
        }
        return root;
    }
};
// @lc code=end
