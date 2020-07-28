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

//Runtime: 60 ms, faster than 25.59% of C++ online submissions for Counting Bits.
//Memory Usage: 9.7 MB, less than 43.90% of C++ online submissions for Counting Bits.
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        for (int i=0;i<num+1;i++)
        {
            int res = i;
            for (int j=0;j<32;j++)
            {
                if (res & 1)
                    ans[i] += 1;
                res = res >> 1;
            }
        }
        return ans;
    }
};

//something not fancy but easy to understand, it just based on the fact that i and i>>1 share the common head;
//Runtime: 52 ms, faster than 94.01% of C++ online submissions for Counting Bits.
//Memory Usage: 9.6 MB, less than 63.42% of C++ online submissions for Counting Bits.
/*
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};
 */