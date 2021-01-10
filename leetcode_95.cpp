//
// Created by 陈海斌 on 2020-08-26.
//

#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> traverse(int left, int right) {
        vector<TreeNode*> res;
        if (left > right)
        {
            // 没想到这个
            res.push_back(nullptr);
            return res;
        }
        for (int i=left; i<=right; i++)
        {
            vector<TreeNode*> left_child = traverse(left, i-1);
            vector<TreeNode*> right_child = traverse(i+1, right);
            for (int j=0; j<left_child.size(); j++)
            {
                for (int k=0; k<right_child.size(); k++)
                {
                    TreeNode *tmp = new TreeNode(i);
                    tmp->left = left_child[j];
                    tmp->right = right_child[k];
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>(0);
        return traverse(1,n);
    }
};

/*
int main()
{
    Solution s;
    vector<TreeNode*> a = s.generateTrees(3);
    cout << "finish";
}
 */