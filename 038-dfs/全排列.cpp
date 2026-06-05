#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (auto &i : nums) cin >> i;

    vector<vector<int>> ans;
    function<void(int)> dfs = [&](int pos) {
        if (pos == n) {
            ans.emplace_back(nums);
            return;
        } else {
            for (int k = pos; k < n; k++) {
                // 数组中所有内容都来到pos位置试一遍，最后换回来。
                swap(nums[pos], nums[k]);
                dfs(pos + 1);
                swap(nums[pos], nums[k]);
            }
        }
    };

    dfs(0);
    for (auto &vec : ans) {
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " \n"[i == vec.size() - 1];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
