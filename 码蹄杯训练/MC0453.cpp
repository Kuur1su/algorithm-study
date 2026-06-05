#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin(), a.end());

	for (int i = 0; i < n - k + 1; i++) {
		int cur = 0;
		for (int j = i; j < i + k - 1; j++) {
			cur += a[j];
		}

		if (cur > a[i + k - 1]) {
			std::cout << "YES\n";
			return;
		}
	}

	std::cout << "NO\n";
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