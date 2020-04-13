/*
 * @lc app=leetcode id=777 lang=csharp
 *
 * [777] Swap Adjacent in LR String
 */

// @lc code=start
public class Solution
{
    public bool CanTransform(string start, string end)
    {
        int unpaired = 0;
        char waiting = ' ';
        for (int i = 0; i < start.Length; i++)
        {
            if (start[i] + end[i] == 'L' + 'R')
            {
                return false;
            }
            switch (start[i])
            {
                case 'L':
                    if (waiting == 'R' && unpaired > 0)
                    {
                        return false;
                    }
                    unpaired--;
                    break;
                case 'R':
                    if (waiting == 'L' && unpaired > 0)
                    {
                        return false;
                    }
                    unpaired++;
                    waiting = 'R';
                    break;
            }
            switch (end[i])
            {
                case 'L':
                    if (waiting == 'R' && unpaired > 0)
                    {
                        return false;
                    }
                    unpaired++;
                    waiting = 'L';
                    break;
                case 'R':
                    if (waiting == 'L' && unpaired > 0)
                    {
                        return false;
                    }
                    unpaired--;
                    break;
            }
            if (unpaired < 0)
            {
                return false;
            }
        }
        return unpaired == 0;
    }
}
// @lc code=end

