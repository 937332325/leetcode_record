//
// Created by 陈海斌 on 2020-07-23.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        int m = word1.size(), n = word2.size();
        for (int i=0; i<m+1;i++)
            dp[i][0] = i;
        for (int i=0; i<n+1;i++)
            dp[0][i] = i;
        for (int i=1; i<m+1;i++)
            for (int j=1; j<n+1;j++)
            {
                if (dp[i-1] == dp[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j]))+1;
            }
        return dp[m][n];
    }
};

// O(n) space fast methods
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int pre = 0;
        vector<int> dp(word2.size()+1);
        for (int i=0; i<n+1;i++)
            dp[i] = i;
        for (int i=1; i<m+1;i++)
        {
            pre = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; j++)
            {
                int tmp = dp[j];
                if (word1[i - 1] == word2[j - 1])
                    dp[j] = pre;
                else
                    dp[j] = min(pre, min(dp[j - 1], dp[j])) + 1;
                pre = tmp;
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    cout << s.minDistance("a", "b");
}