/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator
{
private:
    queue<int> flatten;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        flatten.push(0);
        stack<vector<NestedInteger>*> back({&nestedList});
        stack<int> backidx({0});
        while (!back.empty())
        {
            vector<NestedInteger>* nested = back.top();
            back.pop();
            int i = backidx.top();
            backidx.pop();
            while (i < (*nested).size())
            {
                if ((*nested)[i].isInteger())
                {
                    flatten.push((*nested)[i].getInteger());
                    i++;
                }
                else
                {
                    back.push(nested);
                    backidx.push(i + 1);
                    nested = &(*nested)[i].getList();
                    i = 0;
                }
            }
        }
    }

    int next()
    {
        flatten.pop();
        return flatten.front();
    }

    bool hasNext()
    {
        return flatten.size() > 1;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
