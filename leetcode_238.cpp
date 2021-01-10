//
// Created by 陈海斌 on 2021-01-10.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//神仙想法 序列问题里的双指针
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        for (int i=0; i<nums.size();i++)
        {
            if (i == 0)
                left[i] = nums[i];
            else
                left[i] = nums[i] * left[i-1];
        }
        for (int i=nums.size()-1; i>0;i--)
        {
            if (i == nums.size()-1)
                right[i] = nums[nums.size()-1];
            else
                right[i] = nums[i] * right[i+1];
        }
        for (int i=0; i<nums.size();i++)
        {
            if (i == 0)
                res[i] = right[i+1];
            else if (i==nums.size()-1)
                res[i] = left[i-1];
            else
                res[i] = left[i-1] * right[i+1];
        }
        return res;
    }
};

//少一个空间
class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        for (int i=0; i<nums.size();i++)
        {
            if (i == 0)
                left[i] = nums[i];
            else
                left[i] = nums[i] * left[i-1];
        }
        for (int i=nums.size()-1; i>=0;i--)
        {
            if (i == nums.size()-1)
            {
                right[i] = nums[nums.size()-1];
                left[i] = left[i-1];
            }
            else{
                right[i] = nums[i] * right[i + 1];
                if (i != 0)
                    left[i] = left[i-1] * right[i+1];
                else
                    left[i] = right[i+1];
            }
        }
        return left;
    }
};

//只要一个数组，R其实可以简约为一个常数，因为也是序列乘！
class Solution3 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 1);
        for (int i=1; i<nums.size();i++)
        {
            left[i] = nums[i-1] * left[i-1];
        }
        int right = 1;
        for (int i=nums.size()-1; i>=0;i--)
        {
            left[i] *= right;
            right *= nums[i];
        }
        return left;
    }
};

int main() {
    Solution2 s;
    vector<int> a = {1,2,3,4};
    vector<int> b = s.productExceptSelf(a);
}