#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x1(n), y1(n), x2(n), y2(n);
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    auto cross = [&](int i, int j) -> int {
        if (x2[i] < x1[j] || x2[j] < x1[i]) return 0;
        if (y2[i] < y1[j] || y2[j] < y1[i]) return 0;
        return 1;
    };

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            cnt += cross(i, j);
        }
        cout << cnt << ' ';
    }
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    solve();

    return 0;
}