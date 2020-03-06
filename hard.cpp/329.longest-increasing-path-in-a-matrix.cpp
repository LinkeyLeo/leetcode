/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return 0;
        }
        vector<vector<int>> increase(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> decrease(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max = 1;
        int inc;
        int dec;
        bool changed;
        do
        {
            changed = false;
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    inc = increase[i][j];
                    dec = decrease[i][j];
                    if (j > 0)
                    {
                        if (matrix[i][j - 1] > matrix[i][j] && increase[i][j - 1] + 1 > increase[i][j])
                        {
                            increase[i][j] = increase[i][j - 1] + 1;
                        }
                        else if (matrix[i][j - 1] < matrix[i][j] && decrease[i][j - 1] + 1 > decrease[i][j])
                        {
                            decrease[i][j] = decrease[i][j - 1] + 1;
                        }
                    }
                    if (j < matrix[0].size() - 1)
                    {
                        if (matrix[i][j + 1] > matrix[i][j] && increase[i][j + 1] + 1 > increase[i][j])
                        {
                            increase[i][j] = increase[i][j + 1] + 1;
                        }
                        else if (matrix[i][j + 1] < matrix[i][j] && decrease[i][j + 1] + 1 > decrease[i][j])
                        {
                            decrease[i][j] = decrease[i][j + 1] + 1;
                        }
                    }
                    if (i > 0)
                    {
                        if (matrix[i - 1][j] > matrix[i][j] && increase[i - 1][j] + 1 > increase[i][j])
                        {
                            increase[i][j] = increase[i - 1][j] + 1;
                        }
                        else if (matrix[i - 1][j] < matrix[i][j] && decrease[i - 1][j] + 1 > decrease[i][j])
                        {
                            decrease[i][j] = decrease[i - 1][j] + 1;
                        }
                    }
                    if (i < matrix.size() - 1)
                    {
                        if (matrix[i + 1][j] > matrix[i][j] && increase[i + 1][j] + 1 > increase[i][j])
                        {
                            increase[i][j] = increase[i + 1][j] + 1;
                        }
                        else if (matrix[i + 1][j] < matrix[i][j] && decrease[i + 1][j] + 1 > decrease[i][j])
                        {
                            decrease[i][j] = decrease[i + 1][j] + 1;
                        }
                    }
                    changed |= inc != increase[i][j] || dec != decrease[i][j];
                    max = increase[i][j] + decrease[i][j] + 1 > max ? increase[i][j] + decrease[i][j] + 1 : max;
                }
            }
        } while (changed);
        return max;
    }
};
// @lc code=end
