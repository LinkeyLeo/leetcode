/*
 * @lc app=leetcode id=830 lang=cpp
 *
 * [830] Positions of Large Groups
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string S)
    {
        char pch = '@';
        char ch;
        int s;
        vector<vector<int>> positions;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] != pch)
            {
                if (i - s >= 3)
                {
                    positions.push_back({s, i - 1});
                }
                s = i;
                pch = S[i];
            }
        }
        if (S.size() - s >= 3)
        {
            positions.push_back({s, S.size() - 1});
        }
        return positions;
    }
};
// @lc code=end
