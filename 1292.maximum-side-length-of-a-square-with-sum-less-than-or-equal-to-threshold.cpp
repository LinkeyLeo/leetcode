/*
 * @lc app=leetcode id=1292 lang=cpp
 *
 * [1292] Maximum Side Length of a Square with Sum Less than or Equal to Threshold
 */

// @lc code=start
class Solution
{
public:
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {
        int height = mat.size();
        int width = mat[0].size();
        int maxlength = width > height ? height : width;
        int find = false;
        int square[300][300];
        for (int x = 0; x < height; x++)
        {
            for (int y = 0; y < width; y++)
            {
                square[x][y] = 0;
            }
        }
        for (int length = 0; length < maxlength; length++)
        {
            find = false;
            for (int x = 0; x < height - length; x++)
            {
                for (int y = 0; y < width - length; y++)
                {
                    if (square[x][y] != -1)
                    {
                        square[x][y] += mat[x + length][y + length];
                        for (int i = 0; i < length; i++)
                        {
                            square[x][y] += mat[x + length][y + i];
                            square[x][y] += mat[x + i][y + length];
                        }
                        if (square[x][y] > threshold)
                        {
                            square[x][y] = -1;
                        }
                        else
                        {
                            find = true;
                        }
                    }
                }
            }
            if (!find)
            {
                return length;
            }
        }
        return maxlength;
    }
};
// @lc code=end
