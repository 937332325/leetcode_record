//
// Created by 陈海斌 on 2020-01-30.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;

//baseline排序
//两个数异或 ^= 三个数 二进制中不能被3整除的数拿出来
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i=0;i<32;i++)
        {
            int count = 0;
            for (int j=0;j<nums.size();j++)
            {
                if ((nums[j] >> i) & 1)
                    count += 1;
            }
            if (count % 3 != 0)
                ans |= (1 << i);
        }
        return ans;
    }
};
/*
int main()
{
    // cout << (-2147483648 << 1) << endl;
    Solution s;
    // 99: 1100011 2: 0000010
    vector<int> a = {1,1,-3,1,-3,-3,-4,-2};
    cout << s.singleNumber(a);
}
 */