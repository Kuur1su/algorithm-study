#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n, x;
    std::cin >> n >> x;

    int ans = n;

    for (int i = n; i > 0; i--){
        if (i < x && 2 * i > x) {
            ans--;
        }
    }

    std::cout << ans << "\n";

    for (int i = 0, j = 1; i < ans; i++) {
        while (j < x && 2 * j > x) {
            j++;
        }
        std::cout << j << " \n"[i == ans - 1];
        j++;
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}