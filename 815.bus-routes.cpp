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
        map<int, set<int>> reachable;
        int totalroutes = routes.size();
        int totalstations;
        int s0, s1;
        for (int i = 0; i < totalroutes; i++)
        {
            vector<int> stations = routes[i];
            totalstations = stations.size();
            for (int j = 0; j < totalstations; j++)
            {
                s0 = stations[j];
                for (int k = j + 1; k < totalstations; k++)
                {
                    s1 = stations[k];
                    if (reachable.find(s0) == reachable.end())
                    {
                        reachable.insert({s0, set<int>()});
                    }
                    if (reachable.find(s1) == reachable.end())
                    {
                        reachable.insert({s1, set<int>()});
                    }
                    reachable[s0].insert(s1);
                    reachable[s1].insert(s0);
                }
            }
        }
        set<int> direct;
        set<int> singlenext;
        set<int> next = {S};
        int transfer = 0;
        while (!next.empty())
        {
            direct.clear();
            direct.insert(next.begin(), next.end());
            next.clear();
            transfer++;
            for (int directstation : direct)
            {
                singlenext = reachable[directstation];
                reachable.erase(directstation);
                for (int nextstation : singlenext)
                {
                    if (nextstation == T)
                    {
                        return transfer;
                    }
                    if (direct.find(nextstation) == direct.end())
                    {
                        next.insert(nextstation);
                    }
                    reachable[nextstation].erase(directstation);
                }
            }
        }
        return -1;
    }
};
// @lc code=end
