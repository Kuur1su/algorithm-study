#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define Debug(x) { std::cerr << #x << " = " << x << '\n'; }

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> head(n, -1), to(m << 1), next(m << 1);
    vector<int> indegree(n);
    int id = 0;
    auto addEdge = [&](int u, int v) -> void {
        next[id] = head[u];
        to[id] = v;
        head[u] = id++;
    };

    for (int e = 0; e < m; e++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        addEdge(u, v);
        indegree[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        if (indegree[i]== 0) {
            pq.emplace(i);
        }
    }

    vector<int> ans;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans.emplace_back(u);
        for (int e = head[u]; e != -1; e = next[e]) {
            int v = to[e];
            if (--indegree[v] == 0) {
                pq.emplace(v);
            }
        }
    }

    if ((int)ans.size() != n) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
