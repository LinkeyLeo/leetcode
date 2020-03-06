/*
 * @lc app=leetcode id=322 lang=csharp
 *
 * [322] Coin Change
 */

// @lc code=start
public class Solution
{
    private Dictionary<int, Dictionary<int, int>> cache = new Dictionary<int, Dictionary<int, int>>();
    public int CoinChange(int[] coins, int amount)
    {
        Array.Sort(coins);
        return CoinChange(ref coins, coins.Length, amount);
    }
    private int CoinChange(ref int[] coins, int i, int amount)
    {
        int result = Int32.MaxValue;
        bool solved = false;
        while (--i >= 0)
        {
            int j = amount / coins[i];
            amount %= coins[i];
            if (amount == 0)
            {
                solved = true;
                result = j < result ? j : result;
            }
            while (j > result)
            {
                amount += coins[i];
                --j;
            }
            while (j > 0)
            {
                if (!cache.ContainsKey(i))
                {
                    cache[i] = new Dictionary<int, int>();
                }
                if (!cache[i].ContainsKey(amount))
                {
                    cache[i][amount] = CoinChange(ref coins, i, amount);
                }
                int v = cache[i][amount];
                if (v != -1)
                {
                    solved = true;
                    result = v + j < result ? v + j : result;
                }
                amount += coins[i];
                --j;
            }
        }
        return solved ? result : -1;
    }
}
// @lc code=end

