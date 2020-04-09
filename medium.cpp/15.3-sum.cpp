/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        if (nums.size() >= 2)
        {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 2; i++)
            {
                if (i != 0 && nums[i] == nums[i - 1])
                {
                    continue;
                }
                int m = i + 1;
                int n = nums.size() - 1;
                while (m < n)
                {
                    if (nums[i] + nums[m] + nums[n] < 0)
                    {
                        while (m < n && nums[m] == nums[++m])
                            ;
                    }
                    else if (nums[i] + nums[m] + nums[n] > 0)
                    {
                        while (m < n && nums[n] == nums[--n])
                            ;
                    }
                    else
                    {
                        result.push_back({nums[i], nums[m], nums[n]});
                        while (m < n && nums[m] == nums[++m])
                            ;
                        while (m < n && nums[n] == nums[--n])
                            ;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
