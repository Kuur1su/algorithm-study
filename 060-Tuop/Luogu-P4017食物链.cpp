#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define Debug(x) { std::cerr << #x << " = " << x << '\n'; }

constexpr int mod = 80112002;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> head(n + 1, -1), next(m << 1), to(m << 1);
    vector<int> indegree(n + 1), times(n + 1);
    int id = 1;
    auto addEdge = [&](int u, int v) -> void {
        next[id] = head[u];
        to[id] = v;
        head[u] = id++;
        indegree[v]++;
    };

    while (m--) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            times[i]++;
            q.emplace(i);
        }
    }

    int ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (head[u] == -1) {
            ans = (ans + times[u]) % mod;
        }
        for (int e = head[u]; e != -1; e = next[e]) {
            int v = to[e];
            times[v] = (times[v] + times[u]) % mod;
            if (--indegree[v] == 0) {
                q.emplace(v);
            }
        }
    }

    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
