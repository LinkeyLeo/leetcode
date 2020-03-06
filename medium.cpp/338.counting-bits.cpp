/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> bits({0});
        while (num >= bits.size())
        {
            for (int i = 0, end = bits.size(); i < end && i + end <= num; i++)
            {
                bits.push_back(bits[i] + 1);
            }
        }
        return bits;
    }
};
// @lc code=end
