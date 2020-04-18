/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int width = height.size();
        vector<int> highestL(width, 0);
        vector<int> highestR(width, 0);
        map<int, vector<int>> priority;
        int h = 0;
        for (int i = 0; i < width; i++)
        {
            if (height[i] >= h)
            {
                h = height[i];
            }
            else
            {
                highestL[i] = h;
            }
            if (priority.find(height[i]) == priority.end())
            {
                priority[height[i]] = {i};
            }
            else
            {
                priority[height[i]].push_back(i);
            }
        }
        h = 0;
        for (int i = width - 1; i >= 0; i--)
        {
            if (height[i] >= h)
            {
                h = height[i];
            }
            else
            {
                highestR[i] = h;
            }
        }
        int capacity = 0;
        while (priority.size() > 1)
        {
            map<int, vector<int>>::iterator it = priority.begin();
            vector<int> lowest = it->second;
            int currentHeight = it->first;
            int nextHeight = (++it)->first;
            for (int i : lowest)
            {
                if (highestL[i] >= nextHeight && highestR[i] >= nextHeight)
                {
                    capacity += (highestL[i] < highestR[i] ? highestL[i] : highestR[i]) - currentHeight;
                    priority[highestL[i] < highestR[i] ? highestL[i] : highestR[i]].push_back(i);
                }
            }
            priority.erase(priority.begin());
        }
        return capacity;
    }
};
// @lc code=end
