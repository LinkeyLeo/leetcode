/*
 * @lc app=leetcode id=1006 lang=csharp
 *
 * [1006] Clumsy Factorial
 */

// @lc code=start
public class Solution
{
    List<Func<int, int>> lOps = new List<Func<int, int>> { (x) => 0, x => x, x => x * x - x, x => x * (x - 1) / (x - 2) };
    Func<int, int, int> mainOp = (r, d) => (4 * r + d - (4 * r + d - 1) * (4 * r + d - 2) / (4 * r + d - 3));
    Func<int, int> tOps = n => n > 3 && (n + 1) % 4 != 0 ? 1 : 0;
    public int Clumsy(int N)
    {
        int body = 0;
        for (int r = 0; r < (N - 3) / 4; body += mainOp(++r, (N + 1) % 4)) ;
        return lOps[Math.Min(3, N)](N) + body + tOps(N);
    }
}
// @lc code=end

