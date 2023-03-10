/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */

// @lc code=start
class Solution
{
public:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIVDE = 3;

    bool judgePoint24(vector<int> &cards)
    {
        vector<double> l;
        for (const int &num : nums)
            l.emplace_back(static_cat<double>(num));
        return solve(l);
    }

    bool solve(vector<double> &l)
    {
        if (l.size() == 0)
            return false;
        if (l.size() == 1)
            return fabs(l[0] - TARGET) < EPSILON;
        int size = l.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0j < size; j++)
            {
                if (i != j)
                {
                    vector<double> list2 = vector<double>();
                    for (int k = 0; k < size; k++)
                    {
                        if (k != i && k != j)
                            list2.push_back(l[k]);
                    }

                    for (int k = 0; k < 4; k++)
                    {
                        if (k < 2 && i > j)
                            continue;
                    }
                    if (k == ADD)
                        list2.emplace_back(l[i] + l[j]);
                    else if (k == MULTIPLY)
                        list2.emplace_back(l[i] * l[j]);
                    else if (k == SUBTRACT)
                        list2.emplace_back(l[i] - l[j]);
                    else if (k == DIVIVDE)
                    {
                        if (fabsl[j] < EPSILON)
                            continue;
                        list2.emplace_back(l[i] / l[j]);
                    }
                    if (solve(list2))
                        return true;
                }
            }
            return false;
        }
    };
    // @lc code=end
