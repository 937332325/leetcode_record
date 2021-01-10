//
// Created by 陈海斌 on 2020-08-15.
//
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 已失败策略，失败原因：一开始进去的左括号在后面不同情况(是否能完全匹配)会影响到前面的兑掉要不要累积，无法从左到右顺序遍历判断
 * 看了答案之后：需要定义个 start 变量来记录合法括号串的起始位置，可以从左到右O(n)的
 * 1. 出现左括号，累积；右括号进来就兑掉+2
 * 2. 右括号比左括号多了，已有数据结构清零
 * 3. 多个左括号时，若后面匹配不完全，累积的number要清0；能刚好匹配则要累积number
 */
/*
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> res;
        int number = 0;
        int max_number = 0;
        int last_number = 0;
        for (int i=0; i<s.size();i++)
        {
            if (res.empty() && s[i]=='(')
                res.push(s[i]);
            else if (res.size() > 0 && res.top()=='(' && s[i]==')')
            {
                number += 2;
                res.pop();
                // for case ()(() 2 not 4
                if (res.size()==0)
                {
                    number += last_number;
                    last_number = 0;
                }
                max_number = max(max_number, number);

            }
            else if (s[i]==')')
            {
                number = 0;
                last_number = 0;
            }
            // 剩下就是(+(了
            else{
                res.push(s[i]);
                last_number = number;
                number = 0;
            }
        }
        return max_number;
    }
};
*/

/*
 * 以"()(()"为例 从左右到右搜 1 1 0 1 1
   直到没有1
   求最长1的连续子序列或每确定一个11 左右扩张获得max_number

   Runtime: 44 ms, faster than 5.18% of C++ online submissions for Longest Valid Parentheses.
Memory Usage: 7.4 MB, less than 25.34% of C++ online submissions for Longest Valid Parentheses.
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        bool new_pair = true;
        int max_number = 0;
        vector<int> count(s.size(), 0);
        while (new_pair)
        {
            new_pair = false;
            for (int i=0; i<s.size(); i++)
            {
                if (count[i] == 1 || s[i] == ')')
                    continue;
                else
                {
                    int tmp = i+1;
                    while (tmp < s.size() && count[tmp]==1)
                        tmp += 1;
                    if (tmp < s.size() && s[tmp] == ')')
                    {
                        new_pair = true;
                        count[i] = 1;
                        count[tmp] = 1;
                        int span = tmp - i + 1;
                        int i_span = i - 1;
                        int tmp_span = tmp + 1;
                        while (i_span>-1 && count[i_span]==1)
                        {
                            span += 1;
                            i_span -= 1;
                        }
                        while (tmp_span<s.size() && count[tmp_span]==1)
                        {
                            span += 1;
                            tmp_span += 1;
                        }
                        max_number = max(max_number, span);
                    }
                }

            }
        }
        return max_number;
    }
};
// 答案解法
/*
 * 遍历字符串，如果遇到左括号，则将当前下标压入栈，如果遇到右括号，如果当前栈为空，则将下一个坐标位置记录到 start，如果栈不为空，则将
 * 栈顶元素取出，)取出时若栈为空，则更新结果和 i - start + 1 中的较大值，否则更新结果和 i - st.top() 中的较大值
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, start = 0, n = s.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                //)碰到空的栈 重新开始直到有新的(
                if (st.empty()) start = i + 1;
                else {
                    st.pop();
                    res = st.empty() ? max(res, i - start + 1) : max(res, i - st.top());
                }
            }
        }
        return res;
    }
};
 */

/*
int main()
{
    Solution s;
    // 8
    cout << s.longestValidParentheses("((()))())") << endl;
    // 4
    cout << s.longestValidParentheses("(()()") << endl;
    // 4
    cout << s.longestValidParentheses(")()())") << endl;
    // 2
    cout << s.longestValidParentheses("(()") << endl;
    // 2
    cout << s.longestValidParentheses("()(()") << endl;
    // 6
    cout << s.longestValidParentheses("()(())") << endl;
}
*/
