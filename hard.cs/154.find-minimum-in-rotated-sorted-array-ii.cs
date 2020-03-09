/*
 * @lc app=leetcode id=154 lang=csharp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
public class Solution
{
    public int FindMin(int[] nums)
    {
        int b = 0;
        int u = nums.Length - 1;
        int m = (b + u) / 2;
        while (u > b)
        {
            if (nums[u] > nums[b])
            {
                return nums[b];
            }
            if (nums[b] == nums[m])
            {
                b++;
            }
            else if (nums[u] == nums[m])
            {
                u--;
            }
            else if (nums[b] > nums[m])
            {
                u = m;
            }
            else if (nums[u] < nums[m])
            {
                b = m;
            }
            m = (b + u) / 2;
        }
        return nums[m];
    }
}
// @lc code=end

