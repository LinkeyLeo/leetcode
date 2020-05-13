/*
 * @lc app=leetcode id=42 lang=csharp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
public class Solution
{
    public int Trap(int[] height)
    {
        Stack<int> h = new Stack<int>();
        Stack<int> idx = new Stack<int>();
        int sum = 0;
        int pre = 0;
        for (int i = 0; i < height.Length; i++)
        {
            while (h.Count != 0 && pre < height[i])
            {
                if (height[i] < h.Peek())
                {
                    sum += (height[i] - pre) * (i - idx.Peek() - 1);
                    pre = height[i];
                }
                else
                {
                    sum += (h.Peek() - pre) * (i - idx.Pop() - 1);
                    pre = h.Pop();
                }
            }
            pre = height[i];
            h.Push(pre);
            idx.Push(i);
        }
        return sum;
    }
}
// @lc code=end

