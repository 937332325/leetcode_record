//
// Created by 陈海斌 on 2020-09-23.
//
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

//25分钟第一次提交 通过率149/187 bad case [2,-5,-2,-4,3]
//我的错误还是陈旧的从左到右保存正数最大和绝对值最大，没有考虑后面还有多少个小于0的数，当时觉得再改进代码就太复杂了，但没有想到
//其实应该保存的是最小值，然后可以根据下一个值的正负性进行分类讨论
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //0位置表示正 1位置表示负
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        int res = nums[0];
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(dp[i-1][0], dp[i-1][1]);
            dp[i][0] = max(dp[i-1][0]*nums[i], nums[i]);
            dp[i][1] = min(dp[i-1][1]*nums[i], nums[i]);
            int max_tmp = max(nums[i], dp[i][0]);
            res = max(res, max_tmp);
        }
        return res;
    }
    /*
     * 首先假设存在某个最大乘积，然后对数组遍历，在经过每个元素的时候，有以下四种情况：

如果该元素为正数：
如果到上一个元素为止的最大乘积也是正数，那么直接乘上就好了，同样的最大乘积也会变得更大
如果到上一个元素为止的最大乘积是负数，那么最大乘积就会变成该元素本身，且连续性被断掉
如果该元素为负数：
如果到上一个元素为止的最大乘积也是负数，那么直接乘上就好了，同样的最大乘积也会变得更大
如果到上一个元素为止的最大乘积是正数，那么最大乘积就会不变，且连续性被断掉
以上四种情况中说到的最大乘积都是临时最大乘积，每遍历新的元素都需要进行比较来确定真正的最大乘积。

如果细心的话就可以发现，如果要得到乘以当前元素以后的最大乘积，需要记录最大乘积，也要记录最小乘积，因为最小值可能翻身变最大值。
     */
    int maxProduct2(vector<int>& A) {
        // store the result that is the max we have found so far
        int r = A[0];

        // imax/imin stores the max/min product of
        // subarray that ends with the current number A[i]
        for (int i = 1, imax = r, imin = r; i < A.size(); i++) {
            // multiplied by a negative makes big number smaller, small number bigger
            // so we redefine the extremums by swapping them
            if (A[i] < 0)
                swap(imax, imin);

            // max/min product for the current number is either the current number itself
            // or the max/min by the previous number times the current one
            imax = max(A[i], imax * A[i]);
            imin = min(A[i], imin * A[i]);

            // the newly computed max value is a candidate for our global result
            r = max(r, imax);
        }
        return r;
    }
    //O(N) time O(1) space
    //
    /*
     * Let me try to give some explanations for this solution .

First, if there's no zero in the array, then the subarray with maximum product must start with the first element or end with the last element. And therefore, the maximum product must be some prefix product or suffix product. So in this solution, we compute the prefix product A and suffix product B, and simply return the maximum of A and B.

Why? Here's the proof:

Say, we have a subarray A[i : j](i != 0, j != n) and the product of elements inside is P. Take P > 0 for example: if A[i] > 0 or A[j] > 0, then obviously, we should extend this subarray to include A[i] or A[j]; if both A[i] and A[j] are negative, then extending this subarray to include both A[i] and A[j] to get a larger product. Repeating this procedure and eventually we will reach the beginning or the end of A.

What if there are zeroes in the array? Well, we can split the array into several smaller ones. That's to say, when the prefix product is 0, we start over and compute prefix profuct from the current element instead. And this is exactly what A[i] *= (A[i - 1]) or 1 does.
     */
    /*
 * 思路： 求最大值，可以看成求被0拆分的各个子数组的最大值。

当一个数组中没有0存在，则分为两种情况：

1.负数为偶数个，则整个数组的各个值相乘为最大值；

2.负数为奇数个，则从左边开始，乘到最后一个负数停止有一个“最大值”，从右边也有一个“最大值”，比较，得出最大值。
 */
    int maxProduct3(vector<int> A) {
        int n = A.size(), res = A[0], l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            l =  (l ? l : 1) * A[i];
            r =  (r ? r : 1) * A[n - 1 - i];
            res = max(res, max(l, r));
        }
        return res;
    }

};

/*
int main()
{
    Solution s;
    vector<int> d = {2,-5,-2,-4,3};
    cout << s.maxProduct(d) << endl;
    vector<int> a = {-2,-3,-2,-4};
    cout << s.maxProduct(a) << endl;
    vector<int> b = {2,3,-2,4};
    cout << s.maxProduct(b) << endl;
    vector<int> c = {-2,3,-2,4,5,-6,-2};
    cout << s.maxProduct(c) << endl;
}
 */