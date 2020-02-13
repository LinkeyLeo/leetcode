/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        nums.push_back(val);
        nums.push_back(val);
        int front = -1;
        int end = nums.size();
        while (end - front > 1)
        {
            while (end - front > 1 && nums[++front] != val)
                ;
            while (end - front > 1 && nums[--end] == val)
                ;
            if (nums[front] == val)
            {
                nums[front] ^= nums[end];
                nums[end] ^= nums[front];
                nums[front] ^= nums[end];
            }
        }
        if (nums[front] != val)
        {
            front++;
        }
        return front;
    }
};
// @lc code=end
