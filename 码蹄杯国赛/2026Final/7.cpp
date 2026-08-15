#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> ans;
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (x - i < 0 || !vis[x - i]) {
            ans.emplace_back(i);
            vis[i] = true;
        }
    }
    
    cout << ans.size() << '\n';
    for (auto &i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}