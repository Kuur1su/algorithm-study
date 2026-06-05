#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (auto &i : nums) cin >> i;
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    function<void(int)> dfs = [&](int pos) {
        if (pos == n) {
            ans.emplace_back(nums);
        } else {
            unordered_set<int> seen;
            for (int k = pos; k < n; k++) {
                if (!seen.insert(nums[k]).second) continue; // 如果nums[k]没有来过i位置，才会尝试
                // insert()函数返回一个pair<iterator, bool>
                // 其中.first是指向插入位置的迭代器
                //    .second是表示插入是否成功
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
