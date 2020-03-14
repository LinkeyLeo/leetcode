/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int b = 0;
        int h = nums.size() - 1;
        int i;
        while (h > b)
        {
            if(nums[b]<nums[h])
            {
                return nums[b];
            }
            i = (b + h) / 2;
            if (nums[i] == nums[b])
            {
                b++;
            }
            else if (nums[i] == nums[h])
            {
                h--;
            }
            else if (nums[i] > nums[b])
            {
                b = i;
            }
            else
            {
                h = i;
            }
        }
        return nums[(b + h) / 2];
    }
};
// @lc code=end
