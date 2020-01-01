/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start
class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int S, int T)
    {
        if (S == T)
        {
            return 0;
        }
        int routetotal = routes.size();
        int taken[500];
        set<int> visited;
        set<int> stops;
        set<int> transfer;
        vector<set<int>> sorted;
        for (int i = 0; i < routetotal; i++)
        {
            taken[i] = false;
            sorted.insert(sorted.begin(), set<int>(routes[i].begin(), routes[i].end()));
            for (int stop : routes[i])
            {
                if (stops.find(stop) == stops.end())
                {
                    stops.insert(stop);
                }
                else
                {
                    transfer.insert(stop);
                }
            }
        }
        int count = 0;
        set<int> current;
        set<int> next = {S};
        while (!next.empty())
        {
            count++;
            current.clear();
            current.insert(next.begin(), next.end());
            next.clear();
            for (int location : current)
            {
                if (visited.find(location) == visited.end())
                {
                    visited.insert(location);
                    for (int i = 0; i < routetotal; i++)
                    {
                        if (!taken[i])
                        {
                            set<int> selectedroute(routes[i].begin(), routes[i].end());
                            if (selectedroute.find(location) != selectedroute.end())
                            {
                                taken[i] = true;
                                for (int stop : selectedroute)
                                {
                                    if (stop == T)
                                    {
                                        return count;
                                    }
                                    if (transfer.find(stop) != transfer.end())
                                    {
                                        next.insert(stop);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
