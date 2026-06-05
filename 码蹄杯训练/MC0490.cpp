#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, q;
	std::cin >> n >> m >> q;

	std::vector<std::string> G(m);
	for (int i = 0; i < m; i++) {
		std::cin >> G[i];
	}

	std::vector<std::string> nG = G;
	auto r = [&]() -> void {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				nG[i][j] = G[m - j - 1][i];
			}
		}
		G = nG;
	};

	std::vector M(n, std::vector<int>(n));

	while (q--) {
		int op;
		std::cin >> op;

		if (op == 1) {
			r();
		} else {
			int x, y;
			std::cin >> x >> y;
			x--, y--;

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					if (G[i][j] == '#') {
						if (x + i < n && y + j < n) {
							M[x + i][y + j]++;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << M[i][j] << " \n"[j == n - 1];
		}
	}

	return 0;
}