/*
 * @lc app=leetcode id=828 lang=csharp
 *
 * [828] Count Unique Characters of All Substrings of a Given String
 */

// @lc code=start
public class Solution
{
    public int UniqueLetterString(string s)
    {
        int[] mask = new int[s.Length];
        int[] duplicate = new int[s.Length];
        int[] cache = new int[s.Length];
        int sum = s.Length;
        for (int i = 0; i < s.Length; i++)
        {
            mask[i] = 1 << s[i] - 'A';
            cache[i] = 1;
        }
        for (int i = 1; i < s.Length; i++)
        {
            for (int j = 0; j + i < s.Length; j++)
            {
                if ((1 << s[j + i] - 'A' | mask[j]) != mask[j])
                {
                    mask[j] |= 1 << s[j + i] - 'A';
                    cache[j]++;
                }
                else if ((1 << s[j + i] - 'A' | duplicate[j]) != duplicate[j])
                {
                    duplicate[j] |= 1 << s[j + i] - 'A';
                    cache[j]--;
                }
                cache[j] %= 1000000007;
                sum += cache[j];
                sum %= 1000000007;
            }
        }
        return sum;
    }
}
// @lc code=end

