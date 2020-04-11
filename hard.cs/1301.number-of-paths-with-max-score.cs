/*
 * @lc app=leetcode id=1301 lang=csharp
 *
 * [1301] Number of Paths with Max Score
 */

// @lc code=start
public class Solution
{
    private Dictionary<int, int> score;
    private Dictionary<int, int> count;
    private IList<string> board;
    private int size;
    private void PathsWithMaxScore(int i, int j)
    {
        int stepMax = -1;
        int stepCount = 0;
        switch (board[i][j])
        {
            case 'X':
                break;
            default:
                if (i + 1 < size)
                {
                    if (!score.ContainsKey(((i + 1) << 8) + j))
                    {
                        PathsWithMaxScore(i + 1, j);
                    }
                    if (score[((i + 1) << 8) + j] != -1)
                    {
                        if (score[((i + 1) << 8) + j] + board[i][j] - '0' == stepMax)
                        {
                            stepCount += count[((i + 1) << 8) + j];
                        }
                        else if (score[((i + 1) << 8) + j] + board[i][j] - '0' > stepMax)
                        {
                            stepMax = score[((i + 1) << 8) + j] + board[i][j] - '0';
                            stepCount = count[((i + 1) << 8) + j];
                        }
                    }
                }
                if (j + 1 < size)
                {
                    if (!score.ContainsKey((i << 8) + j + 1))
                    {
                        PathsWithMaxScore(i, j + 1);
                    }
                    if (score[(i << 8) + j + 1] != -1)
                    {
                        if (score[(i << 8) + j + 1] + board[i][j] - '0' == stepMax)
                        {
                            stepCount += count[(i << 8) + j + 1];
                        }
                        else if (score[(i << 8) + j + 1] + board[i][j] - '0' > stepMax)
                        {
                            stepMax = score[(i << 8) + j + 1] + board[i][j] - '0';
                            stepCount = count[(i << 8) + j + 1];
                        }
                    }
                }
                if (i + 1 < size && j + 1 < size)
                {
                    if (!score.ContainsKey(((i + 1) << 8) + j + 1))
                    {
                        PathsWithMaxScore(i + 1, j + 1);
                    }
                    if (score[((i + 1) << 8) + j + 1] != -1)
                    {
                        if (score[((i + 1) << 8) + j + 1] + board[i][j] - '0' == stepMax)
                        {
                            stepCount += count[((i + 1) << 8) + j + 1];
                        }
                        else if (score[((i + 1) << 8) + j + 1] + board[i][j] - '0' > stepMax)
                        {
                            stepMax = score[((i + 1) << 8) + j + 1] + board[i][j] - '0';
                            stepCount = count[((i + 1) << 8) + j + 1];
                        }
                    }
                }
                break;
        }
        score.Add((i << 8) + j, stepMax);
        count.Add((i << 8) + j, stepCount % 1000000007);
    }
    public int[] PathsWithMaxScore(IList<string> board)
    {
        size = board.Count;
        this.board = board;
        score = new Dictionary<int, int> { { 0x0101 * (size - 1), 0 } };
        count = new Dictionary<int, int> { { 0x0101 * (size - 1), 1 } };
        PathsWithMaxScore(0, 0);
        if (score[0] == -1)
        {
            return new int[] { 0, 0 };
        }
        else
        {
            return new int[] { score[0] - ('E' - '0') % 1000000007, count[0] };
        }
    }
}
// @lc code=end

