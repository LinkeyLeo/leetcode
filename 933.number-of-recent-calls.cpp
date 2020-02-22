/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */

// @lc code=start
class RecentCounter
{
private:
    queue<int> history;

public:
    RecentCounter() {}

    int ping(int t)
    {
        history.push(t);
        while (history.front() < t - 3000)
        {
            history.pop();
        }
        return history.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
