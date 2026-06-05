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
 	
    int n, q;
    std::cin >> n >> q;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    }

    std::vector<i64> diff(n + 1);
    diff[1] = a[0];
    for (int i = 2; i <= n; i++) {
    	diff[i] = (diff[i - 1] + a[i - 1]) % P;
    }

    std::vector<i64> diff_2(n + 2);
    for (int i = 1; i <= n + 1; i++) {
    	diff_2[i] = (diff_2[i - 1] + diff[i - 1]) % P;
    }

    while (q--) {
    	int l, r;
    	std::cin >> l >> r;

    	std::cout << (1LL * (r - l + 1) * diff[r] - diff_2[r] + diff_2[l - 1] + P) % P << "\n";
    }

    return 0;
}