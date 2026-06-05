#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::string> G(n);
	for (int i = 0; i < n; i++) {
		std::cin >> G[i];
	}

	std::vector<int> ans(n);

	while (m--) {
		std::string s;
		std::cin >> s;

		for (int i = 0; i < n; i++) {
			bool ok = true;
			for (int j = 0; j < s.size(); j++) {
				if (G[i][j] != s[j]) {
					ok = false;
				}
			}

			// std::cerr << m << "! ";
			if (ok) {
				ans[i]++;
				// std::cerr << i << "! ";
			}
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << ans[i] << " \n"[i == n - 1];
	}

	return 0;
}