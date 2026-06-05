#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr int inf = 1e9;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int m = richer.size();
        int n = quiet.size();

        vector<int> head(n, -1), next(m), to(m);
        vector<int> indegree(n);
        int id = 0;
        auto addEdge = [&](int u, int v) -> void {
            next[id] = head[u];
            to[id] = v;
            head[u] = id++;
            indegree[v]++;
        };

        for (int i = 0; i < m; i++) {
            addEdge(richer[i][0], richer[i][1]);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.emplace(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int e = head[u]; e != -1; e = next[e]) {
                int v = to[e];
                quiet[v] = min(quiet[u], quiet[v]);
                if (--indegree[v] == 0) {
                    q.emplace(v);
                }
            }
        }

        return quiet;
    }
};
