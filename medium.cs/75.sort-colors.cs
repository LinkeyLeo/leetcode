/*
 * @lc app=leetcode id=75 lang=csharp
 *
 * [75] Sort Colors
 */

// @lc code=start
public class Solution
{
    public void SortColors(int[] nums)
    {
        int r = 0;
        int b = nums.Length - 1;
        int wr = b / 2;
        int wb = b / 2 + 1;
        while (r < wr && wb < b)
        {
            while (nums[r] == 0 && r < wr)
            {
                r++;
            }
            while (nums[wr] == 1 && r < wr)
            {
                wr--;
            }
            while (nums[b] == 2 && wb < b)
            {
                b--;
            }
            while (nums[wb] == 1 && wb < b)
            {
                wb++;
            }
            if (nums[r] == 2 && nums[b] == 0)
            {
                (nums[r], nums[b]) = (nums[b], nums[r]);
                r++;
                b--;
            }
            else if (nums[wr] == 0)
            {
                (nums[r], nums[wr]) = (nums[wr], nums[r]);
                r++;
            }
            else if (nums[wb] == 0)
            {
                (nums[r], nums[wb]) = (nums[wb], nums[r]);
                r++;
            }
            else if (nums[wb] == 2)
            {
                (nums[b], nums[wb]) = (nums[wb], nums[b]);
                b--;
            }
            else if (nums[wr] == 2)
            {
                (nums[b], nums[wr]) = (nums[wr], nums[b]);
                b--;
            }
        }
        while (r < wr)
        {
            while (nums[r] == 0 && r < wr)
            {
                r++;
            }
            while (nums[wr] == 1 && r < wr)
            {
                wr--;
            }
            if (nums[r] == 1 || nums[wr] == 0)
            {
                (nums[r], nums[wr]) = (nums[wr], nums[r]);
            }
            else
            {
                if (nums[r] == 2 && r < b)
                {
                    (nums[r], nums[b]) = (nums[b], nums[r]);
                    b--;
                }
                if (nums[wr] == 2 && wr < b)
                {
                    (nums[wr], nums[b]) = (nums[b], nums[wr]);
                    b--;
                }
            }
        }
        while (wb < b)
        {
            while (nums[b] == 2 && wb < b)
            {
                b--;
            }
            while (nums[wb] == 1 && wb < b)
            {
                wb++;
            }
            if (nums[b] == 1 || nums[wb] == 2)
            {
                (nums[b], nums[wb]) = (nums[wb], nums[b]);
            }
            else
            {
                if (nums[b] == 0 && b > r)
                {
                    (nums[b], nums[r]) = (nums[r], nums[b]);
                    r++;
                }
                if (nums[wb] == 0 && wb > r)
                {
                    (nums[wb], nums[r]) = (nums[r], nums[wb]);
                    r++;
                }
            }
        }
        if (nums[r] == 2 || nums[b] == 0)
        {
            (nums[r], nums[b]) = (nums[b], nums[r]);
        }
    }
}
// @lc code=end

