/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 */

// @lc code=start
class Solution
{
private:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

public:
    string toGoatLatin(string S)
    {
        string result = "";
        string a = "";
        S += " ";
        for (int i = 1; i < S.size(); i += 2)
        {
            a += "a";
            string trail = "ma" + a + " ";
            if (isVowel(S[i - 1]))
            {
                result += S[i - 1];
            }
            else
            {
                trail = S[i - 1] + trail;
            }
            while (i < S.size() && S[i] != ' ')
            {
                result += S[i++];
            }
            result += trail;
        }
        result[result.size() - 1] = '\0';
        return result;
    }
};
// @lc code=end
