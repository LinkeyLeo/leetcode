/*
 * @lc app=leetcode id=322 lang=csharp
 *
 * [322] Coin Change
 */

// @lc code=start
public class Solution
{
    public int CoinChange(int[] coins, int amount)
    {
        List<int> cache = new List<int>(new int[] { 0 });
        for (int i = 1; i <= amount; i++)
        {
            int v = Int32.MaxValue;
            bool possible = false;
            foreach (int coin in coins)
            {
                if (i - coin >= 0 && cache[i - coin] >= 0)
                {
                    v = Math.Min(v, cache[i - coin]);
                    possible = true;
                }
            }
            if (possible)
            {
                cache.Add(v + 1);
            }
            else
            {
                cache.Add(-1);
            }
        }
        return cache[amount];
    }
}
// @lc code=end

