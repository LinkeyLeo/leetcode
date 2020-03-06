/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 */

// @lc code=start
class Solution
{
public:
    bool canReorderDoubled(vector<int> &A)
    {
        map<int, short> count;
        for (int v : A)
        {
            count[v]++;
        }
        while (count.size() > 0)
        {
            int v = count.begin()->first;
            if (v > 0)
            {
                v <<= 1;
            }
            else if (v % 2 != 0)
            {
                return false;
            }
            else
            {
                v >>= 1;
            }
            if (count.begin()->second == 1)
            {
                count.erase(count.begin());
            }
            else
            {
                count.begin()->second--;
            }
            switch (count[v])
            {
            case 0:
                return false;
            case 1:
                count.erase(v);
                break;
            default:
                count[v]--;
                break;
            }
        }
        return true;
    }
};
// @lc code=end
