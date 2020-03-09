/*
 * @lc app=leetcode id=468 lang=csharp
 *
 * [468] Validate IP Address
 */

// @lc code=start
public class Solution
{
    public string ValidIPAddress(string IP)
    {
        string[] seg = IP.Split('.');
        if (seg.Length == 4)
        {
            foreach (string k in seg)
            {
                if (k.Length > 3 || k.Length == 0 || k.Length > 1 && k[0] == '0')
                {
                    return "Neither";
                }
                int v = 0;
                foreach (char c in k)
                {
                    v *= 10;
                    v += c - '0';
                }
                if (v < 0 || v > 255)
                {
                    return "Neither";
                }
            }
            return "IPv4";
        }
        else if (seg.Length == 1)
        {
            seg = IP.Split(':');
            if (seg.Length != 8)
            {
                return "Neither";
            }
            foreach (string k in seg)
            {
                if (k.Length > 4 || k.Length == 0)
                {
                    return "Neither";
                }
                foreach (char c in k)
                {
                    if (!(c >= '0' && c <= '9' || c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F'))
                    {
                        return "Neither";
                    }
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
}
// @lc code=end

