#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
 	int n;
 	std::cin >> n;

 	std::vector<std::vector<int>> adj(n);
 	for (int i = 0; i < n - 1; i++) {
 		int u, v;
 		std::cin >> u >> v;
 		u--, v--;

 		adj[u].push_back(v);
 		adj[v].push_back(u);
 	}

 	std::vector<i64> sz(n + 1);
 	std::vector<i64> dp(n + 1);

 	auto dfs = [&](auto self, int u, int p) -> void {
 		sz[u] = 1;
 		i64 max = 0;
 		for (int v : adj[u]) {
 			if (v != p) {
 				self(self, v, u);
 				sz[u] += sz[v];

 				max = std::max(max, dp[v]);
 			}
 		}

 		dp[u] = sz[u] + max;
 	};

 	dfs(dfs, 0, -1);

 	std::cout << dp[0] << "\n";

    return 0;
}