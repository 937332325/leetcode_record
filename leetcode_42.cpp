//
// Created by 陈海斌 on 2020-08-19.
//

#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int exist_localmax(vector<int>& height, int j, int tmp)
    {
        int max_v = 0;
        while (j<height.size())
        {
            if (height[j] > tmp)
                max_v = max(max_v, height[j]);
            j += 1;
        }
        return max(tmp, max_v);
    }
    int trap(vector<int>& height) {
        if (height.size()==0)
            return 0;
        int total = 0;
        int before = height[0];
        int accumulate = 0;
        int local_max = 0;
        int i = 0;
        while (i < height.size())
        {
            if (height[i] >= local_max)
            {
                local_max = height[i];
            }
            else
            {
                int next_max = exist_localmax(height, i, height[i]);
                if (next_max > height[i] && next_max >= local_max)
                    total = total + local_max - height[i];
                else if (next_max > height[i] && next_max < local_max)
                    total = total + next_max - height[i];
                else if (next_max==local_max && height[i] != local_max)
                    total = total + local_max - height[i];
                else
                    local_max = height[i];
            }
            i += 1;
        }
        return total;
    }
};
/*
int main()
{
    Solution s;
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(a) << endl;
    vector<int> b = {2,0,2};
    cout << s.trap(b) << endl;
    vector<int> c = {4,2,3};
    cout << s.trap(c) << endl;
}
 */