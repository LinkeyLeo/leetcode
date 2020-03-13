/*
 * @lc app=leetcode id=813 lang=csharp
 *
 * [813] Largest Sum of Averages
 */

// @lc code=start
public class Solution
{
    Dictionary<int, double> cache = new Dictionary<int, double>();
    int[] data;
    public double LargestSumOfAverages(int K, int i)
    {
        double partial = 0;
        double count = 0;
        if (K == 1)
        {
            if (i + K <= data.Length)
            {
                count = data.Length - i;
                while (i < data.Length)
                {
                    partial += data[i++];
                }
                return partial / count;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            double max = 0;
            for (; i < data.Length; i++)
            {
                partial += data[i];
                count++;
                if (!cache.ContainsKey((K << 7) + i))
                {
                    cache[(K << 7) + i] = LargestSumOfAverages(K - 1, i + 1);
                }
                max = Math.Max(max, partial / count + cache[(K << 7) + i]);
            }
            return max;
        }
    }
    public double LargestSumOfAverages(int[] A, int K)
    {
        data = A;
        return LargestSumOfAverages(K, 0);
    }
}
// @lc code=end

