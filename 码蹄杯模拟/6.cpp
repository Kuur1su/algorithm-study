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

    std::unordered_map<int, int> num;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        num[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        std::cout << num[a[i]] - 1 << " \n"[i == n - 1];
    }

    return 0;
}