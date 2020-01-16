/*
 * @lc app=leetcode id=1103 lang=cpp
 *
 * [1103] Distribute Candies to People
 */

// @lc code=start
class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        int steps = sqrt(2 * candies) - 0.5;
        int remain = candies - (steps * steps + steps) / 2;
        int batches = steps / num_people + 1;
        steps %= num_people;
        int next = batches * (batches - 1) * num_people / 2;
        int i = 0;
        vector<int> distribution;
        while (i < steps)
        {
            next += batches;
            distribution.push_back(next);
            i++;
        }
        batches--;
        next -= batches * (num_people - 1);
        next -= i;
        i++;
        distribution.push_back(next + remain);
        while (i < num_people)
        {
            next += batches;
            distribution.push_back(next);
            i++;
        }
        return distribution;
    }
};
// @lc code=end
