/*
 * @lc app=leetcode.cn id=2432 lang=cpp
 *
 * [2432] 处理用时最长的那个任务的员工
 */

// @lc code=start
class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        int id = 0, time = 0, endTime = 0;
        for (const vector<int> &arr : logs)
        {
            int ctime = arr[1] - endTime;
            if (ctime > time)
            {
                time = ctime;
                id = arr[0];
            }
            else if (ctime == time)
            {
                id = min(id, arr[0]);
            }
            endTime = arr[1];
        }
        return id;
    }
};
// @lc code=end
