#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
	int n;
	i64 m;
	std::cin >> n >> m;

	std::vector<int> a(n);
	int max = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		max = std::max(max, a[i]);
	}

	auto check = [&](int D) -> bool {
		i64 cur = 0;
		for (int i = 0; i < n; i++) {
			cur += (a[i] / D);
		}
		return cur <= m;
	};

	int l = 1, r = max + 1;
	int ans = r;

	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	std::cout << ans << "\n";
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