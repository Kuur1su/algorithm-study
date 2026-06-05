#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
	int n;
	std::cin >> n;

	int eor = 0;
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		eor ^= a;
	}
	if (eor != 0) {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;

    while (t--) {
    	solve();
    }

    return 0;
}