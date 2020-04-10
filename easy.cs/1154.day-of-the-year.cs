/*
 * @lc app=leetcode id=1154 lang=csharp
 *
 * [1154] Day of the Year
 */

// @lc code=start
public class Solution
{
    public int DayOfYear(string date)
    {
        int[] lt = new int[] { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
        int year = int.Parse(date.Substring(0, 4));
        int month = int.Parse(date.Substring(5, 2));
        int day = int.Parse(date.Substring(8, 2));
        return lt[month] + day + (month > 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 1 : 0);
    }
}
// @lc code=end

