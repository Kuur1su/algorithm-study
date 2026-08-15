#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    int ans = 0;
    for (int i = k - 1; i < n; i += k) {
        ans += a[i];
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    solve();

    return 0;
}