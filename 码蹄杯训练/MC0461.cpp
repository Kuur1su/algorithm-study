#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;

    int tot = n;
    std::vector<std::pair<int, int>> a;

    while (n--) {
        int opt;
        std::cin >> opt;

        int l, r;
        if (opt == 1) {
            int x;
            std::cin >> x;

            l = x;
            r = tot - 1;
        } else if (opt == 2) {
            int x;
            std::cin >> x;

            l = 0;
            r = x;
        } else {
            int x, y;
            std::cin >> x >> y;

            l = x;
            r = y;
        }

        a.push_back({l, r});
    }

    std::sort(a.begin(), a.end());

    std::priority_queue<int, std::vector<int>, std::greater<>> pq;

    int idx = 0;

    for (int i = 0; i < tot; i++) {
        while (idx < tot && a[idx].first <= i) {
            pq.push(a[idx].second);
            idx++;
        }

        if (pq.empty()) {
            std::cout << "N\n";
            return;
        }

        int cur = pq.top();
        pq.pop();

        if (cur < i) {
            std::cout << "N\n";
            return;
        }
    }

    std::cout << "Y\n";
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