/*
 * @lc app=leetcode id=836 lang=csharp
 *
 * [836] Rectangle Overlap
 */

// @lc code=start
public class Solution
{
    public bool IsRectangleOverlap(int[] rec1, int[] rec2)
    {
        int outerW = Math.Max(rec1[2], rec2[2]) - Math.Min(rec1[0], rec2[0]);
        int outerH = Math.Max(rec1[3], rec2[3]) - Math.Min(rec1[1], rec2[1]);
        return 0L + rec2[2] - rec2[0] + rec1[2] - rec1[0] > outerW &&
                0L + rec2[3] - rec2[1] + rec1[3] - rec1[1] > outerH;
    }
}
// @lc code=end

