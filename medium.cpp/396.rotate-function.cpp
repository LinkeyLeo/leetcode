/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */

// @lc code=start
class Solution
{
public:
    int maxRotateFunction(vector<int> &A)
    {
        long step = 0;
        for (int v : A)
        {
            step += v;
        }
        long sum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            sum += i * A[i];
        }
        long max = sum;
        for (int i = 0; i < A.size(); i++)
        {
            sum += step;
            sum -= A.size() * A[A.size() - 1 - i];
            max = sum > max ? sum : max;
        }
        return (int)max;
    }
};
// @lc code=end
