/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
class Solution
{
public:
    int minDeletionSize(vector<string> &A)
    {
        if (A.size() == 0)
        {
            return 0;
        }
        set<int> keep;
        for (int i = 0; i < A[0].size(); i++)
        {
            keep.insert(i);
        }
        string prv;
        string cnt = A[0];
        for (int j = 1; j < A.size(); j++)
        {
            prv = cnt;
            cnt = A[j];
            for (int i : keep)
            {
                if (cnt[i] < prv[i])
                {
                    keep.erase(i);
                }
            }
        }
        return A[0].size() - keep.size();
    }
};
// @lc code=end
