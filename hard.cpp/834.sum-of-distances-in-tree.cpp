/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */

// @lc code=start
class Solution
{
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges)
    {
        map<int, set<int>> connect;
        for (vector<int> e : edges)
        {
            connect[e[0]].insert(e[1]);
            connect[e[1]].insert(e[0]);
        }
        vector<int> child(N, 1);
        vector<int> answer(N, 0);
        map<int, set<int>> ct = connect;
        while (ct.size() > 1)
        {
            vector<map<int, set<int>>::iterator> d;
            for (map<int, set<int>>::iterator it = ct.begin(); it != ct.end(); it++)
            {
                if (it->second.size() == 1 && it->first != 0)
                {
                    child[*(it->second.begin())] += child[it->first];
                    answer[*(it->second.begin())] += answer[it->first] + child[it->first];
                    ct[*(it->second.begin())].erase(it->first);
                    d.push_back(it);
                }
            }
            for (map<int, set<int>>::iterator it : d)
            {
                ct.erase(it);
            }
        }
        queue<int> next({0});
        set<int> visit;
        while (!next.empty())
        {
            visit.insert(next.front());
            for (int p : connect[next.front()])
            {
                if (visit.find(p) == visit.end())
                {
                    next.push(p);
                    answer[p] = answer[next.front()] + N - 2 * child[p];
                }
            }
            next.pop();
        }
        return answer;
    }
};
// @lc code=end
