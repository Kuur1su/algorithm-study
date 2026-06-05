#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	int ans = 0;
	int max = -1;

	std::vector<int> stk;
	stk.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		while (!stk.empty() && a[i] > stk.back()) {
			max = std::max(max, stk.back());			
			stk.pop_back();
			// std::cerr << ans << "!\n";
		}
		stk.push_back(a[i]);
	}

	for (auto e : stk) {
		if (e >= max) {
			ans++;
		}
	}

	std::cout << n - ans << "\n";

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
