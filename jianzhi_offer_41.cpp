//
// Created by 陈海斌 on 2019-09-08.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 容易想到的 O(nlog n)排序
    // 本来自己一开始是想实现这个的 最大堆容器放k个 但是后来考虑到k的数量可能很大 就没先实现了
    // 当然剑指offer提示了这么做比较适合海量数据
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k<=0 || input.size() == 0 || k>input.size())
        {
            return res;
        }
        //自动排序
        make_heap(res.begin(), res.end(), less<int>());
        for (int i=0; i<input.size();i++)
        {
            //对数组和priority_queue操作
            res.push_back(input[i]);
            push_heap(res.begin(), res.end(), less<int>());
            if (res.size() > 4)
            {
                pop_heap(res.begin(), res.end(), less<int>());
                //pop后放在数组的back
                res.pop_back();
            }
        }
        return res;
    }
    // 用快速排序的O(n)换位 自己的主要问题是对快速排序不够熟悉 调试了挺久
    /*
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k<=0 || input.size() == 0 || k>input.size())
        {
            vector<int> empty;
            return empty;
        }
        int index = partition(input, 0, input.size()-1);
        while (index != k-1)
        {
            if (index > k-1)
            {
                index = partition(input, 0, index-1);
            }
            else
            {
                index = partition(input, index+1, input.size()-1);
            }
        }
        vector<int> res(k, 0);
        for (int i=0; i<k; i++)
            res[i] = input[i];
        return res;
    }

    int partition(vector<int> &input, int start, int end)
    {
        if (start >= end)
        {
            cout << "begin >= end" << endl;
            return end;
        }
        int index = start + rand() % (end-start);
        int x = input[index];
        swap(input[index], input[start]);
        while (start < end)
        {
            while (start < end && input[end] >= x)
                end--;
            if (start < end)
                input[start++] = input[end];
            while (start < end && input[start] < x)
                start++;
            if (start < end)
                input[end--] = input[start];
        }
        input[start] = x;
        return start;
    }
     */
};

/*
int main()
{
    Solution s;
    vector<int> a = {4,5,1,6,2,7,3,8};
    vector<int> res = s.GetLeastNumbers_Solution(a, 5);
    cout << res[0] << " " << res[1] << " " << res[2];
}
*/