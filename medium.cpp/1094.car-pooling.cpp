/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        sort(trips.begin(), trips.end(), [](vector<int> a, vector<int> b) { return a[1] < b[1]; });
        map<int, int> arrive;
        int off = trips[0][2];
        for (vector<int> t : trips)
        {
            while (off <= t[1])
            {
                if (capacity < 0)
                {
                    return false;
                }
                capacity += arrive[off];
                arrive.erase(off);
                off = arrive.begin()->second;
            }
            arrive[t[2]] += t[0];
            capacity -= t[0];
            off = min(t[2], off);
        }
        return capacity >= 0;
    }
};
// @lc code=end
