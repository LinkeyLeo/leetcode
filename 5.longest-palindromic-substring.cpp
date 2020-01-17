/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int total = s.size();
        int maxlnth = 0;
        int start = 0;
        for (int rdc = 0; rdc <= total - maxlnth; rdc++)
        {
            float cntr;
            int lnth;
            cntr = (total - rdc - 1) / 2.0;
            lnth = (total - rdc) % 2 == 0 ? 0 : -1;
            for (int i = cntr, j = total - rdc - cntr - 0.5; j - i < total - rdc && i >= 0 && j < total; i--, j++)
            {
                if (s[i] != s[j])
                {
                    if (maxlnth < lnth)
                    {
                        maxlnth = lnth;
                        start = i + 1;
                    }
                    break;
                }
                lnth += 2;
            }
            if (maxlnth < lnth)
            {
                maxlnth = lnth;
                start = 0;
                break;
            }
            if (rdc == 0)
            {
                continue;
            }
            cntr = (total + rdc - 1) / 2.0;
            lnth = (total - rdc) % 2 == 0 ? 0 : -1;
            for (int i = cntr, j = total + rdc - cntr - 0.5; j - i < total - rdc && i >= 0 && j < total; i--, j++)
            {
                if (s[i] != s[j])
                {
                    if (maxlnth < lnth)
                    {
                        maxlnth = lnth;
                        start = i + 1;
                    }
                    break;
                }
                lnth += 2;
            }
            if (maxlnth < lnth)
            {
                maxlnth = lnth;
                start = rdc;
                break;
            }
        }
        return s.substr(start, maxlnth);
    }
};
// @lc code=end
