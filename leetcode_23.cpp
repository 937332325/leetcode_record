//
// Created by 陈海斌 on 2020-01-24.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

/*
Input:
[
1->4->5,
1->3->4,
2->6
]
Output: 1->1->2->3->4->4->5->6
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//我的思路是每一轮找出最小的那个链表值 O(n^3) 没意识到这是个分而治之的问题
/*
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int min_val = INT32_MAX;
        int min_index = -1;
        ListNode* res = new ListNode(-1);
        ListNode* prev = new ListNode(-1);
        ListNode* head = prev;
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int i=0; i<lists.size(); i++)
            {
                if (lists[i] != NULL)
                {
                    flag = true;
                    if (lists[i]->val < min_val)
                    {
                        min_val = lists[i]->val;
                        min_index = i;
                    }
                }
                else
                    continue;
            }
            if (flag == true)
            {
                prev->next = new ListNode(0);
                prev = prev->next;
                prev->val = min_val;
                prev->next = NULL;

                res->next = new ListNode(0);
                res->val = min_val;
                res = res->next;
                lists[min_index] = lists[min_index]->next;
                min_index = -1;
                min_val = INT32_MAX;
            }
        }
        return head->next;
    }
};
*/
// write in iterative merge sort
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *a1, ListNode *a2)
    {
        if (a1 == NULL)
            return a2;
        if (a2 == NULL)
            return a1;
        if(a1->val <= a2->val){
            a1->next = mergeTwoLists(a1->next, a2);
            return a1;
        }
        else{
            a2->next = mergeTwoLists(a1, a2->next);
            return a2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int now_len = lists.size();
        while (now_len > 1) {
            for (int i = 0; i < now_len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[now_len - 1 - i]);
            }
            now_len = (now_len + 1) / 2;
        }
        return lists.front();
    }
};
/*
int main()
{
    Solution s;
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(4);
    ListNode *c = new ListNode(5);
    a->next = b;
    b->next = c;
    ListNode *d = new ListNode(1);
    ListNode *e = new ListNode(3);
    ListNode *f = new ListNode(4);
    d->next = e;
    e->next = f;
    ListNode *g = new ListNode(2);
    ListNode *h = new ListNode(6);
    g->next = h;
    vector<ListNode*> v;
    v.insert(v.end(), a);
    v.insert(v.end(), d);
    v.insert(v.end(), g);
    d = s.mergeKLists(v);
    // cout << d << endl;
    while (d != NULL)
    {
        cout << d->val << endl;
        d = d->next;
    }
}
*/

/* write in priority queue
struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
ListNode *mergeKLists(vector<ListNode *> &lists) { //priority_queue
    priority_queue<ListNode *, vector<ListNode *>, compare> q;
    for(auto l : lists) {
        if(l)  q.push(l);
    }
    if(q.empty())  return NULL;

    ListNode* result = q.top();
    q.pop();
    if(result->next) q.push(result->next);
    ListNode* tail = result;
    while(!q.empty()) {
        tail->next = q.top();
        q.pop();
        tail = tail->next;
        if(tail->next) q.push(tail->next);
    }
    return result;
}
*/