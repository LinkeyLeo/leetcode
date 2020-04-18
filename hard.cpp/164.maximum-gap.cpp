/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return 0;
        }
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        for (int v : nums)
        {
            minimum = v < minimum ? v : minimum;
            maximum = v > maximum ? v : maximum;
        }
        int offset = minimum;
        int gap = (maximum - minimum) / (nums.size() - 1);
        gap = gap > 1 ? gap : 1;
        int buckets = (maximum - minimum) / gap + 1;
        vector<int> bucketMIN(buckets, INT_MAX);
        vector<int> bucketMAX(buckets, INT_MIN);
        for (int v : nums)
        {
            bucketMIN[(v - offset) / gap] = v < bucketMIN[(v - offset) / gap] ? v : bucketMIN[(v - offset) / gap];
            bucketMAX[(v - offset) / gap] = v > bucketMAX[(v - offset) / gap] ? v : bucketMAX[(v - offset) / gap];
        }
        int maxdiff = 0;
        for (int i = 0; i < buckets - 1; i++)
        {
            if (bucketMIN[i + 1] == INT_MAX || bucketMAX[i] == INT_MIN)
            {
                bucketMAX[i + 1] = bucketMAX[i];
            }
            else
            {
                maxdiff = bucketMIN[i + 1] - bucketMAX[i] > maxdiff ? bucketMIN[i + 1] - bucketMAX[i] : maxdiff;
            }
        }
        return maxdiff;
    }
};
// @lc code=end
