/*
 * @lc app=leetcode id=984 lang=cpp
 *
 * [984] String Without AAA or BBB
 */

// @lc code=start
class Solution
{
public:
    string strWithout3a3b(int A, int B)
    {
        string a;
        string b;
        if (A > B)
        {
            a = "a";
            b = "b";
        }
        else
        {
            A ^= B;
            B ^= A;
            A ^= B;
            a = "b";
            b = "a";
        }
        string str = "";
        string c = a + a + b;
        while (A > B && B > 0)
        {
            A -= 2;
            B--;
            str += c;
        }
        if (A == B)
        {
            if (A % 2 == 1)
            {
                str += a + b;
            }
            A--;
            c += b;
            while (A > 0)
            {
                A -= 2;
                str += c;
            }
        }
        else
        {
            switch (A)
            {
            case 2:
                str += a;
            case 1:
                str += a;
            case 0:
                break;
            }
        }
        return str;
    }
};
// @lc code=end
