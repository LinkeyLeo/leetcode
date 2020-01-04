/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        x ^= y;
        int d = 0;
        while (x != 0)
        {
            d++;
            x &= (x - 1);
        }
        return d;
    }
};
// @lc code=end
