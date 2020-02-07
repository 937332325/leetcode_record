//
// Created by 陈海斌 on 2020-02-03.
//

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <algorithm>
#include<unordered_map>

using namespace std;

//超时写法
/*
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = m;
        for (int i=m;i<=n;i++)
        {
            res &= i;
        }
        return res;
    }
};
*/
// idea 寻找m和n之间2^n最大的幂次 存在则返回0 再&n 寻找不到则&m

// Runtime: 20 ms, faster than 34.13% of C++ online submissions for Bitwise AND of Numbers Range.
// Memory Usage: 8.4 MB, less than 27.27% of C++ online submissions for Bitwise AND of Numbers Range.
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int pow_num_middle = 0;
        int res = m;
        for (int i=0;i<32;i++)
        {
            if ((pow(2, i) > m) && (pow(2, i) < n))
            {
                pow_num_middle = max(pow_num_middle, i);
            }
        }
        int pow_begin;
        if (pow_num_middle != 0)
        {
            return 0;
        }
        else
            pow_begin = m;
        //避免INT32_MAX i++造成溢出
        for (int i=pow_begin-1;i<n;i++)
        {
            res &= (i + 1);
        }
        return res;
    }
};

// 用mask的写法 只要写代码找到左边公共的部分即可
// Runtime: 28 ms, faster than 11.33% of C++ online submissions for Bitwise AND of Numbers Range.
// Memory Usage: 8.2 MB, less than 81.82% of C++ online submissions for Bitwise AND of Numbers Range.
/*
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        unsigned int d = INT_MAX;
        while ((m & d) != (n & d)) {
            d <<= 1;
        }
        return m & d;
    }
};
*/
// 如果n大于m，那么就对m和n分别除以2，并且调用递归函数，对结果再乘以2，一定要乘回来，不然就不对了，就举一个最简单的例子，m = 10, n = 11，
// 注意这里是二进制表示的，然后各自除以2，都变成了1，调用递归返回1，这时候要乘以2，才能变回10
// 除法类似于移位
// Runtime: 24 ms, faster than 19.40% of C++ online submissions for Bitwise AND of Numbers Range.
// Memory Usage: 8.3 MB, less than 72.73% of C++ online submissions for Bitwise AND of Numbers Range.
/*
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return (n > m) ? (rangeBitwiseAnd(m / 2, n / 2) << 1) : m;
    }
};
 */
/*
int main()
{
    Solution s;
    cout << INT32_MAX << endl;
    cout << s.rangeBitwiseAnd(2147483646,2147483647);
}
 */