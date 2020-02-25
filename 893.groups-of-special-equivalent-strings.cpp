/*
 * @lc app=leetcode id=893 lang=cpp
 *
 * [893] Groups of Special-Equivalent Strings
 */

// @lc code=start
class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &A)
    {
        set<vector<char>> record;
        for (string s : A)
        {
            vector<char> c(52, 0);
            for (int i = 0; i < s.size(); i += 2)
            {
                c[s[i] - 'a']++;
            }
            for (int i = 1; i < s.size(); i += 2)
            {
                c[26 + s[i] - 'a']++;
            }
            record.insert(c);
        }
        return record.size();
    }
};
// @lc code=end
