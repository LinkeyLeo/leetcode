/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<bitset<9>> s(9, bitset<9>());
        vector<bitset<9>> h(9, bitset<9>());
        vector<bitset<9>> v(9, bitset<9>());
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (s[i / 3 * 3 + j / 3][board[i][j] - '1'] | h[i][board[i][j] - '1'] | v[j][board[i][j] - '1'])
                    {
                        return false;
                    }
                    s[i / 3 * 3 + j / 3].set(board[i][j] - '1');
                    h[i].set(board[i][j] - '1');
                    v[j].set(board[i][j] - '1');
                }
            }
        }
        return true;
    }
};
// @lc code=end
