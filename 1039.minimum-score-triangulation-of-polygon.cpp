/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */

// @lc code=start
class Solution
{
public:
    int minScoreTriangulation(vector<int> &A)
    {
        int vertices = A.size();
        int partialminimun[50][50];
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                partialminimun[i][j] = 0;
            }
        }
        for (int i = 0; i < vertices; i++)
        {
            partialminimun[i][(i + 1) % vertices] = 0;
        }
        for (int i = 0; i < vertices; i++)
        {
            partialminimun[i][(i + 2) % vertices] = A[i] * A[(i + 1) % vertices] * A[(i + 2) % vertices];
        }
        for (int distance = 3; distance < vertices; distance++)
        {
            for (int i = 0; i < vertices; i++)
            {
                int minimum = INT_MAX;
                int tminimum;
                for (int stepdistance = 1; stepdistance < distance; stepdistance++)
                {
                    tminimum = partialminimun[i][(i + stepdistance) % vertices] + partialminimun[(i + stepdistance) % vertices][(i + distance) % vertices];
                    tminimum += A[i] * A[(i + stepdistance) % vertices] * A[(i + distance) % vertices];
                    if (tminimum < minimum)
                    {
                        minimum = tminimum;
                    }
                }
                partialminimun[i][(i + distance) % vertices] = minimum;
            }
        }
        return partialminimun[1][0];
    }
};
// @lc code=end
