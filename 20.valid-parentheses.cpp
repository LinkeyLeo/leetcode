/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 == 1)
        {
            return false;
        }
        stack<char> brackets;
        for (char c : s)
        {
            switch (c)
            {
            case '(':
            case '[':
            case '{':
                brackets.push(c);
                break;
            case ')':
            case ']':
            case '}':
                if (brackets.empty() || c - brackets.top() != 1 && c - brackets.top() != 2)
                {
                    return false;
                }
                brackets.pop();
                break;
            }
        }
        return brackets.empty();
    }
};
// @lc code=end
