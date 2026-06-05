#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

constexpr int P = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int n;
    std::cin >> n;

    std::string a;
    std::cin >> a;

    i64 ans = 0;
    i64 sum = 0;

    for (int y = 0; y < n; y++) {
    	if (a[y] == '1') {
    		sum = (sum + y + 1) % P;
    	} else if (a[y] == '0') {
    		i64 cur = (sum * (n - y)) % P;
    		ans = (ans + cur) % P;
    	}
    }

    std::cout << ans << "\n";

    return 0;
}