/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Trie
{
public:
    bool isWord = false;
    map<char, Trie *> c;
};
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        Trie *root = new Trie();
        for (string word : wordDict)
        {
            Trie *node = root;
            int i = 0;
            for (char c : word)
            {
                if (node->c[c] == NULL)
                {
                    node->c[c] = new Trie();
                }
                node = node->c[c];
            }
            node->isWord = true;
        }
        stack<int> q({0});
        unordered_set<int> tried({0});
        while (!q.empty())
        {
            int i = q.top();
            Trie *node = root;
            q.pop();
            while (i < s.size() && node->c[s[i]] != NULL)
            {
                node = node->c[s[i]];
                i++;
                if (node->isWord)
                {
                    if (i == s.size())
                    {
                        return true;
                    }
                    else if (tried.find(i) == tried.end())
                    {
                        tried.insert(i);
                        q.push(i);
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end
