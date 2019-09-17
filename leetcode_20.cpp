//
// Created by 陈海斌 on 2019-09-16.
//
#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> res;
        for (int i=0;i<s.size();i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                res.push(s[i]);
            else if (res.size() == 0)
            {
                res.push('-1');
                break;
            }
            else if (s[i] == ')')
            {
                if (res.top() != '(')
                    break;
                else
                    res.pop();
            }
            else if (s[i] == ']')
            {
                if (res.top() != '[')
                    break;
                else
                    res.pop();
            }
            else if (s[i] == '}')
            {
                if (res.top() != '{')
                    break;
                else
                    res.pop();
            } else
                break;
        }
        return res.size() == 0;
    }
};

int main()
{
    Solution s;
    cout << s.isValid("([)]");
}