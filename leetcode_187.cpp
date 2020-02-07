//
// Created by 陈海斌 on 2020-02-02.
//

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <algorithm>
#include<unordered_map>

using namespace std;

/*
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> res;
        vector<string> repeat;
        if (s.size() < 10)
            return repeat;
        for (int i=0;i<s.size()-9;i++)
        {
            if (res.find(s.substr(i, 10)) != res.end() && find(repeat.begin(), repeat.end(), s.substr(i, 10)) == repeat.end())
                repeat.push_back(s.substr(i, 10));
            else
            {
                auto tmp = res.insert(s.substr(i, 10));
                cout << res.size() << endl;
            }
        }
        return repeat;
    }
};
*/

//unordered map写法
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> res;
        vector<string> repeat;
        if (s.size() < 10)
            return repeat;
        int mask = 0x7ffffff, cur = 0;
        for (int i = 0; i < 9; ++i) {
            cur = (cur << 3) | (s[i] & 7);
        }
        for (int i=9; i<s.size(); i++)
        {
            cur = ((cur & mask) << 3 | (s[i] & 7));
            if (res.count(cur)) {
                if (res.count(cur) == 1)
                    repeat.push_back(s.substr(i - 9, 10));
                res[cur] += 1;
            }
            else
                res[cur] = 1;
        }
        return repeat;
    }
};

/*
int main()
{
    Solution s;
    string a = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    string b = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    cout << b.size() << endl;
    //cout << s.findRepeatedDnaSequences(a);
    vector<string> r = s.findRepeatedDnaSequences(b);
    cout << r.size() << " ";
}
*/