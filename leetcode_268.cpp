//
// Created by 陈海斌 on 2020-02-05.
//
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

// 思路 XOR两次 a^a=0 剩下那个只出现一次的
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int j=0; j<nums.size(); j++)
        {
            res ^= j;
            res ^= nums[j];
        }
        res ^= nums.size();
        return res;
    }
};
/*
int main()
{
    Solution s;
    vector<int> a = {1,0,3};
    cout << s.missingNumber(a);
}
 */