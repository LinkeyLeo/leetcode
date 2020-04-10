/*
 * @lc app=leetcode id=120 lang=csharp
 *
 * [120] Triangle
 */

// @lc code=start
public class Solution
{
    public int MinimumTotal(IList<IList<int>> triangle)
    {
        for (int i = triangle.Count - 1; i >= 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                triangle[i - 1][j] += Math.Min(triangle[i][j], triangle[i][j + 1]);
            }
        }
        return triangle.Count > 0 ? triangle[0][0] : 0;
    }
}
// @lc code=end

