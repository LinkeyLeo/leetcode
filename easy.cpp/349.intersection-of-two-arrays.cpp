/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> occur(nums1.begin(), nums1.end());
        set<int> inter;
        for (int v : nums2)
        {
            if (occur.find(v) != occur.end())
            {
                inter.insert(v);
            }
        }
        return vector<int>(inter.begin(), inter.end());
    }
};
// @lc code=end
