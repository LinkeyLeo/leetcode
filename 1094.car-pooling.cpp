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
        map<short, pair<short, int>> info({{1000, {0, 0}}});
        int required = 0;
        for (vector<int> p : trips)
        {
            while (p[2] > p[1])
            {
                if (info.find(p[2]) == info.end())
                {
                    info[p[2]] = info.upper_bound(p[2])->second;
                    info.upper_bound(p[2])->second.first = p[2];
                }
                else
                {
                    if (info[p[2]].first < p[1])
                    {
                        info[p[1]] = info[p[2]];
                        info[p[2]].first = p[1];
                    }
                    info[p[2]].second += p[0];
                    required = max(info[p[2]].second, required);
                    p[2] = info[p[2]].first;
                }
            }
        }
        return required <= capacity;
    }
};
// @lc code=end
