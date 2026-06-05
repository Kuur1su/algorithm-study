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

    std::vector<int> a(n);
    for (auto& i : a) std::cin >> i;
    std::sort(a.begin(), a.end());

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int x = 0, y = n - 1;
        if (a[i] == a[x] + a[y]) {
            ans++;
        }
        if (a[i] < a[x] + a[y]) {
            y--;
        }
        if (a[i] > a[x] + a[y]) {
            x++;
        }
    }

    return 0;
}