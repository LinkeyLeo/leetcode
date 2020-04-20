/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int M = dungeon.size();
        int N = dungeon[0].size();
        vector<vector<int>> H(M, vector<int>(N, INT_MAX));
        for (int I = M - 1; I >= 0; I--)
        {
            for (int J = N - 1; J >= 0; J--)
            {
                H[I][J] = 1 - dungeon[I][J] > 1 ? 1 - dungeon[I][J] : 1;
                if (I != M - 1 || J != N - 1)
                {
                    int HI = INT_MAX;
                    if (I != M - 1)
                    {
                        HI = H[I][J] + dungeon[I][J] < H[I + 1][J] ? H[I + 1][J] - dungeon[I][J] : H[I][J];
                    }
                    int HJ = INT_MAX;
                    if (J != N - 1)
                    {
                        HJ = H[I][J] + dungeon[I][J] < H[I][J + 1] ? H[I][J + 1] - dungeon[I][J] : H[I][J];
                    }
                    H[I][J] = HI < HJ ? HI : HJ;
                }
            }
        }
        return H[0][0];
    }
};
// @lc code=end
