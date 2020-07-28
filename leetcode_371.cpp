//
// Created by 陈海斌 on 2020-02-07.
//

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;
// 1010
//+1111
//10001

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Two Integers.
//Memory Usage: 8.3 MB, less than 33.33% of C++ online submissions for Sum of Two Integers.
class Solution {
public:
    int getSum(int a, int b)
    {
        int res = 0, jinwei = 0;
        for (int i=0;i<32;i++)
        {
            int count = ((a&1)^(b&1)^jinwei);
            count <<= i;
            if ((a&1) && (b&1) || (jinwei&1) && (b&1) || (a&1) && (jinwei&1))
                jinwei = 1;
            else
                jinwei = 0;
            a >>= 1;
            b >>= 1;
            res ^= count;
        }
        return res;
    }
};

/*
int main()
{
    Solution s;
    cout << (1^1^1) << endl;
    cout << s.getSum(10, 15);
}
 */