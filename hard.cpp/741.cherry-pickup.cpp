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
    int cherryPickup(vector<vector<int>> &grid, vector<int> p0, vector<int> p1)
    {
        if (p0 == p1)
        {
            return cherryPickup(grid, p0);
        }
        if (p0[0] >= grid.size() || p1[1] >= grid.size() || p0[0] < p1[0] && p0[1] > p1[1] || grid[p0[0]][p0[1]] == -1 || grid[p1[0]][p1[1]] == -1)
        {
            return -1;
        }
        unsigned int location = (p0[0] << 24) + (p0[1] << 16) + (p1[0] << 8) + p1[1];
        if (cache.find(location) == cache.end())
        {
            int dd = cherryPickup(grid, {p0[0] + 1, p0[1]}, {p1[0] + 1, p1[1]});
            int dr = cherryPickup(grid, {p0[0] + 1, p0[1]}, {p1[0], p1[1] + 1});
            int rd = cherryPickup(grid, {p0[0], p0[1] + 1}, {p1[0] + 1, p1[1]});
            int rr = cherryPickup(grid, {p0[0], p0[1] + 1}, {p1[0], p1[1] + 1});
            cache[location] = max(max(dd, dr), max(rd, rr)) == -1 ? -1 : grid[p0[0]][p0[1]] + grid[p1[0]][p1[1]] + max(max(dd, dr), max(rd, rr));
        }
        return cache[location];
    }

    int cherryPickup(vector<vector<int>> &grid, vector<int> p)
    {
        if (p[0] >= grid.size() || p[1] >= grid.size() || grid[p[0]][p[1]] == -1)
        {
            return -1;
        }
        else if (p[0] == grid.size() - 1 && p[1] == grid.size() - 1)
        {
            return grid[grid.size() - 1][grid.size() - 1];
        }

        unsigned int location = (p[0] << 24) + (p[1] << 16) + (p[0] << 8) + p[1];
        if (cache.find(location) == cache.end())
        {
            int d = cherryPickup(grid, {p[0] + 1, p[1]});
            int r = cherryPickup(grid, {p[0], p[1] + 1});
            int s = cherryPickup(grid, {p[0] + 1, p[1]}, {p[0], p[1] + 1});
            cache[location] = max(max(d, r), s) == -1 ? -1 : grid[p[0]][p[1]] + max(max(d, r), s);
        }
        return cache[location];
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        return max(0, cherryPickup(grid, {0, 0}));
    }
};
// @lc code=end
