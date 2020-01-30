/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
        {
            return "";
        }
        queue<TreeNode *> nodes({root->left, root->right});
        string serialized = to_string(root->val);
        TreeNode *node;
        while (!nodes.empty())
        {
            node = nodes.front();
            nodes.pop();
            if (node == NULL)
            {
                serialized += ",*";
            }
            else
            {
                serialized += "," + to_string(node->val);
                nodes.push(node->left);
                nodes.push(node->right);
            }
        }
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "")
        {
            return NULL;
        }
        int c = 1;
        while (data[c] != ',')
        {
            c++;
        }
        TreeNode *root = new TreeNode(stoi(data.substr(0, c)));
        queue<TreeNode *> nodes({root});
        c++;
        int i = c++;
        TreeNode *node;
        while (!nodes.empty())
        {
            node = nodes.front();
            nodes.pop();
            if (data[i] == '*')
            {
                c += 2;
                i += 2;
            }
            else
            {
                while (data[c] != ',')
                {
                    c++;
                }
                node->left = new TreeNode(stoi(data.substr(i, c - i)));
                nodes.push(node->left);
                c++;
                i = c++;
            }
            if (data[i] == '*')
            {
                c += 2;
                i += 2;
            }
            else
            {
                while (data[c] != ',')
                {
                    c++;
                }
                node->right = new TreeNode(stoi(data.substr(i, c - i)));
                nodes.push(node->right);
                c++;
                i = c++;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
