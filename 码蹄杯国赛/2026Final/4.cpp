#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    int ans = (n - 1) / 2 * n;
    if (n % 3 == 0) {
        ans -= n / 3 * 2;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}