/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() % 2 == 2 && nums[0] == nums[nums.size() / 2 - 1])
        {
            return nums[0];
        }
        return nums[nums.size() / 2];
    }
};
// @lc code=end
