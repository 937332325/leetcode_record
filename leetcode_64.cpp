//
// Created by 陈海斌 on 2019-09-17.
//
#include <vector>
#include <iostream>
using namespace std;
//这个题减少空间的思路是只要存储上面一个和左边一个 所以不需要存储整个数组
/*
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0 )
            return 0;
        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size(), 0));
        res[0][0] = grid[0][0];
        for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid[0].size();j++)
            {
                if (i == 0 && j==0)
                    continue;
                if (i == 0)
                    res[i][j] = grid[i][j] + res[i][j-1];
                else if (j == 0)
                    res[i][j] = grid[i][j] + res[i-1][j];
                else
                {
                    res[i][j] = min(grid[i][j] + res[i][j-1],
                                    grid[i][j] + res[i-1][j]);
                }
            }
        }
        return res[grid.size()-1][grid[0].size()-1];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> t = {{1, 2, 3},
                             {4, 5, 6}};
    cout << s.minPathSum(t);
}
*/
//#include<omp.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>

using namespace std;


int SIZE;
int ThreadNum;

int* inArray;
int* outArray;

int timeBegin;
int timeEnd;

void init() {

    inArray = new int[SIZE];
    outArray = new int[SIZE];

    for (int i = 0; i < SIZE; i++) {
        inArray[i] = rand();
    }
}

void logout() {
    ofstream log("output.txt");
    log << "before:" << endl;
    for (int i = 0; i < SIZE; i++) {
        log << inArray[i]<<"\t";
    }
    log << endl;
    log << "after:" << endl;
    for (int i = 0; i < SIZE; i++) {
        log << outArray[i]<<"\t";
    }
    log << endl;
    log.close();
}
/*
int main() {
    while (true) {
        srand(time(NULL));

        cout << "input the size of array：";
        cin >> SIZE;
        init();

        int i, j, k;

        //并行部分
        para: {
        timeBegin = clock();
#pragma omp parallel for private(i, j, k)
        for (i = 0; i < SIZE; i++) {
            k = 0;
            for (j = 0; j < SIZE; j++) {
                if (inArray[i] > inArray[j] || inArray[i] == inArray[j] && i>j) {
                    k++;
                }
            }
            outArray[k] = inArray[i];
        }
        timeEnd = clock();
        cout << "para_time:\t" << timeEnd - timeBegin << endl;
        //logout();
    }

        //串行部分
        serial: {
        timeBegin = clock();
        for (i = 0; i < SIZE; i++) {
            k = 0;
            for (j = 0; j < SIZE; j++) {
                if (inArray[i] > inArray[j] || inArray[i] == inArray[j] && i>j) {
                    k++;
                }
            }
            outArray[k] = inArray[i];
        }
        timeEnd = clock();
        cout << "seri_time:\t" << timeEnd - timeBegin << endl;
        logout();
    }
        system("pause");
        system("cls");
    }
    return 0;
}
*/