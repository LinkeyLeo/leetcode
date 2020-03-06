/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> spiral(n, vector<int>(n, 0));
        int val = 1;
        int t = 0;
        int b = n;
        int l = 0;
        int r = n;
        while (val <= n * n)
        {
            for (int i = l; i < r && val <= n * n; i++, val++)
            {
                spiral[t][i] = val;
            }
            t++;
            r--;
            for (int i = t; i < b && val <= n * n; i++, val++)
            {
                spiral[i][r] = val;
            }
            b--;
            for (int i = r - 1; i >= l && val <= n * n; i--, val++)
            {
                spiral[b][i] = val;
            }
            for (int i = b - 1; i >= t && val <= n * n; i--, val++)
            {
                spiral[i][l] = val;
            }
            l++;
        }
        return spiral;
    }
};
// @lc code=end
