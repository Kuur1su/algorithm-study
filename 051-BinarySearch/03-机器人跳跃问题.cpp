#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define Debug(x) { std::cerr << #x << " = " << x << '\n'; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    int maxn = 0;
    for (int i = 0; i < n; i++) {
        maxn = max(a[i], maxn);
    }

    // 返回机器人到达最大值的时候多出来能量吗
    auto work = [&](int e) -> bool {
        for (int i = 0; i < n; i++) {
            if (e > a[i]) {
                e += e - a[i];
            } else {
                e -= a[i] - e;
            }
            if (e >= maxn) return true;
            if (e < 0) return false;
        }
        return true;
    };

    int m, ans = -1;
    for (int l = 0, r = maxn; l <= r; ) {
        m = l + ((r - l) >> 1);
        if (work(m)) {
            r = m - 1;
            ans = m;
        } else {
            l = m + 1;
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
