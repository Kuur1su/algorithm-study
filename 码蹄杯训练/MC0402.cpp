#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
	std::string s;
	std::cin >> s;

	int l = 0, r = 0;

	i64 ans = 0;

	for (char c : s) {
		if (c == '(') {
			if (r != 0) {
				ans += r;	
				r--;
			} else {
				l++;
			}
		} else {
			if (l != 0) {
				l--;
			} else {
				r++;
			}
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