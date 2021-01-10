//
// Created by 陈海斌 on 2020-08-17.
//

#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

//Your algorithm should run in O(n) time and uses constant extra space.
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int res = 1;
        if (nums.size() == 0)
            return 1;
        vector<int> dp(nums.size()+1, 0);
        bool used = false;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] > 0 && nums[i] < nums.size()+1)
                dp[nums[i]] += 1;
        }
        for (int i=1; i<nums.size()+1; i++)
        {
            if (dp[i] == 0)
            {
                res = i;
                used = true;
                break;
            }
        }
        if (!used)
            return nums.size() + 1;
        return res;
    }
};

/*
Put each number in its right place.
For example:
When we find 5, then swap it with A[4].
At last, the first place where its number is not right, return the place + 1.

//nice的地方在于第二个while 总的次数也是O(n0
class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);

        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};
*/

/*
int main()
{
    Solution s;
    vector<int> a = {1,2};
    cout << s.firstMissingPositive(a) << endl;
}
 */