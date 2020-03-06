/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
};
*/
class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        map<int, Node *> nodes({{node->val, new Node(node->val)}});
        queue<Node *> q({node});
        Node *source, *target;
        while (!q.empty())
        {
            source = q.front();
            q.pop();
            target = nodes[source->val];
            for (Node *neighbor : source->neighbors)
            {
                if (nodes.find(neighbor->val) == nodes.end())
                {
                    nodes.insert({neighbor->val, new Node(neighbor->val)});
                    q.push(neighbor);
                }
                target->neighbors.push_back(nodes[neighbor->val]);
            }
        }
        return nodes[1];
    }
};
// @lc code=end
