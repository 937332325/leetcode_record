//
// Created by 陈海斌 on 2019-09-11.
//

#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 本部分主要是熟悉map的一些api
// map 红黑树 默认根据key排序 而unordered_map是用哈希表
// 查找借助的是algorithm的find api 用iterator来操作（同insert和erase）

// 思路:O(1)的插入查询->map  需要值的两端操作 使用list来存放已插入的值 如果要用时间换空间 就给每个value加上一个优先值
// 每次有新值或旧值更新就赋为1 其他+1
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = my_cache.find(key);
        if (it == my_cache.end())
            return -1;
        vector<pair<int, int>>::iterator i = find(l.begin(), l.end(), make_pair(key, it->second));
        l.erase(i);
        l.insert(l.begin(), make_pair(key, it->second));
        return it->second;
    }

    void put(int key, int value) {
        auto it = my_cache.find(key);
        if (it != my_cache.end())
        {
            vector<pair<int, int>>::iterator i = find(l.begin(), l.end(), make_pair(key, it->second));
            l.erase(i);
        }
        my_cache[key] = value;
        l.insert(l.begin(), make_pair(key, value));
        if (my_cache.size() > cap)
        {
            pair<int, int> p = l.back();
            l.pop_back();
            my_cache.erase(p.first);
        }
    }
private:
    vector<pair<int, int>> l;
    unordered_map<int, int> my_cache;
    int cap;
};

/*
int main() {
    LRUCache *cache = new LRUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << " ";       // returns 1
    cache->put(3, 3);    // evicts key 2
    cout << cache->get(2) << " ";       // returns -1 (not found)
    cache->put(4, 4);    // evicts key 1
    cout << cache->get(1) << " ";       // returns -1 (not found)
    cout << cache->get(3) << " ";       // returns 3
    cout << cache->get(4) << " ";       // returns 4
}
*/