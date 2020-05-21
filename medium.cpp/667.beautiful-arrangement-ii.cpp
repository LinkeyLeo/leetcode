/*
 * @lc app=leetcode id=667 lang=cpp
 *
 * [667] Beautiful Arrangement II
 */

// @lc code=start
class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> a{(k >> 1) + 1};
        a.reserve(n);
        int rest = k;
        int l = a[0] - 1;
        int r = a[0];
        if (k % 2 == 1)
        {
            a.push_back(++r);
        }
        while (l > 0)
        {
            a.push_back(l--);
            a.push_back(++r);
        }
        while (r < n)
        {
            a.push_back(++r);
        }
        return a;
    }
};
// @lc code=end
