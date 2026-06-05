#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define Debug(x) { std::cerr << #x << " = " << x << '\n'; }

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> head(n + 1, -1), to(m << 1), next(m << 1);
    vector<int> indegree(n);
    int cnt = 0;
    auto addEdge = [&](int u, int v) -> void {
        next[cnt] = head[u];
        to[cnt] = v;
        head[u] = cnt++;
    };

    while (m--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        addEdge(u, v);
        indegree[v]++;
    }

    vector<int> order;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            order.emplace_back(i);
        }
    }

    for (int i = 0; i < (int)order.size(); i++) {
        int u = order[i];
        for (int e = head[u]; e != -1; e = next[e]) {
            int v = to[e];
            if (--indegree[v] == 0) {
                order.emplace_back(v);
            }
        }
    }
    if (order.size() == n) {
        for (int i = 0; i < n; i++) {
            cout << order[i] + 1 << " \n"[i == n - 1];
        }
        return;
    }
    cout << -1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
