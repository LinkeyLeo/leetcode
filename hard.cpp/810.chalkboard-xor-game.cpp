/*
 * @lc app=leetcode id=810 lang=cpp
 *
 * [810] Chalkboard XOR Game
 */

// @lc code=start
class Solution
{
public:
    bool xorGame(vector<int> &nums)
    {
        if (nums.size() % 2 == 0)
        {
            return true;
        }
        int x = 0;
        for (int v : nums)
        {
            x ^= v;
        }
        return x == 0;
    }
};
// @lc code=end
