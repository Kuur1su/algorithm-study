#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
    	std::cin >> a[i];
    }

    int ans = 0;
    for (int i = 1; i <= (n / k); i++) {
    	ans += a[i * k];
    }

    std::cout << ans << "\n";

    return 0;
}