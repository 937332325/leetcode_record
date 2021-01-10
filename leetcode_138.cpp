//
// Created by 陈海斌 on 2020-09-27.
//

#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// https://leetcode-cn.com/problems/copy-list-with-random-pointer/solution/fu-zhi-dai-sui-ji-zhi-zhen-de-lian-biao-by-leetcod/
// O(N) 内存 O(N) 时间
class Solution {
public:
    map<Node*, Node*> map_node;
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        if (map_node.count(head) != 0)
            return map_node[head];
        Node* node = new Node(head->val);
        map_node.insert(pair<Node*, Node*>(head, node));
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        return node;
    }
};

class Solution2 {
public:
    map<Node*, Node*> map_node;
    Node* getCloned(Node* node)
    {
        // If the node exists then
        if (node != NULL) {
            // Check if the node is in the visited dictionary
            if (map_node.count(node)) {
                // If its in the visited dictionary then return the new node reference from the dictionary
                return map_node[node];
            } else {
                // Otherwise create a new node, add to the dictionary and return it
                map_node.insert(pair<Node*, Node*>(node, new Node(node->val)));
                return map_node[node];
            }
        }
        return NULL;
    }
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        Node *oldNode = head;

        // Creating the new head node.
        Node *newNode = new Node(oldNode->val);
        map_node.insert(pair<Node*, Node*>(oldNode, newNode));

        // Iterate on the linked list until all nodes are cloned.
        while (oldNode != NULL) {
            // Get the clones of the nodes referenced by random and next pointers.
            newNode->random = this->getCloned(oldNode->random);
            newNode->next = this->getCloned(oldNode->next);

            // Move one step ahead in the linked list.
            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        return map_node[head];
    }
};

class Solution3 {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        Node *ptr = head;

        while (ptr != NULL)
        {
            Node *newNode = new Node(ptr->val);
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = newNode->next;
        }
        ptr = head;
        while (ptr != NULL)
        {
            ptr->next->random = (ptr->random != NULL) ? ptr->random->next : NULL;
            ptr = ptr->next->next;
        }
        Node *ptr_old = head;
        Node *ptr_new = head->next;
        Node *head_old = head->next;
        while (ptr_old != NULL)
        {
            ptr_old->next = ptr_old->next->next;
            ptr_new->next = (ptr_new->next != NULL) ? ptr_new->next->next : NULL;
            ptr_old = ptr_old->next;
            ptr_new = ptr_new->next;
        }
        return head_old;
    }
};

/*
int main() {
    Solution s;

    Node *a = new Node(1);
    Node *b = new Node(2);
    a->next = b;
    a->random = b;
    b->random = b;
    Node *res = s.copyRandomList(a);
    cout << "finish" << endl;



    Node *a = new Node(7);
    Node *b = new Node(13);
    Node *c = new Node(11);
    Node *d = new Node(10);
    Node *e = new Node(1);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    b->random = a;
    c->random = e;
    d->random = c;
    e->random = a;
    Node *res2 = s.copyRandomList(a);
    cout << "finish2" << endl;

    for (double i = 0; i < 1+1e-6; i+=0.1)
        printf("%.8g\n", i);
}
*/