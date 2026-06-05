#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (auto& i : nums) cin >> i;

    int ans = 0;
    unordered_map<int, int> hash;
    hash.emplace(0, -1);
    for (int i = 0, sum = 0; i < n; i++) {
        sum += nums[i];
        if (hash.find(sum - k) != hash.end()) {
            ans = max(ans, i - hash[sum - k]);
        }
        if (hash.find(sum) == hash.end()) {
            hash.emplace(sum, i);
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
