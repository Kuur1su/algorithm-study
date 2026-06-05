#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

i64 MOD = 1e9 + 7;

template <class T>
constexpr T power(T a, u64 b, T res = 1) {
	a %= MOD;
	for (; b != 0; b /= 2, a = (a * a) % MOD) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
	}
	return res;
}

void solve() {
	i64 a, b;
	std::cin >> a >> b;

	i64 ans = power(a, b) ;

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