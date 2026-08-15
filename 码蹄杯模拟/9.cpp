#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;


    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> grid[i][j];
        }
    }

    int q;
    std::cin >> q;

    while (q--) {
        int opt, x, k;
        std::cin >> opt >> x >> k;
        x--;

        std::vector<int> cur(m);

        if (opt == 1) {
            for (int i = 0; i < m; i++) {
                cur[(i - k + (k / m + 1) * m) % m] = grid[x][i];
            }
            grid[x] = cur;
        } else {
            for (int i = 0; i < m; i++) {
                cur[(i + k) % m] = grid[x][i];
            }
            grid[x] = cur;
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << grid[i][j] << " \n"[j == m - 1];
        }
    }
    std::cout << "\n";

    return 0;
}