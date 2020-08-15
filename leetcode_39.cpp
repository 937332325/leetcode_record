//
// Created by 陈海斌 on 2020-08-15.
//

#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 1. candidate赋值1
 * 2. 每个值为所有子因数值的和，且可重复
 */
class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int> &now, int &value, int target, vector<int> candidates, int index)
    {
        if (value == target)
        {
            res.push_back(now);
        }
        else if (value > target)
            return;
        else
        {
            for (int i=index; i<candidates.size();i++)
            {
                now.push_back(candidates[i]);
                value += candidates[i];
                dfs(res, now, value, target, candidates, i);
                now.pop_back();
                value -= candidates[i];
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> now;
        int value = 0;
        for (int i = 0; i < candidates.size(); i++) {
            now.clear();
            now.push_back(candidates[i]);
            value = candidates[i];
            dfs(res, now, value, target, candidates, i);
        }
        return res;
    }
    vector<vector<int>> combinationSum_dp_increment(vector<int> &candidates, int target);
};

//dp写法
vector<vector<int>> Solution::combinationSum_dp_increment(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>());
    dp[0].push_back(vector<int>());

    for (const int &candidate : candidates) {
        // all the existing combinations, except for those whose sum exceeds target
        for (int sub_target = 0; sub_target + candidate <= target; ++sub_target){
            vector<vector<int>> new_combinations = dp[sub_target];
            for (vector<int> &new_combination: new_combinations) {  // append a candidate
                new_combination.push_back(candidate);
            }
            int target_yielded = sub_target + candidate;  // the target yielded
            dp[target_yielded].insert(dp[target_yielded].end(), new_combinations.begin(), new_combinations.end());
        }
    }

    return dp[target];
}

int main() {
    Solution s;
    vector<int> candidates = {2,3,5};
    int target = 8;
    vector<vector<int>> res = s.combinationSum(candidates, target);
    for (int i=0;i<res.size();i++)
    {
        for (int j=0;j<res[i].size();j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    vector<vector<int>> res2 = s.combinationSum_dp_increment(candidates, target);
}