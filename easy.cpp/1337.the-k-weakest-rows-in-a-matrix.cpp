/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> weight;
        for (int i = 0; i < mat.size(); i++)
        {
            int sum = 0;
            for (int v : mat[i])
            {
                sum += v;
            }
            weight.push_back({sum, i});
        }
        sort(weight.begin(), weight.end());
        vector<int> weakest;
        for (int i = 0; i < k; i++)
        {
            weakest.push_back(weight[i].second);
        }
        return weakest;
    }
};
// @lc code=end
