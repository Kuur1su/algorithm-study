#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

constexpr int P = 998244353;

i64 qmi(i64 a, i64 k) {
    i64 res = 1;
    while (k) {
        if (k & 1) res = res * a % P;
        a = a * a % P;
        k >>= 1;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
    int n;
    std::cin >> n;

    i64 ans = qmi(26, n);

    ans = (ans - 3 * qmi(25, n) + P) % P;
    ans = (ans + 3 * qmi(24, n) + P) % P;
    ans = (ans - qmi(23, n) + P) % P;

    std::cout << ans << "\n";

    return 0;
}