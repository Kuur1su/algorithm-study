#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] > 0) nums[i] = 1;
        if (nums[i] < 0) nums[i] = -1;
    }

    unordered_map<int, int> hashmp;
    hashmp[0] = -1;
    int cur = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        cur += nums[i];
        if (hashmp.count(cur)) {
            ans = max(ans, i - hashmp[cur]);
        } else {
            hashmp[cur] = i;
        }
    }

    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
