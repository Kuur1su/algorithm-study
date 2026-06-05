#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

constexpr int P = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    i64 ans = 1;

    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];

    	ans = (ans * (a[i] + 1)) % P;	
    }

    std::cout << ans - 1 << "\n";

    return 0;
}