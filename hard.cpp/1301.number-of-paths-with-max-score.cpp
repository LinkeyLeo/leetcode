/*
 * @lc app=leetcode id=1301 lang=cpp
 *
 * [1301] Number of Paths with Max Score
 */

// @lc code=start
class Solution
{
public:
    vector<int> pathsWithMaxScore(vector<string> &board)
    {
        map<pair<int, int>, pair<int, int>> cache({{{0, 0}, {0, 1}}});
        queue<pair<int, int>> back({{0, 0}});
        set<pair<int, int>> visit;
        set<pair<int, int>> diag;
        pair<int, int> next;
        pair<int, int> p;
        while (!back.empty())
        {
            p = back.front();
            back.pop();
            if (diag.find(p) != diag.end())
            {
                back.push(p);
                diag.erase(p);
            }
            else
            {
                int x = p.first;
                int y = p.second;
                p = cache[p];
                if (x + 1 < board.size())
                {
                    next = cache[{x + 1, y}];
                    switch (board[x + 1][y])
                    {
                    case 'S':
                        if (next.first < p.first)
                        {
                            cache[{x + 1, y}] = p;
                        }
                        else if (next.first == p.first)
                        {
                            cache[{x + 1, y}].second += p.second;
                            cache[{x + 1, y}].second %= 1000000007;
                        }
                        if (visit.find({x + 1, y}) == visit.end())
                        {
                            visit.insert({x + 1, y});
                            back.push({x + 1, y});
                        }
                    case 'X':
                        break;
                    default:
                        int v = board[x + 1][y] - '0';
                        if (next.first < p.first + v)
                        {
                            cache[{x + 1, y}] = {p.first + v, p.second};
                        }
                        else if (next.first == p.first + v)
                        {
                            cache[{x + 1, y}].second += p.second;
                            cache[{x + 1, y}].second %= 1000000007;
                        }
                        if (visit.find({x + 1, y}) == visit.end())
                        {
                            visit.insert({x + 1, y});
                            back.push({x + 1, y});
                        }
                    }
                }
                if (y + 1 < board.size())
                {
                    next = cache[{x, y + 1}];
                    switch (board[x][y + 1])
                    {
                    case 'S':
                        if (next.first < p.first)
                        {
                            cache[{x, y + 1}] = p;
                        }
                        else if (next.first == p.first)
                        {
                            cache[{x, y + 1}].second += p.second;
                            cache[{x, y + 1}].second %= 1000000007;
                        }
                        if (visit.find({x, y + 1}) == visit.end())
                        {
                            visit.insert({x, y + 1});
                            back.push({x, y + 1});
                        }
                    case 'X':
                        break;
                    default:
                        int v = board[x][y + 1] - '0';
                        if (next.first < p.first + v)
                        {
                            cache[{x, y + 1}] = {p.first + v, p.second};
                        }
                        else if (next.first == p.first + v)
                        {
                            cache[{x, y + 1}].second += p.second;
                            cache[{x, y + 1}].second %= 1000000007;
                        }
                        if (visit.find({x, y + 1}) == visit.end())
                        {
                            visit.insert({x, y + 1});
                            back.push({x, y + 1});
                        }
                    }
                }
                if (x + 1 < board.size() && y + 1 < board.size() && board[x + 1][y] == 'X' && board[x][y + 1] == 'X')
                {
                    switch (board[x + 1][y + 1])
                    {
                    case 'S':
                        cache[{x + 1, y + 1}] = p;
                        if (visit.find({x + 1, y + 1}) == visit.end())
                        {
                            visit.insert({x + 1, y + 1});
                            diag.insert({x + 1, y + 1});
                            back.push({x + 1, y + 1});
                        }
                    case 'X':
                        break;
                    default:
                        cache[{x + 1, y + 1}] = {p.first + board[x + 1][y + 1] - '0', p.second};
                        if (visit.find({x + 1, y + 1}) == visit.end())
                        {
                            visit.insert({x + 1, y + 1});
                            diag.insert({x + 1, y + 1});
                            back.push({x + 1, y + 1});
                        }
                    }
                }
            }
        }
        return vector<int>({cache[{board.size() - 1, board.size() - 1}].first, cache[{board.size() - 1, board.size() - 1}].second});
    }
};
// @lc code=end
