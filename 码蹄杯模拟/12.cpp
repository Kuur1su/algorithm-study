#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_map<std::string, int> mp, mp2;

    int n;
    std::cin >> n;

    std::vector<std::string> S(n);
    for (int i = 0; i < n; i++){
        std::cin >> S[i];
        mp[S[i]] = 0;
        mp2[S[i]] = -1;
    }

    int m;
    std::cin >> m;

    while (m--) {
        int opt;
        std::string x;
        std::cin >> opt >> x;

        if (opt == 1) {
            int y;
            std::cin >> y;

            if (mp2[x] == -1) {
                mp[x] += y;                
            }
        } else {
            if (mp2[x] == -1) {
                std::cout << mp[x] << "\n";
            } else {
                std::cout << -1 << "\n";
            }
        }
    }

    return 0;
}