#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, t1, t2;
	std::cin >> n >> m >> t1 >> t2;

	std::vector G(n, std::vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> G[i][j];
		}
	}

	int h = n / t1;
	int l = m / t2;

	int ans = 0;

	for (int x = 0; x < h; x++) {
		for (int y = 0; y < l; y++) {
			int cur = 0;
			for (int i = t1 * x; i < t1 * (x + 1); i++) {
				for (int j = t2 * y; j < t2 * (y + 1); j++) {
					cur = cur ^ G[i][j];
				}
			}
			ans += cur;			
		}
	}

	std::cout << ans << "\n";

	return 0;
}