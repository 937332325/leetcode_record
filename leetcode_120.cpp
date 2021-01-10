//
// Created by 陈海斌 on 2020-09-01.
//

#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int minSum = INT_MAX;
        int h=triangle.size(),j;
        j=h;
        vector<vector<int>> v(h,vector<int> (j,0));
        v[0][0]=triangle[0][0];
        for(int i=1;i<h;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j==0) v[i][j]=v[i-1][j]+triangle[i][j];
                else if(j==triangle[i].size()-1) v[i][j]=v[i-1][j-1]+triangle[i][j];
                else
                    v[i][j]=min(v[i-1][j-1],v[i-1][j])+triangle[i][j];
            }

        }

        return *min_element(v[h-1].begin(),v[h-1].end());


    }
};

//比较秀的两个解法
// top-down
int minimumTotal1(vector<vector<int>>& triangle) {
    vector<int> res(triangle.size(), triangle[0][0]);
    for (unsigned int i = 1; i < triangle.size(); i++)
        for (int j = i; j >= 0; j--) {
            if (j == 0)
                res[0] += triangle[i][j];
            else if (j == i)
                res[j] = triangle[i][j] + res[j-1];
            else
                res[j] = triangle[i][j] + min(res[j-1], res[j]);
        }
    return *min_element(res.begin(), res.end());
}

// bottom-up
int minimumTotal(vector<vector<int>>& triangle) {
    vector<int> res = triangle.back();
    for (int i = triangle.size()-2; i >= 0; i--)
        for (unsigned int j = 0; j <= i; j++)
            res[j] = triangle[i][j] + min(res[j], res[j+1]);
    return res[0];
}

/*
int main()
{
    Solution s;
    vector<vector<int>> a = {
            {-1},
            {2,3},
            {1,-1,-3}};
    cout << s.minimumTotal(a) << endl;
    vector<vector<int>> b = {
            {2},
            {3,4},
            {6,5,7},
            {4,1,8,3}};
    cout << s.minimumTotal(b) << endl;
}
*/