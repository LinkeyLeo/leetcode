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
        List<short>[] indices = new List<short>[26];
        for (short i = 0; i < s.Length; i++)
        {
            indices[s[i] - 'A'] ??= new List<short>();
            indices[s[i] - 'A'].Add(i);
        }
        return indices
            .Select(idx => { idx?.Insert(0, -1); idx?.Add((short)s.Length); return idx; })
            .Select(idx =>
            {
                int p = 0;
                for (int i = 0; i < idx?.Count - 2; i++)
                {
                    p += (idx[i + 2] - idx[i + 1]) * (idx[i + 1] - idx[i]);
                    p %= 1000000007;
                }
                return p;
            })
            .Aggregate((a, b) => a + b % 1000000007);
    }
}
// @lc code=end

