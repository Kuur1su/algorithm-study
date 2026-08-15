#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n;
    std::cin  >> n;

    while (n--) {
        std::string t;
        std::cin >> t;

        for (int i = 0, j = 0; i <= t.size() && j <= s.size(); j++) {
            if (t[i] == s[j]) {
                i++;
            }

            if (i == t.size()) {
                std::cout << "YES\n";
                break;
            }

            if (j == s.size()) {
                std::cout << "NO\n";
                break;
            }
        }
    }

    return 0;
}