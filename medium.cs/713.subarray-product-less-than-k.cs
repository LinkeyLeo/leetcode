/*
 * @lc app=leetcode id=713 lang=csharp
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
public class Solution
{
    public int NumSubarrayProductLessThanK(int[] nums, int k)
    {
        int m = 1;
        int count = 0;
        int i = 0, j = 0;
        for (; j < nums.Length; j++)
        {
            m *= nums[j];
            while (m >= k && i <= j)
            {
                count += j - i;
                m /= nums[i++];
            }
        }
        return (int)(count + 1L * (j - i) * (j - i + 1) / 2);
    }
}
// @lc code=end

