/*
 * @lc app=leetcode id=668 lang=csharp
 *
 * [668] Kth Smallest Number in Multiplication Table
 */

// @lc code=start
public class Solution
{
    public int FindKthNumber(int m, int n, int k)
    {
        int bottom = 0;
        int cell = m * n;
        int t = cell + 1 >> 1;
        if (m > n)
        {
            m ^= n;
            n ^= m;
            m ^= n;
        }
        while (bottom + 1 < cell)
        {
            int c = 0;
            for (int i = 0; i < m; c += t / ++i < n ? t / i : n) ;
            if (c >= k)
            {
                cell = t;
                t += bottom + 1;
                t >>= 1;
            }
            else
            {
                bottom = t;
                t += cell + 1;
                t >>= 1;
            }
        }
        return bottom + 1;
    }
}
// @lc code=end

