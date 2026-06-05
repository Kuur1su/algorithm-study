#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

constexpr int P = 998244353;

template <class T>
constexpr T power(T a, u64 b, T res = 1) {
    for (; b != 0; b /= 2, a *= a) {
        if (b & 1) {
            res *= a;
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    	
    int n;
    std::cin >> n;

    std::map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;

        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                int cnt = 0;
                while (x % j == 0) {
                    x /= j;
                    cnt++;
                }
                mp[j] = std::max(mp[j], cnt);
            }
        }

        if (x > 1) {
            mp[x] = std::max(mp[x], 1);
        }
    }

    i64 ans = 1;
    for (auto p : mp) {
        ans = 1LL * (ans * power(p.first, p.second)) % P; 
    }

    std::cout << ans << "\n";

    return 0;
}







