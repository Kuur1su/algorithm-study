#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define Debug(x) { std::cerr << #x << " = " << x << '\n'; }

void solve() {
    int n;
    cin >> n;

    // 邻接矩阵方式建图
    vector<vector<int>> graph1(n, vector<int>(n));

    // 邻接表方式建图
    vector<vector<pair<int, int>>> graph2(n);

    // 链式前向星建图
    int cnt = 0;
    vector<int> head(n), next(n << 1), to(n << 1), weight(n << 1);

    auto addEdge = [&](int u, int v, int w) -> void {
        next[cnt] = head[u];
        to[cnt] = v;
        weight[cnt] = w;
        head[u] = cnt++;
    };

    // 三种方式建立有向图带权图
    auto directGraph = [&](vector<vector<int>> edges) -> void {
        for (auto edge : edges) {
            graph1[edge[0]][edge[1]] = edge[2];
        }

        for (auto edge : edges) {
            graph2[edge[0]].emplace_back(edge[1], edge[2]);
        }

        for (auto edge : edges) {
            addEdge(edge[0], edge[1], edge[2]);
        }
    };
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
