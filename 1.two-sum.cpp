/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int total = nums.size();
        for (int i = 0; i < total; i++)
        {
            for (int j = i + 1; j < total; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return vector<int>({i, j});
                }
            }
        }
        return vector<int>(0);
    }
};
// @lc code=end
