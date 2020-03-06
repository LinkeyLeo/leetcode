/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
class Solution
{
public:
    vector<string> uncommonFromSentences(string A, string B)
    {
        set<string> occur;
        set<string> unique;
        string s = A + " " + B + " ";
        string word;
        for (char c : s)
        {
            switch (c)
            {
            case ' ':

                if (occur.find(word) != occur.end())
                {
                    unique.erase(word);
                }
                else
                {
                    occur.insert(word);
                    unique.insert(word);
                }
                word = "";
                break;
            default:
                word += c;
                break;
            }
        }
        return vector<string>(unique.begin(), unique.end());
    }
};
// @lc code=end
