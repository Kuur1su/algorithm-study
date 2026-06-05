#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    string s; cin >> s;
    unordered_set<string> hash;
    string res = "";

    // 回溯擦除路径
    // function<void(int)> dfs1 = [&](int pos) {
    //     if (pos == s.size()) {
    //         hash.emplace(res);
    //         return;
    //     } else {
    //         dfs1(pos + 1);
    //         res += s[pos];
    //         dfs1(pos + 1);
    //         res.pop_back();
    //     }
    // };
    // dfs1(0);

    // 用size管理路径大小，不用擦除
    // vector<char> path(s.size());
    // function<void(int, int)> dfs2 = [&](int pos, int size) {
    //     if (pos == s.size()) {
    //         hash.emplace(string(path.begin(), path.begin() + size));
    //         return;
    //     } else {
    //         path[size] = s[pos];
    //         dfs2(pos + 1, size + 1);
    //         dfs2(pos + 1, size);
    //     }
    // };
    // dfs2(0, 0);

    // 同上，语法不通增加substr的开销
    string path(s.size(), ' ');
    function<void(int, int)> dfs3 = [&](int pos, int size) {
        if (pos == s.size()) {
            hash.emplace(path.substr(0, size));
        } else {
            path[size] = s[pos];
            dfs3(pos + 1, size + 1);
            dfs3(pos + 1, size);
        }
    };
    dfs3(0, 0);

    for (auto &ans : hash) cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
