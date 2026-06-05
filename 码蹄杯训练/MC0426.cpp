#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector G(26, std::vector<bool>(26, false));

	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;

		int u = s.front() - 'a';
		int v = s.back() - 'a';

		G[u][v] = true;
	}

	for (int k = 0; k < 26; k++) {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				if (G[i][k] && G[k][j]) {
					G[i][j] = true;
				}
			}
		}
	}

	while (q--) {
		char x, y;
		std::cin >> x >> y;

		int st = x - 'a';
		int ed = y - 'a';

		if (G[st][ed]) {
			std::cout << "Yes\n";
		} else {
			std::cout << "No\n";
		}
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
    int T;
    std::cin >> T;

    while (T--) {
    	solve();
    }

    return 0;
}