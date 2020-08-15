//
// Created by 陈海斌 on 2020-08-15.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

/*
I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
 */

/*
 * Runtime: 40 ms, faster than 18.39% of C++ online submissions for Integer to Roman.
Memory Usage: 13.7 MB, less than 5.02% of C++ online submissions for Integer to Roman.
 */
class Solution {
public:
    string intToRoman(int num) {
        map<int,string> dic;
        dic[1] = "I";
        dic[4] = "IV";
        dic[5] = "V";
        dic[9] = "IX";
        dic[10] = "X";
        dic[40] = "XL";
        dic[50] = "L";
        dic[90] = "XC";
        dic[100] = "C";
        dic[400] = "CD";
        dic[500] = "D";
        dic[900] = "CM";
        dic[1000] = "M";
        vector<int> base = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int i = 0;
        string res = "";
        while (num > 0)
        {
            if (num >= base[i])
            {
                res += dic[base[i]];
                num -= base[i];
            }
            else
                i += 1;
        }
        return res;
    }
};

/*
 * Runtime: 12 ms, faster than 76.56% of C++ online submissions for Integer to Roman.
Memory Usage: 6 MB, less than 69.87% of C++ online submissions for Integer to Roman.
 The basic idea is really simple: replace every digit in num by roman numerals.

string intToRoman(int num) {
    string table[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                           {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                           {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                           {"", "M", "MM", "MMM"}
    };
    string result;
    int count = 0;
    while(num > 0){
        int temp = num % 10;
        result = table[count][temp] + result;
        num /= 10;
        count++;
    }
    return result;
}
 */

/*
int main()
{
    Solution s;
    cout << s.intToRoman(3) << endl;
    cout << s.intToRoman(4) << endl;
    cout << s.intToRoman(9) << endl;
    cout << s.intToRoman(58) << endl;
    cout << s.intToRoman(1994) << endl;
}
 */