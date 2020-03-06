/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 */

// @lc code=start
class Solution
{
public:
    int integerReplacement(int n)
    {
        if (n == INT_MAX)
        {
            return 32;
        }
        int i = 0;
        while (n > 3)
        {
            switch (n % 4)
            {
            case 1:
                n--;
                break;
            case 3:
                n++;
                break;
            default:
                n >>= 1;
                break;
            }
            i++;
        }
        switch (n)
        {
        case 3:
            i++;
        case 2:
            i++;
        }
        return i;
    }
};
// @lc code=end
