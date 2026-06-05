#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define Debug(x) { std::cerr << #x << " = " << x << '\n'; }

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> nums(n);

    for (auto &i : nums) cin >> i;

    vector<ll> l, r;

    function<void(int, int, ll, vector<ll>&)> gen = [&](int l, int r, ll curr, vector<ll>& sums) -> void {
        if (curr > m) return;
        if (l == r) {
            sums.push_back(curr);
        } else {
            gen(l + 1, r, curr, sums);
            gen(l + 1, r, curr + nums[l], sums);
        }
    };

    gen(0, n >> 1, 0, l);
    gen(n >> 1, n, 0, r);

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    ll ans = 0;
    int j = (int)r.size() - 1;
    for (int i = 0; i < (int)l.size(); i++) {
        while (j >= 0 && l[i] + r[j] > m) {
            --j;
        }
        ans += (j + 1);
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
