/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 */

// @lc code=start
class Solution
{
private:
    map<unsigned int, int> cache;
    void cherryPickup(vector<vector<int>> &grid, vector<int> p0, vector<int> p1, unsigned int location)
    {
        int val = -1;
        if (cache.find(location + 0x01000100) == cache.end())
        {
            if (p0[0] + 1 < grid.size() && grid[p0[0] + 1][p0[1]] != -1 && grid[p1[0] + 1][p1[1]] != -1)
            {
                cherryPickup(grid, {p0[0] + 1, p0[1]}, {p1[0] + 1, p1[1]}, location + 0x01000100);
            }
            else
            {
                cache[location + 0x01000100] = -1;
            }
        }
        val = max(val, cache[location + 0x01000100]);
        if (cache.find(location + 0x00010001) == cache.end())
        {
            if (p1[1] + 1 < grid.size() && grid[p0[0]][p0[1] + 1] != -1 && grid[p1[0]][p1[1] + 1] != -1)
            {
                cherryPickup(grid, {p0[0], p0[1] + 1}, {p1[0], p1[1] + 1}, location + 0x00010001);
            }
            else
            {
                cache[location + 0x00010001] = -1;
            }
        }
        val = max(val, cache[location + 0x00010001]);
        if (cache.find(location + 0x01000001) == cache.end())
        {
            if (p0[0] + 1 < grid.size() && p1[1] + 1 < grid.size() && grid[p0[0] + 1][p0[1]] != -1 && grid[p1[0]][p1[1] + 1] != -1)
            {
                cherryPickup(grid, {p0[0] + 1, p0[1]}, {p1[0], p1[1] + 1}, location + 0x01000001);
            }
            else
            {
                cache[location + 0x01000001] = -1;
            }
        }
        val = max(val, cache[location + 0x01000001]);
        if (cache.find(location + 0x00010100) == cache.end())
        {
            if (p0[1] + 1 == p1[1] && p1[0] + 1 == p0[0] && grid[p0[0]][p1[1]] != -1)
            {
                cherryPickup(grid, {p0[0], p1[1]}, location + 0x0010100);
            }
            else if (grid[p0[0]][p0[1] + 1] != -1 && grid[p1[0] + 1][p1[1]] != -1)
            {
                cherryPickup(grid, {p0[0], p0[1] + 1}, {p1[0] + 1, p1[1]}, location + 0x00010100);
            }
            else
            {
                cache[location + 0x00010100] = -1;
            }
        }
        val = max(val, cache[location + 0x00010100]);
        cache[location] = val == -1 ? -1 : grid[p0[0]][p0[1]] + grid[p1[0]][p1[1]] + val;
    }

    void cherryPickup(vector<vector<int>> &grid, vector<int> p, unsigned int location)
    {
        int val = -1;
        if (cache.find(location + 0x01000100) == cache.end())
        {
            if (p[0] + 1 < grid.size() && grid[p[0] + 1][p[1]] != -1)
            {
                cherryPickup(grid, {p[0] + 1, p[1]}, location + 0x01000100);
            }
            else
            {
                cache[location + 0x01000100] = -1;
            }
        }
        val = max(val, cache[location + 0x01000100]);
        if (cache.find(location + 0x00010001) == cache.end())
        {
            if (p[1] + 1 < grid.size() && grid[p[0]][p[1] + 1] != -1)
            {
                cherryPickup(grid, {p[0], p[1] + 1}, location + 0x00010001);
            }
            else
            {
                cache[location + 0x00010001] = -1;
            }
        }
        val = max(val, cache[location + 0x00010001]);
        if (cache.find(location + 0x01000001) == cache.end())
        {
            if (p[0] + 1 < grid.size() && grid[p[0] + 1][p[1]] != -1 && p[1] + 1 < grid.size() && grid[p[0]][p[1] + 1] != -1)
            {
                cherryPickup(grid, {p[0] + 1, p[1]}, {p[0], p[1] + 1}, location + 0x01000001);
            }
            else
            {
                cache[location + 0x01000001] = -1;
            }
        }
        val = max(val, cache[location + 0x01000001]);
        cache[location] = val == -1 ? -1 : grid[p[0]][p[1]] + val;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        if (grid.size() < 2)
        {
            return grid[0][0] == 1 ? 1 : 0;
        }
        cache[(grid.size() - 1) * 0x01010101] = grid[grid.size() - 1][grid.size() - 1];
        cherryPickup(grid, {0, 0}, 0);
        return cache[0] == -1 ? 0 : cache[0];
    }
};
// @lc code=end
