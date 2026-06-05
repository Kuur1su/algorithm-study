#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // 笛卡尔树
    std::vector<int> ls(n, -1), rs(n, -1), stk;
    for (int i = 0; i < n; i++) {
        int last = -1;
        while (stk.size() && a[stk.back()] > a[i]) {
            last = stk.back();
            stk.pop_back();
        }
        if (stk.size()) {
            rs[stk.back()] = i;
        }
        if (last != -1) {
            ls[i] = last;
        }
        stk.emplace_back(i);
    }

    i64 ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
        ans1 ^= 1LL * (i + 1) * (ls[i] + 2);
        ans2 ^= 1LL * (i + 1) * (rs[i] + 2);
    }
    std::cout << ans1 << " " << ans2 << "\n";

    return 0;
}