/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        if (num <= 0)
        {
            return false;
        }
        while (num > 1)
        {
            if (num % 4 != 0)
            {
                return false;
            }
            num >>= 2;
        }
        return true;
    }
};
// @lc code=end
