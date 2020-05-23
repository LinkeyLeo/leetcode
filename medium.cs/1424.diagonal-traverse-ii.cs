/*
 * @lc app=leetcode id=1424 lang=csharp
 *
 * [1424] Diagonal Traverse II
 */

// @lc code=start
public class Solution
{
    public int[] FindDiagonalOrder(IList<IList<int>> nums)
    {
        LinkedList<int> answer = new LinkedList<int>(nums[0]);
        List<LinkedListNode<int>> insertion = new List<LinkedListNode<int>>();
        LinkedListNode<int> node = answer.First;
        while (node != null)
        {
            insertion.Add(node);
            node = node.Next;
        }
        for (int line = 1; line < nums.Count; line++)
        {
            for (int i = 0; i < nums[line].Count; i++)
            {
                if (line + i == insertion.Count)
                {
                    answer.AddLast(nums[line][i]);
                    insertion.Add(answer.Last);
                }
                else
                {
                    answer.AddAfter(insertion[line + i - 1], nums[line][i]);
                }
            }
        }
        return answer.Select(x => x).ToArray();
    }
}
// @lc code=end

