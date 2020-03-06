/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int D)
    {
        if (weights.size() == 0)
        {
            return 1;
        }
        int capacity = max(accumulate(weights.begin(), weights.end(), D - 1) / D, *max_element(weights.begin(), weights.end()));
        vector<pair<int, int>> allocation;
        int load = 0;
        int step = INT_MAX;
        for (int i = 0; i < weights.size(); i++)
        {
            if (weights[i] + load > capacity)
            {
                allocation.push_back({load, i});
                step = min(weights[i] + load - capacity, step);
                load = 0;
            }
            load += weights[i];
        }
        allocation.push_back({load, weights.size()});
        while (allocation.size() > D)
        {
            capacity += step;
            step = INT_MAX;
            int shipped = 0;
            int ship = 0;
            int unload = 0;
            while (ship < allocation.size())
            {
                if (shipped < weights.size())
                {
                    allocation[ship].first -= unload;
                    unload = allocation[ship].first;
                    while (allocation[ship].second < weights.size() && allocation[ship].first + weights[allocation[ship].second] <= capacity)
                    {
                        allocation[ship].first += weights[allocation[ship].second];
                        allocation[ship].second++;
                    }
                    unload = allocation[ship].first - unload;
                    if (allocation[ship].second < weights.size() && allocation[ship].first + weights[allocation[ship].second] > capacity)
                    {
                        step = min(allocation[ship].first + weights[allocation[ship].second] - capacity, step);
                    }
                    shipped = allocation[ship].second;
                    ship++;
                }
                else
                {
                    allocation.pop_back();
                }
            }
        }
        return capacity;
    }
};
// @lc code=end
