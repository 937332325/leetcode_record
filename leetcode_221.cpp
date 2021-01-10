//
// Created by 陈海斌 on 2020-12-27.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution2 {
public:
    bool validate(vector<vector<char>>& matrix, int i, int j, int square)
    {
        if (square == 0)
        {
            if (matrix[i][j]=='1')
                return true;
            else
                return false;
        }
        for (int tmp_i=i; tmp_i<i+square; tmp_i++)
        {
            if (tmp_i > matrix.size()-1)
                return false;
            for (int tmp_j=j; tmp_j<j+square;tmp_j++)
            {
                if (tmp_j > matrix[0].size()-1)
                    return false;
                if (matrix[tmp_i][tmp_j] == '0')
                    return false;
            }
        }
        return true;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        for (int i=0; i<matrix.size(); i++)
        {
            for (int j=0; j<matrix[0].size(); j++)
            {
                int square = 0;
                while (validate(matrix, i, j, square))
                    square += 1;
                square = max(square-1, 0);
                res = max(res, square*square);
            }
        }
        return res;
    }
};

// true solution dp! 每个点的值是左上角那个点加上 上/左是否为1
// 经典题 但是就是写不出来。。经典dp表达式由这三个的min决定，以及矩阵单一规约方向(左上到右下)可以规约为一维列数列
// 自我练习题 复习时写一个规约为一维行数列的
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        if (matrix.size()==0)
            return res;
        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for (int j=1; j<=matrix[0].size(); j++)
        {
            for (int i=1; i<=matrix.size(); i++)
            {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res*res;
    }
};

/*
int main() {
    Solution s;

    vector<vector<char>> a = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << s.maximalSquare(a) << endl;

    vector<vector<char>> b = {{'0','1'},{'1','0'}};
    cout << s.maximalSquare(b) << endl;


    vector<vector<char>> c = {{'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}};
    cout << s.maximalSquare(c) << endl;

     * 0 0 0 1
     * 1 1 0 1
     * 1 1 1 1
     * 0 1 1 1
     * 0 1 1 1
     */
    //vector<vector<char>> d = {{'1','1','1','1','0'},{'1','1','1','1','0'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'1','1','1','1','1'}};
    //cout << s.maximalSquare(d) << endl;
//}
