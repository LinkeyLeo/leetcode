/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int row = board.size();
        if (row == 0)
        {
            return false;
        }
        int colume = board[0].size();
        vector<vector<bool>> used(row, vector<bool>(colume, false));
        stack<vector<int>> next;
        stack<vector<int>> back;
        int last = word.size() - 1;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < colume; j++)
            {
                next.push({0, i, j});
            }
        }
        vector<int> current;
        int i, j, p = 0;
        while (!next.empty())
        {
            current = next.top();
            next.pop();
            while (p > current[0])
            {
                used[back.top()[0]][back.top()[1]] = false;
                back.pop();
                p--;
            }
            while (p < current[0])
            {
                used[i][j] = true;
                back.push({i, j});
                p++;
            }
            i = current[1];
            j = current[2];
            if (board[i][j] == word[p])
            {
                if (p == last)
                {
                    return true;
                }
                if (i > 0 && !used[i - 1][j])
                {
                    next.push({p + 1, i - 1, j});
                }
                if (i < row - 1 && !used[i + 1][j])
                {
                    next.push({p + 1, i + 1, j});
                }
                if (j > 0 && !used[i][j - 1])
                {
                    next.push({p + 1, i, j - 1});
                }
                if (j < colume - 1 && !used[i][j + 1])
                {
                    next.push({p + 1, i, j + 1});
                }
            }
        }
        return false;
    }
};
// @lc code=end
