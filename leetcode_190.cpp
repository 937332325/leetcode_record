//
// Created by 陈海斌 on 2020-01-30.
//

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

//stack 效率有点低
/*
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        stack<int> s;
        uint32_t res = 0;
        for (int i=0;i<32;i++)
        {
            s.push((n>>i) & 1);
        }
        for (int i=0;i<32;i++)
        {
            res |= ((s.top()) << i);
            s.pop();
        }
        return res;
    }
};
*/

/*
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        auto ret = 0;
        for (auto i = 0; i < 32; ++i) {
            ret = (ret << 1) + (n & 1);
            n >>= 1;
        }
        return ret;
    }
};
*/

//最高级操作 两两交换 从16到1
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};

/*
int main()
{
    Solution s;
    cout << s.reverseBits(43261596);
}
*/