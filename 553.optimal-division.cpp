/*
 * @lc app=leetcode id=553 lang=cpp
 *
 * [553] Optimal Division
 */

// @lc code=start
class step
{
public:
    double val;
    string expression = "";
    step(double val) { this->val = val; }
};

class Solution
{
private:
    vector<vector<step>> cachemax;
    vector<vector<step>> cachemin;

public:
    void maximum(int start, int end)
    {
        for (int i = start; i < end; i++)
        {
            if (cachemax[start][i].val == 0)
            {
                maximum(start, i);
            }
            if (cachemin[i + 1][end].val == DBL_MAX)
            {
                minimum(i + 1, end);
            }
            if (cachemax[start][i].val / cachemin[i + 1][end].val > cachemax[start][end].val)
            {
                cachemax[start][end].val = cachemax[start][i].val / cachemin[i + 1][end].val;
                if (i + 1 == end)
                {
                    cachemax[start][end].expression = cachemax[start][i].expression + "/" + cachemin[i + 1][end].expression;
                }
                else
                {
                    cachemax[start][end].expression = cachemax[start][i].expression + "/" + "(" + cachemin[i + 1][end].expression + ")";
                }
            }
        }
    }

    void minimum(int start, int end)
    {
        for (int i = start; i < end; i++)
        {
            if (cachemin[start][i].val == DBL_MAX)
            {
                minimum(start, i);
            }
            if (cachemax[i + 1][end].val == 0)
            {
                maximum(i + 1, end);
            }
            if (cachemin[start][i].val / cachemax[i + 1][end].val < cachemin[start][end].val)
            {
                cachemin[start][end].val = cachemin[start][i].val / cachemax[i + 1][end].val;
                if (i + 1 == end)
                {
                    cachemin[start][end].expression = cachemin[start][i].expression + "/" + cachemax[i + 1][end].expression;
                }
                else
                {
                    cachemin[start][end].expression = cachemin[start][i].expression + "/" + "(" + cachemax[i + 1][end].expression + ")";
                }
            }
        }
    }

    string optimalDivision(vector<int> &nums)
    {
        int last = nums.size();
        switch (last)
        {
        case 0:
            return "";
            break;
        case 1:
            return to_string(nums[0]);
            break;
        case 2:
            return to_string(nums[0]) + "/" + to_string(nums[1]);
            break;
        }
        cachemax = vector<vector<step>>(last, vector<step>(last, step(0)));
        cachemin = vector<vector<step>>(last, vector<step>(last, step(DBL_MAX)));
        for (int i = 0; i < last; i++)
        {
            cachemax[i][i].val = nums[i];
            cachemax[i][i].expression = to_string(nums[i]);
            cachemin[i][i].val = nums[i];
            cachemin[i][i].expression = to_string(nums[i]);
        }
        maximum(0, last - 1);
        return cachemax[0][last - 1].expression;
    }
};
// @lc code=end
