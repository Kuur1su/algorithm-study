#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
    i64 n, k;
    std::cin >> n >> k;

    i64 s = std::sqrt(n);
    if (s * s < n) {
    	s++;
    }

    i64 x = (k - 1) / s + 1;
    i64 y = (k - 1) % s + 1;

    std::cout << x  <<  " " << y << "\n";

    return 0;
}