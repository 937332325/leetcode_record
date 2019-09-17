//
// Created by 陈海斌 on 2019-09-04.
//
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.size() == 0)
        {
            while (stack1.size()>0)
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.size() == 0)
            return 0;
        int res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
