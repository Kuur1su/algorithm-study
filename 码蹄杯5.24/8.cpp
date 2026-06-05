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

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	while (m--) {
		int L;
		std::cin >> L;
		std::unordered_map<int, int> num;

		int cur = 0;
		for (int i = 0; i < L; i++) {
			if (num[a[i]] == 0) {
				cur++;				
			}
			num[a[i]]++;
		}

		int ans = cur;
		for (int i = L; i < n; i++) {
			if (num[a[i]] == 0) {
				cur++;
			}
			num[a[i]]++;
			num[a[i - L]]--;
			if (num[a[i - L]] == 0) {
				cur--;
			}
			// std::cerr << cur << "! ";
			ans += cur;
		}

		std::cout << ans << "\n";

	}


	return 0;
}