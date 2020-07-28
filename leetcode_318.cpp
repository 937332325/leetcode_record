//
// Created by 陈海斌 on 2020-02-05.
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

//remind ^优先级比==低; vector也可以& 默认每个元素都&
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<int> mask(words.size());
        for (int i=0;i<words.size();i++)
        {
            for (int k=0;k<words[i].size();k++)
                mask[i] |= words[i][k];
            for (int j=0;j<i;j++)
            {
                if (!(mask[i] & mask[j])) {
                    int s = words[i].size() * words[j].size();
                    res = max(s, res);
                }
            }
        }
        return res;
    }
};
/*
int main()
{
    Solution s;
    vector<string> a = {"abcde", "hik"};
    string b = "abc";
    cout << s.maxProduct(a);
}
*/