/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = 0, p2 = 0;
        int sortes[m + n];
        int cur;

        while (p1 < m || p2 < n)
        {
            if (p1 == m)
                cur = nums2[p2++];
            else if (p2 == n)
                cur = nums1[p1++];
            else if (nums1[p1] < nums2[p2])
                cur = nums1[p1++];
            else
                cur = nums2[p2++];
            sortes[p1 + p2 - 1] = cur;
        }
        for (int i = 0; i < m + n; i++)
            nums1[i] = sortes[i];
    }
};
// @lc code=end
