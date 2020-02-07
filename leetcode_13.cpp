//
// Created by 陈海斌 on 2020-01-24.
//
#include <iostream>
#include <string>
#include <map>
using namespace std;

// 从左至右一个一个匹配 4 IV 9 IX是特殊
/*
I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
*/

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman_map;
        roman_map.insert(pair<char, int>('I', 1));
        roman_map.insert(pair<char, int>('V', 5));
        roman_map.insert(pair<char, int>('X', 10));
        roman_map.insert(pair<char, int>('L', 50));
        roman_map.insert(pair<char, int>('C', 100));
        roman_map.insert(pair<char, int>('D', 500));
        roman_map.insert(pair<char, int>('M', 1000));
        int res = 0;
        for (int i=0; i<s.size();i++)
        {
            if (s[i] == 'I' and i + 1 < s.size() and s[i+1] == 'V')
            {
                res += 4;
                i += 1;
            }
            else if (s[i] == 'I' and i + 1 < s.size() and s[i+1] == 'X')
            {
                res += 9;
                i += 1;
            }
            else if (s[i] == 'X' and i + 1 < s.size() and s[i+1] == 'L')
            {
                res += 40;
                i += 1;
            }
            else if (s[i] == 'X' and i + 1 < s.size() and s[i+1] == 'C')
            {
                res += 90;
                i += 1;
            }
            else if (s[i] == 'C' and i + 1 < s.size() and s[i+1] == 'D')
            {
                res += 400;
                i += 1;
            }
            else if (s[i] == 'C' and i + 1 < s.size() and s[i+1] == 'M')
            {
                res += 900;
                i += 1;
            }
            else
                res += roman_map[s[i]];
        }
        return res;
    }
};

/*
int main()
{
    Solution s;
    cout << s.romanToInt("IX");
}
*/

/*
leetcode sample answer: faster unorder; find substraction
int romanToInt(string s)
{
    unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };

    int sum = T[s.back()];
    for (int i = s.length() - 2; i >= 0; --i)
    {
        if (T[s[i]] < T[s[i + 1]])
        {
            sum -= T[s[i]];
        }
        else
        {
            sum += T[s[i]];
        }
    }

    return sum;
}
*/