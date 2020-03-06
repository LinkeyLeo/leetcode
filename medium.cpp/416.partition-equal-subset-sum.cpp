/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        bitset<10000> memory;
        int sum = 0;
        for (int v : nums)
        {
            sum += v;
            memory = memory << v | memory;
            memory.set(v);
        }
        if (sum % 2 == 0)
        {
            return memory[sum / 2];
        }
        return false;
    }
};
// @lc code=end
