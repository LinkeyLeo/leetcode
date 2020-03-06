/*
 * @lc app=leetcode id=1111 lang=cpp
 *
 * [1111] Maximum Nesting Depth of Two Valid Parentheses Strings
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        vector<int> A(seq.size(), 0);
        for (int i = 1; i < seq.size(); i++)
        {
            A[i] = seq[i] == seq[i - 1] ? 1 - A[i - 1] : A[i - 1];
        }
        return A;
    }
};
// @lc code=end
