#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

constexpr int P = 1E9 + 7;
constexpr int M = 2E5 + 5;

i64 qmi(i64 a, i64 k) {
    i64 res = 1;
    while (k) {
        if (k & 1) res = res * a % P;
        a = a * a % P;
        k >>= 1;
    }
    return res;
}

i64 inv(i64 a) {
	return qmi(a, P - 2);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
    i64 n, m;
    std::cin >> n >> m;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    }

    std::sort(a.begin(), a.end(), std::greater<>());

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
    	i64 E = std::min(a[i], m);

    	i64 term = (m % P) * inv(E) % P;
    	ans = (ans + term) % P;
    }

    std::cout << ans << "\n";

    return 0;
}