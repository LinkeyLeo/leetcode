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
            if (cachemax[i][start].val == 0)
            {
                maximum(start, i);
            }
            if (cachemin[end][i + 1].val == DBL_MAX)
            {
                minimum(i + 1, end);
            }
            if (cachemax[i][start].val / cachemin[end][i + 1].val > cachemax[end][start].val)
            {
                cachemax[end][start].val = cachemax[i][start].val / cachemin[end][i + 1].val;
                if (i + 1 == end)
                {
                    cachemax[end][start].expression = cachemax[i][start].expression + "/" + cachemin[end][i + 1].expression;
                }
                else
                {
                    cachemax[end][start].expression = cachemax[i][start].expression + "/" + "(" + cachemin[end][i + 1].expression + ")";
                }
            }
        }
    }

    void minimum(int start, int end)
    {
        for (int i = start; i < end; i++)
        {
            if (cachemin[i][start].val == DBL_MAX)
            {
                minimum(start, i);
            }
            if (cachemax[end][i + 1].val == 0)
            {
                maximum(i + 1, end);
            }
            if (cachemin[i][start].val / cachemax[end][i + 1].val < cachemin[end][start].val)
            {
                cachemin[end][start].val = cachemin[i][start].val / cachemax[end][i + 1].val;
                if (i + 1 == end)
                {
                    cachemin[end][start].expression = cachemin[i][start].expression + "/" + cachemax[end][i + 1].expression;
                }
                else
                {
                    cachemin[end][start].expression = cachemin[i][start].expression + "/" + "(" + cachemax[end][i + 1].expression + ")";
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
        for (int i = 0; i < last; i++)
        {
            cachemax.push_back(vector<step>(i + 1, step(0)));
            cachemin.push_back(vector<step>(i + 1, step(DBL_MAX)));
            cachemax[i][i].val = nums[i];
            cachemax[i][i].expression = to_string(nums[i]);
            cachemin[i][i].val = nums[i];
            cachemin[i][i].expression = to_string(nums[i]);
        }
        maximum(0, last - 1);
        return cachemax[last - 1][0].expression;
    }
};
// @lc code=end
