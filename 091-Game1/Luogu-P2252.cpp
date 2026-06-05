#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

constexpr long double PHI = (1.0 + sqrtl(5.0)) / 2.0;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int a, b;
    std::cin >> a >> b;

    int minn = std::min(a, b);
    int maxn = std::max(a, b);

    if (minn == (int) (PHI * (maxn - minn))) {
    	std::cout << 0 << "\n";
    } else {
    	std::cout << 1 << "\n";
    }

    return 0;
}