#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    std::vector<int> c(26);
    for (char t : s) {
        c[t - 'a']++;
    }

    std::vector<std::vector<int>> L(n, std::vector<int>(26));
    L[0][s[0] - 'a']++;

    for (int i = 1; i < n; i++) {
        L[i] = L[i - 1];
        L[i][s[i] - 'a']++;
    }

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;

        int ans = 0;

        for (int k = 0; k < 26; k++) {
            int cur = 0;
            cur = (L[r][k] - L[l][k] + (s[l] - 'a' == k));

            if (cur % 2) {
                ans++;
            }
        }

        std::cout << 26 - ans << " " << ans << "\n";
    }

    return 0;
}