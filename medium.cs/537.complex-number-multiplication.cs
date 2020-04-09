/*
 * @lc app=leetcode id=537 lang=csharp
 *
 * [537] Complex Number Multiplication
 */

// @lc code=start
public class Solution
{
    private (int, int) unbox(string complex)
    {
        int split = complex.IndexOf("+");
        return (int.Parse(complex.Substring(0, split)), int.Parse(complex.Substring(split + 1, complex.Length - split - 2)));
    }
    public string ComplexNumberMultiply(string a, string b)
    {
        int ar;
        int ai;
        int br;
        int bi;
        int sr;
        int si;
        (ar, ai) = unbox(a);
        (br, bi) = unbox(b);
        sr = ar * br - ai * bi;
        si = ar * bi + ai * br;
        return $"{sr}+{si}i";
    }
}
// @lc code=end

