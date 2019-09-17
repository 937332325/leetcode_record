#include <iostream>

/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
 */

#include <string>
#include <vector>
using namespace std;

// 看出这里有重叠子问题，可用dp处理
// 关于*的处理：字符匹配|| *使用0次 || *字符是否匹配(检查上一状态是否匹配)
bool isMatch(string s, string p) {
    vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, 0));
    dp[0][0] = 1;
    for (int j=1; j<=p.size(); j++)
        dp[0][j] = p[j-1]=='*' && j >= 2 && dp[0][j-2];
    for (int i=1; i<=s.size(); i++)
    {
        for (int j=1; j<=p.size(); j++)
        {
            if (p[j-1] != '*')
                dp[i][j] = dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
            else if (j>=2)
                dp[i][j] = dp[i][j-2] || ((s[i-1]==p[j-2] || p[j-2] =='.')&& dp[i-1][j]);
        }
    }
    return dp[s.size()][p.size()];
}

/*
int main() {
    std::cout << isMatch("ippi", "p*.") << std::endl;
    std::cout << isMatch("ab", ".*") << std::endl;
    std::cout << isMatch("aa", "a*") << std::endl;
    std::cout << isMatch("ab", ".*c") << std::endl;
    std::cout << isMatch("aab", "c*a*b") << std::endl;
    std::cout << isMatch("cabbccaccabacccbaa", "b*b*c*b*b*c*.c*.*c") << std::endl;
    std::cout << isMatch("aa", "aaa") << std::endl;
    std::cout << isMatch("aaa", "a*aa") << std::endl;
    std::cout << isMatch("aaa","ab*a*c*a") << std::endl;
    std::cout << isMatch("aaca", "ab*a*c*a") << std::endl;
    return 0;
}
*/

// 常见情况 a*/a.的处理
// 1.未考虑到情况：.*后还有字符(更大的问题是p是否匹配完）,只有.*则成功，否则还要判断是否和s最后一个匹配
// 2.习惯性和python一样写了字符串的-1
// 3. *不完全是贪心的 要考虑后面的p情况 补回来

// 难道这个问题是for循环里逐个移动 考虑所有情况嘛