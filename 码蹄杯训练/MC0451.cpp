#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

constexpr int P = 998244353;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> p(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		p[i] = 2 * p[i - 1] % P;
	}

	std::unordered_map<int, i64> mp;
	i64 s = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		s = (2 * s - mp[x] + p[i - 1]) % P;
		mp[x] = (mp[x] + p[i - 1]) % P;
	}
	if (s < 0) {
		s += P;
	}
	std::cout << s << "\n";

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