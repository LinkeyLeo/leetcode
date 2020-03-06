/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

// @lc code=start
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int p = nums[0];
        int modified = false;
        for (int i = 1; i < nums.size(); i++)
        {
            if (p > nums[i])
            {
                if (modified)
                {
                    return false;
                }
                if (i > 1 && nums[i] >= nums[i - 2] || i == 1)
                {
                    p = p < nums[i] ? p : nums[i];
                }
                modified = true;
            }
            else
            {
                p = nums[i];
            }
        }
        return true;
    }
};
// @lc code=end
