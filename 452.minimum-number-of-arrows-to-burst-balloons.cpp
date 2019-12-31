/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if(points.empty())
        {
            return 0;
        }
        int shots = 0;
        int earliest = INT_MAX;
        bool needshot = false;
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) -> bool { return a[0] > b[0]; });
        vector<int> target = points.back();
        for (int x = target[0]; !points.empty(); x = target[0])
        {
            if (x > earliest)
            {
                shots++;
                needshot = false;
                earliest = INT_MAX;
            }
            while (target[0] == x)
            {
                points.pop_back();
                if (target[1] < earliest)
                {
                    earliest = target[1];
                }
                needshot = true;
                if (points.empty())
                {
                    break;
                }
                else
                {
                    target = points.back();
                }
            }
            if (x == earliest)
            {
                shots++;
                needshot = false;
                earliest = INT_MAX;
            }
        }
        if (needshot)
        {
            shots++;
        }
        return shots;
    }
};
// @lc code=end
