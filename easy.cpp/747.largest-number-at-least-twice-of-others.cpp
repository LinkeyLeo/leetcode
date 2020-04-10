/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int maxi = nums.size() - 1;
        int nexti;
        if (nums.size() >= 2)
        {
            if (nums[0] > nums[1])
            {
                maxi = 0;
                nexti = 1;
            }
            else
            {
                maxi = 1;
                nexti = 0;
            }
            for (int i = 2; i < nums.size(); i++)
            {
                if (nums[i] >= nums[maxi])
                {
                    nexti = maxi;
                    maxi = i;
                }
                else if (nums[i] > nums[nexti])
                {
                    nexti = i;
                }
            }
            maxi = nums[maxi] >> 1 >= nums[nexti] ? maxi : -1;
        }
        return maxi;
    }
};
// @lc code=end
