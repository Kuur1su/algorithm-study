#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
	int N;
	std::cin >> N;

	int sum = 0;
	int eor = 0;
	for (int i = 0; i < N; i++) {
		int a;
		std::cin >> a;
		sum += a;
		eor ^= a;
	}

	if (sum == N) {
		std::cout << (sum & 1 ? "Brother\n" : "John\n");
	} else {
		std::cout << (eor == 0 ? "Brother\n" : "John\n");
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