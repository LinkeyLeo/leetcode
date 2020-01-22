/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> last;
        bool unused[10];
        memset(unused, true, 10);
        vector<vector<int>> combinations;
        vector<int> combination;
        int back = 0;
        do
        {
            if (!last.empty())
            {
                combination.pop_back();
                back = last.back();
                last.pop_back();
                unused[back] = true;
                k++;
                n += back;
            }
            for (int i = back + 1; i < 10; i++)
            {
                if (k == 1)
                {
                    if (n >= i && n < 10 && unused[n])
                    {
                        combination.push_back(n);
                        combinations.push_back(vector<int>(combination));
                        combination.pop_back();
                    }
                    combination.pop_back();
                    i = last.back();
                    last.pop_back();
                    unused[i] = true;
                    k++;
                    n += i;
                }
                else if (unused[i])
                {
                    if (n > i)
                    {
                        combination.push_back(i);
                        last.push_back(i);
                        unused[i] = false;
                        k--;
                        n -= i;
                    }
                    else if (!last.empty())
                    {
                        combination.pop_back();
                        i = last.back();
                        last.pop_back();
                        unused[i] = true;
                        k++;
                        n += i;
                    }
                }
            }
        } while (!last.empty());
        return combinations;
    }
};
// @lc code=end
