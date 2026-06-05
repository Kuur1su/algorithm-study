#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n; cin >> n;

    auto work = [&]() -> int {
        if (n <= 0) {
            return 1;
        } else {
            n--;
            n |= (n >> 1);
            n |= (n >> 2);
            n |= (n >> 4);
            n |= (n >> 8);
            n |= (n >> 16);
        }
        return n + 1;
    };

    cout << work();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
