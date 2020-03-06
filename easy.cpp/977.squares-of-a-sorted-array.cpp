/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> s;
        for (int v : A)
        {
            s.push_back(v * v);
        }
        sort(s.begin(), s.end());
        return s;
    }
};
// @lc code=end
