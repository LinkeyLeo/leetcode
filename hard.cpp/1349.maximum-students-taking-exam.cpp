/*
 * @lc app=leetcode id=1349 lang=cpp
 *
 * [1349] Maximum Students Taking Exam
 */

// @lc code=start
class Solution
{
private:
    unordered_map<bitset<64>, int> cache;
    int r;
    int c;
    int maxStudents(int idx, bitset<64> available)
    {
        int m = 0;
        while (++idx < 64)
        {
            int i = idx >> 3;
            int j = idx & 7;
            if (i < r && j < c)
            {
                if (available[(i << 3) + j])
                {
                    bitset<64> mask(UINT64_MAX);
                    if (j > 0)
                    {
                        for (int k = max(0, i - 1); k < min(r, i + 2); k++)
                        {
                            mask.reset((k << 3) + j - 1);
                        }
                    }
                    if (j < c - 1)
                    {
                        for (int k = max(0, i - 1); k < min(r, i + 2); k++)
                        {
                            mask.reset((k << 3) + j + 1);
                        }
                    }
                    available.reset((i << 3) + j);
                    if (cache.find(mask & available) == cache.end())
                    {
                        cache[mask & available] = maxStudents(idx, mask & available) + 1;
                    }
                    m = max(m, cache[mask & available]);
                }
            }
        }
        return m;
    }

public:
    int maxStudents(vector<vector<char>> &seats)
    {
        r = seats.size();
        c = seats[0].size();
        bitset<64> available;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (seats[i][j] == '.')
                {
                    available.set((i << 3) + j);
                }
            }
        }
        return maxStudents(-1, available);
    }
};
// @lc code=end
