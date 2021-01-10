//
// Created by 陈海斌 on 2020-09-07.
//

#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

//优化思路 方向改变坐标的映射可以用数组存储，排除繁琐if else嵌套，用i+1，然后i%4去访问就可以
//方法二 最外边框"距离"为1 下一圈框"距离"为2 通过圈这个矩形的左上角的点坐标和右下角的点坐标移动 4个for解决 不用消耗空间
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int now_i = 0;
        int now_j = -1;
        vector<int> res;
        if (matrix.size()==0 || matrix[0].size()==0)
            return res;
        // 0 右 1 下 2 左 3 上
        int direction = 0;
        while (1)
        {
            if ((now_j==matrix[0].size()-1 || matrix[now_i][now_j+1] == -INT16_MAX+1) &&
                (now_j==0 || matrix[now_i][now_j-1] == -INT16_MAX+1) &&
                (now_i==matrix.size()-1 || matrix[now_i+1][now_j] == -INT16_MAX+1) &&
                (now_i==0 || matrix[now_i-1][now_j] == -INT16_MAX+1) && matrix[now_i][now_j] == -INT16_MAX+1)
                break;
            if (direction == 0)
            {
                // initial
                if (now_j == -1)
                    direction = 0;
                else if (now_j == matrix[0].size()-1 || matrix[now_i][now_j+1] == -INT16_MAX+1)
                    direction = 1;
                else
                    direction = 0;
            }
            else if (direction == 1)
            {
                if (now_i == matrix.size()-1 || matrix[now_i+1][now_j] == -INT16_MAX+1)
                    direction = 2;
                else
                    direction = 1;
            }
            else if (direction == 2)
            {
                if (now_j == 0 || matrix[now_i][now_j-1] == -INT16_MAX+1)
                    direction = 3;
                else
                    direction = 2;
            }
            else
            {
                if (now_i == 0 || matrix[now_i-1][now_j] == -INT16_MAX+1)
                    direction = 0;
                else
                    direction = 3;
            }
            // initialize
            if (now_j == -1)
            {
                now_j += 1;
                continue;
            }
            else if (matrix[now_i][now_j] != -INT16_MAX+1)
            {
                res.push_back(matrix[now_i][now_j]);
                matrix[now_i][now_j] = -INT16_MAX+1;
            }
            if (direction == 0)
            {
                //cout << now_j << " ";
                //cout << matrix[0].size()-1 << " ";
                if (now_j < matrix[0].size()-1)
                    now_j += 1;
                //cout << now_j;
            }
            else if (direction == 1)
            {
                if (now_i < matrix.size()-1)
                    now_i += 1;
            }
            else if (direction == 2)
            {
                if (now_j > 0)
                    now_j -= 1;
            }
            else
            {
                if (now_i > 0)
                    now_i -= 1;
            }
        }
        return res;
    }
};

/*
int main()
{
    Solution s;
    vector<vector<int>> a = {{1,2,3}, {4,5,6}, {7,8,9}};
    //cout << a[0].size()-1;
    vector<int> res = s.spiralOrder(a);
    for (int i=0; i<res.size();i++)
        cout << res[i] << " ";
    cout << endl;
    vector<vector<int>> b = {{1}, {2}, {3}};
    res = s.spiralOrder(b);
    for (int i=0; i<res.size();i++)
        cout << res[i] << " ";
    cout << endl;
}
 */