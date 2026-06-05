#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (auto& i : nums) cin >> i;

    vector<int> sum(n + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = nums[i] + sum[i - 1];
    }


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
