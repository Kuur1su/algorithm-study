#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int n, p;
    std::cin >> n >> p;

    std::vector<int> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
    	inv[i] = (int) (p - (i64)inv[p % i] * (p / i) % p);
    }

    for (int i = 1; i <= n; i++) {
    	std::cout << inv[i] << "\n";
    }

    return 0;
}