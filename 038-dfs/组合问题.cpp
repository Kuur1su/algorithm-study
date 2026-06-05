#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

// 输入一个数组，讨论所有组合的情况。
void solve() {
    // 输入部分
    int n; cin >> n;
    vector<vector<int>> ans;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());

    vector<int> path(n);
    function<void(int, int)> dfs = [&](int pos, int size) {
        if (pos == n) { // 遇到终止位置，统筹答案，加入到ans数组中
            ans.emplace_back(path.begin(), path.begin() + size);
            return;
        } else {
            int next = pos + 1;
            while (next < n && a[pos] == a[next]) next++; // 找到下一组的起始位置
            // 不要当前组的任何数
            dfs(next, size);
            // 当前组分别取1, 2...j - i - 1个
            for (; pos < next; pos++) {
                path[size++] = a[pos];
                dfs(next, size);
            }
        }
    };


    dfs(0, 0);
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
