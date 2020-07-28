//
// Created by 陈海斌 on 2020-06-26.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses==1)
            return true;
        if (prerequisites.size()==0)
            return true;
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, INT16_MAX));
        vector<int> distance(numCourses, INT16_MAX);
        vector<int> start;
        for (int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][1]][prerequisites[i][0]] = 1;
            if (graph[prerequisites[i][0]][prerequisites[i][1]]!=INT16_MAX)
            {
                graph[prerequisites[i][1]][prerequisites[i][0]] = 0;
                graph[prerequisites[i][0]][prerequisites[i][1]] = 0;
            }
            distance[prerequisites[i][0]] = INT16_MAX - 1;
            start.push_back(prerequisites[i][1]);
        }
        // 是否存在路径 dijkstra算法 记录路径
        for (int s=0;s<start.size();s++) {
            int start_point = start[s];
            vector<vector<int>> edge(numCourses, vector<int>(numCourses, 0));
            vector<int> visit(numCourses, 0);
            vector<int> path(numCourses, -1);
            // 初始化第一个点
            for (int i = 0; i < numCourses; i++) {
                if (graph[start_point][i] != 0)
                    distance[i] = graph[start_point][i];
            }
            visit[start_point] = 1;
            for (int i = 1; i < numCourses; i++) {
                int min_value = INT16_MAX;
                int min_index = 0;
                // 寻找最近顶点
                for (int j = 1; j < numCourses; j++) {
                    if (visit[j] == 0 && distance[j] < min_value) {
                        min_value = distance[j];
                        min_index = j;
                    }
                }
                visit[min_index] = 1;
                for (int k = 0; k < numCourses; k++) {
                    if (distance[min_index] + graph[min_index][k] < distance[k]) {
                        if (graph[k][0] != 0)
                            continue;
                        int tmp = k;
                        int flag = 0;
                        path[k] = min_index;
                        while (path[tmp] != -1) {
                            if (graph[tmp][0] != 0)
                                flag = 1;
                            tmp = path[tmp];
                        }
                        if (flag == 1) {
                            path[k] = -1;
                            continue;
                        }
                        distance[k] = distance[min_index] + graph[min_index][k];
                    }
                }
            }
            int flag = 1;
            for (int i = 0; i < numCourses; i++) {
                if (distance[i] == INT16_MAX)
                    flag = 0;
            }
            if (flag==1)
                return true;
        }
        return false;
    }
};
*/

class Solution {
public:
    bool DFS(vector<vector<int>>& graph, vector<int>& visit, int i, vector<int>& connect)
    {
        if (visit[i]==-1)
            return false;
        if (visit[i]==1)
            return true;
        visit[i] = -1;
        for (int j = 0; j < graph.size(); j++)
        {
            if (graph[i][j] != -1)
            {
                connect[j] = 1;
                if (!DFS(graph, visit, j, connect))
                    return false;
            }
        }
        visit[i] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses==1 || prerequisites.size()==0)
            return true;
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, -1));
        vector<int> visit(numCourses);
        // 这个题可能没这个意思，万一要检查是否走完了整个图
        vector<int> connect(numCourses);
        for (int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][1]][prerequisites[i][0]] = 1;
        }
        // 查找不符合的环
        for (int i = 0; i < numCourses; i++) {
            if (!DFS(graph, visit, i, connect))
                return false;
        }
        for (int i = 0; i < numCourses; i++) {
            if (connect[i] == 0)
                return false;
        }
        return true;
    }
};
/*
int main()
{
    Solution s;
    //vector<vector<int>> a = {{0, 1}};
    //cout << s.canFinish(2, a);
    vector<vector<int>> a = {{1, 2}};
    cout << s.canFinish(3, a);
}
*/