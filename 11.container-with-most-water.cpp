/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max = 0;
        int v;
        int l = 0;
        for (int i = 0; i < height.size(); i++)
        {
            if (l < height[i])
            {
                l = height[i];
                for (int j = i + 1; j < height.size(); j++)
                {
                    v = l < height[j] ? l : height[j];
                    v *= j - i;
                    max = v > max ? v : max;
                }
            }
        }
        return max;
    }
};
// @lc code=end
