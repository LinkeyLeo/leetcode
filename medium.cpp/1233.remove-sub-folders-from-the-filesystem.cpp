/*
 * @lc app=leetcode id=1233 lang=cpp
 *
 * [1233] Remove Sub-Folders from the Filesystem
 */

// @lc code=start
class Node
{
public:
    bool vaild = false;
    map<string, Node *> sub;
};
class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        Node *root = new Node();
        root->sub[""] = new Node();
        for (string path : folder)
        {
            string name = "";
            Node *ptr = root;
            for (char c : path)
            {
                if (c == '/')
                {
                    if (ptr->sub[name] == NULL)
                    {
                        ptr->sub[name] = new Node();
                    }
                    ptr = ptr->sub[name];
                }
                name += c;
            }
            if (ptr->sub[name] == NULL)
            {
                ptr->sub[name] = new Node();
            }
            ptr->sub[name]->vaild = true;
        }
        queue<pair<string, Node *>> q({{"", root->sub[""]}});
        vector<string> result;
        while (!q.empty())
        {
            root = q.front().second;
            if (root->vaild)
            {
                result.push_back(q.front().first);
            }
            else
            {
                for (pair<string, Node *> sub : root->sub)
                {
                    q.push({sub.first, sub.second});
                }
            }
            q.pop();
        }
        return result;
    }
};
// @lc code=end
