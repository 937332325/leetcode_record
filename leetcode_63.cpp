//
// Created by 陈海斌 on 2020-08-24.
//

#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

/*
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
        if (obstacleGrid[0][0] == 1)
            return 0;
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        dp[0][0] = 1;
        bool exist_zero = false;
        for (int i=1;i<dp.size();i++)
        {
            if (obstacleGrid[i][0]==1)
                exist_zero = true;
            if (exist_zero)
                dp[i][0] = 0;
            else
                dp[i][0] = 1;
        }
        exist_zero = false;
        for (int i=1;i<dp[0].size();i++)
        {
            if (obstacleGrid[0][i]==1)
                exist_zero = true;
            if (exist_zero)
                dp[0][i] = 0;
            else
                dp[0][i] = 1;
        }
        for (int i=1; i<dp.size(); i++)
        {
            for (int j=1;j<dp[0].size();j++)
            {
                if (obstacleGrid[i][j]==1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
}
};
*/

/*
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
        if (obstacleGrid[0][0] == 1)
            return 0;
        vector<int> dp(obstacleGrid[0].size(), 0);
        int top = 0;
        int left = 0;
        for (int i=0; i<obstacleGrid[0].size(); i++)
    }
};
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
        if (obstacleGrid[0][0] == 1)
            return 0;
        obstacleGrid[0][0] = 1;
        bool exist_zero = false;
        for (int i=1;i<obstacleGrid.size();i++)
        {
            if (obstacleGrid[i][0]==1)
                exist_zero = true;
            if (exist_zero)
                obstacleGrid[i][0] = -1;
            else
                obstacleGrid[i][0] = 1;
        }
        exist_zero = false;
        for (int i=1;i<obstacleGrid[0].size();i++)
        {
            if (obstacleGrid[0][i]==1)
                exist_zero = true;
            if (exist_zero)
                obstacleGrid[0][i] = -1;
            else
                obstacleGrid[0][i] = 1;
        }
        for (int i=1; i<obstacleGrid.size(); i++)
        {
            for (int j=1;j<obstacleGrid[0].size();j++)
            {
                if (obstacleGrid[i][j]!=1)
                {
                    if (obstacleGrid[i-1][j] != -1)
                        obstacleGrid[i][j] += obstacleGrid[i-1][j];
                    if (obstacleGrid[i][j-1] != -1)
                        obstacleGrid[i][j] += obstacleGrid[i][j-1];
                }
                else
                    obstacleGrid[i][j] = -1;
            }
        }
        return max(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1], 0);
    }
};

/*
int main()
{
    Solution s;
    vector<vector<int>> a = {{0,0,0},{0,1,0},{0,0,0}};
    cout << s.uniquePathsWithObstacles(a) << endl;
    vector<vector<int>> b = {{0},{1}};
    cout << s.uniquePathsWithObstacles(b) << endl;
    vector<vector<int>> c = {{0,1,0},{1,1,0},{0,0,0}};
    cout << s.uniquePathsWithObstacles(c) << endl;
}
 */