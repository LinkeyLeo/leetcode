/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

// @lc code=start
class Solution
{
private:
    map<int, queue<int>> store;

public:
    Solution(vector<int> &nums)
    {
        int total = nums.size();
        for (int i = 0; i < total; i++)
        {
            int value = nums[i];
            if (store.find(value) == store.end())
            {
                store.insert({value, queue<int>({i})});
            }
            else
            {
                store[value].push(i);
            }
        }
    }

    int pick(int target)
    {
        int index = store[target].front();
        store[target].pop();
        store[target].push(index);
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end
