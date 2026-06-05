#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, q;
	std::cin >> n >> q;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	while (q--) {
		int l, r;
		std::cin >> l >> r;
		l--;

		std::vector<int> b;
		bool ok = 0;

		for (int i = l; i < r; i++) {
			auto it = std::upper_bound(b.begin(), b.end(), a[i]);

			if (it == b.end()) {
				b.push_back(a[i]);
			} else {
				*it = a[i];
			}

			if (b.size() == 3) {
				ok = 1;
				break;
			}
		}

		if (ok) {
			std::cout << "Yes\n";
		} else {
			std::cout << "No\n";
		}
	}

	return 0;
}