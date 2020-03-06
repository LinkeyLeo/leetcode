/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<int> tried;
        int length = s.size();
        queue<int> tocheck({length});
        int next;
        while (!tocheck.empty())
        {
            next = tocheck.front();
            tocheck.pop();
            for (string m : wordDict)
            {
                int mlength = m.size();
                if (next - mlength > 0)
                {
                    if (s.substr(next - mlength, mlength) == m && tried.find(next - mlength) == tried.end())
                    {
                        tried.insert(next-mlength);
                        tocheck.push(next - mlength);
                    }
                }
                else if (next - mlength == 0)
                {
                    if (s.substr(0, mlength) == m)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end
