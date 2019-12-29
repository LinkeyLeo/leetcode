/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> outerTrees(vector<vector<int>> &points)
    {
        int total = points.size();
        if (total < 4)
        {
            return points;
        }
        int topx, bottomx, leftx = 101, rightx = -1;
        int topy = -1, bottomy = 101, lefty, righty;
        for (int i = 0; i < total; i++)
        {
            vector<int> p = points[i];
            int x = p[0], y = p[1];
            if (x >= rightx)
            {
                rightx = x;
                righty = y;
            }
            if (x <= leftx)
            {
                leftx = x;
                lefty = y;
            }
            if (y >= topy)
            {
                topx = x;
                topy = y;
            }
            if (y <= bottomy)
            {
                bottomx = x;
                bottomy = y;
            }
        }
        if (topy == bottomy || leftx == rightx)
        {
            return points;
        }
        vector<vector<int>> result;
        result.push_back(vector<int>({topx, topy}));
        result.push_back(vector<int>({rightx, righty}));
        result.push_back(vector<int>({bottomx, bottomy}));
        result.push_back(vector<int>({leftx, lefty}));
        for (int i = 0; i < 4; i++)
        {
            if (result[i] == result[(i + 1) % 4])
            {
                result.erase(result.begin() + i);
            }
        }
        int resulttotal = result.size();
        for (int i = 0; i < resulttotal; i++)
        {
            points.erase(find(points.begin(), points.end(), result[i]));
        }
        total = points.size();
        double centerx, centery;
        switch (resulttotal)
        {
        case 3:
            centerx = (result[0][0] + result[1][0] + result[2][0]) / 3.0;
            centery = (result[0][1] + result[1][1] + result[2][1]) / 3.0;
            break;
        case 4:
            centerx = (result[1][0] + result[3][0]) / 2.0;
            centery = (result[0][1] + result[2][1]) / 2.0;
            break;
        default:
            break;
        }
        bool enclose = false;
        vector<vector<int>> step;
        while (!enclose)
        {
            step.clear();
            for (int i = 0; i < resulttotal; i++)
            {
                double distance = 1;
                vector<int> p1 = result[i];
                vector<int> p2 = result[(i + 1) % resulttotal];
                step.push_back(p1);
                bool vertical = false;
                if (p1[0] == p2[0])
                {
                    vertical = true;
                }
                double k, b, centerdirection;
                if (vertical)
                {
                    b = p1[0];
                    centerdirection = centerx - b;
                }
                else
                {
                    k = 1.0 * (p1[1] - p2[1]) / (p1[0] - p2[0]);
                    b = p1[1] - k * p1[0];
                    centerdirection = centery - (k * centerx + b);
                }
                vector<int> p0;
                for (int i = 0; i < total; i++)
                {
                    vector<int> pt = points[i];
                    double pointdirection;
                    if (vertical)
                    {
                        pointdirection = pt[0] - b;
                    }
                    else
                    {
                        pointdirection = pt[1] - (k * pt[0] + b);
                    }
                    if (pointdirection * centerdirection < distance)
                    {
                        p0 = pt;
                        distance = pointdirection * centerdirection;
                    }
                }
                if (distance <= 0)
                {
                    step.push_back(p0);
                    points.erase(find(points.begin(), points.end(), p0));
                    total--;
                }
            }
            if (resulttotal == step.size())
            {
                enclose = true;
            }
            else
            {
                result.assign(step.begin(), step.end());
                resulttotal = result.size();
            }
        }
        return result;
    }
};
// @lc code=end
