/*
 * @lc app=leetcode id=788 lang=cpp
 *
 * [788] Rotated Digits
 */

// @lc code=start
class Solution
{
public:
    int rotatedDigits(int N)
    {
        N++;
        int X = 0;
        int h;
        int i = 4;
        int base;
        int baseun;
        bool unchange = true;
        while (i-- > 0)
        {
            h = N / pow(10, i);
            base = pow(7, i);
            baseun = unchange ? pow(3, i) : 0;
            switch (h)
            {
            case 10:
                X += base - baseun;
            case 9:
                X += base - baseun;
            case 8:
            case 7:
                X += base;
            case 6:
                X += base;
            case 5:
            case 4:
            case 3:
                X += base;
            case 2:
                X += base - baseun;
            case 1:
                X += base - baseun;
            }
            switch (h)
            {
            case 3:
            case 4:
            case 7:
                return X;
            case 2:
            case 5:
            case 6:
            case 9:
                unchange = false;
            }
            N %= (int)pow(10, i);
        }
        return X;
    }
};
// @lc code=end
