/*
 * @lc app=leetcode id=756 lang=csharp
 *
 * [756] Pyramid Transition Matrix
 */

// @lc code=start
public class Solution
{
    public bool PyramidTransition(string bottom, IList<string> allowed)
    {
        BitArray triple = new BitArray(7 * 8 * 8, false);
        Dictionary<int, List<int>> cache = new Dictionary<int, List<int>> { };
        for (int i = 0; i < 56; i++)
        {
            cache.Add(i, new List<int> { });
        }
        foreach (string pattern in allowed)
        {
            cache[((pattern[0] - 'A') << 3) + (pattern[1] - 'A')].Add(pattern[2] - 'A');
        }
        int level = bottom.Length;
        List<HashSet<int>> beneath = bottom.ToCharArray().Select(c => new HashSet<int> { c - 'A' }).ToList();
        while (--level > 0)
        {
            List<HashSet<int>> next = new List<HashSet<int>> { };
            for (int i = 0; i < level; i++)
            {
                HashSet<int> aboveCandidate = new HashSet<int> { };
                foreach (int lb in beneath[i])
                {
                    foreach (int rb in beneath[i + 1])
                    {
                        foreach (char c in cache[(lb << 3) + rb])
                        {
                            aboveCandidate.Add(c);
                        }
                    }
                }
                if (aboveCandidate.Count == 0)
                {
                    return false;
                }
                next.Add(aboveCandidate);
            }
            beneath = next;
        }
        return beneath.Count > 0;
    }
}
// @lc code=end

