#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
	i64 a, b;
	std::cin >> a >> b;

	if ((a + b) % 2) {
		std::cout << "YES\n";
		return;
	}

	if (a % 2 == 0 && b % 2 == 0) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}

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