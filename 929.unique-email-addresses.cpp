/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */

// @lc code=start
class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> receivers;
        for (string address : emails)
        {
            int i = 0;
            string name = "";
            for (; address[i] != '@' && address[i] != '+'; i++)
            {
                if (address[i] != '.')
                {
                    name += address[i];
                }
            }
            for (; address[i] != '@'; i++)
                ;
            receivers.insert(name + "@" + address.substr(i + 1));
        }
        return receivers.size();
    }
};
// @lc code=end
