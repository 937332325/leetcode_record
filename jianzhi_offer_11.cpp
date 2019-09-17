//
// Created by 陈海斌 on 2019-09-04.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // O(n)
    int minNumberInRotateArray_vector(vector<int> rotateArray) {
        if (rotateArray.size()==0) return 0;
        int min = rotateArray[0];
        int location = 0;
        for (int i=0;i<rotateArray.size();i++)
        {
            if (rotateArray[i]<min)
            {
                min = rotateArray[i];
                break;
            }
        }
        return min;
    }
    // O(log n)
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size()==0) return 0;
        int min_val = rotateArray[0];
        int begin = 0, end = rotateArray.size()-1;
        while (begin < end)
        {
            if (rotateArray[begin] < rotateArray[end])
                return rotateArray[begin];
            int middle = (begin + end) / 2;
            if (rotateArray[middle] > min_val)
                begin = middle + 1;
            else if (rotateArray[middle] < min_val)
                end = middle;
            else
                begin++;
        }
        return rotateArray[begin];
    }
};

/*
int main()
{
    Solution s;
    vector<int> a = { 1, 2, 3, 4, 5 };
    cout << s.minNumberInRotateArray(a);
}
*/