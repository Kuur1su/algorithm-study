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

	std::vector<int> a(n);
	i64 ans = 0;
	i64 cur = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		cur += a[i];
	}

	cur /= n;

	for (int i = 0; i < n; i++) {
		if (a[i] > cur) {
			ans++;
		} 
	}

	std::cout << ans << "\n";

	return 0;
}