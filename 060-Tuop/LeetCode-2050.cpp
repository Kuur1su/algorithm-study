#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int m = relations.size();

        vector<int> head(n + 1, -1), next(m), to(m);
        vector<int> indegree(n + 1);
        int id = 0;
        auto addEdge = [&](int u, int v) -> void {
            next[id] = head[u];
            to[id] = v;
            head[u] = id++;
            indegree[v]++;
        };


        for (int i = 0; i < m; i++) {
            addEdge(relations[i][0], relations[i][1]);
        }

        vector<int> cost(n + 1);
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                cost[i] = time[i - 1];
                q.emplace(i);
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans = max(ans, cost[u]);
            for (int e = head[u]; e != -1; e = next[e]) {
                int v = to[e];
                cost[v] = max(cost[v], cost[u] + time[v - 1]);
                if (--indegree[v] == 0) {
                    q.emplace(v);
                }
            }
        }

        return ans;
    }
};
