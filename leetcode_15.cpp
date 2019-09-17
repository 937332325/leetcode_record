//
// Created by 陈海斌 on 2019-09-15.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 思路：先fix一个 求后面两个
// 后面两个可以求出所有二元组合 O(n^2)
// 这里可以先排序o(nlogn) 在以线性时间的双指针法找出结果 注意不能和fix值相同
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        for (int fix=0;fix<nums.size()-2;fix++)
        {
            // 排序后fix的值大于0则不可能还有符合条件的三元组
            if (nums[fix] > 0)
                break;
            if (fix > 0 && nums[fix] == nums[fix-1])
                continue;
            int i = fix + 1, j = nums.size() - 1;
            while (i < j)
            {
                if (nums[i] + nums[j] == -nums[fix]) {
                    res.push_back({nums[fix], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1])
                        ++i;
                    while (i < j && nums[j] == nums[j - 1])
                        --j;
                    ++i; --j;
                }
                else if (nums[i] + nums[j] < -nums[fix])
                    ++i;
                else
                    --j;
            }
        }
        return res;
    }
};

