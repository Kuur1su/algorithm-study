#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    string s; cin >> s;

    int where = 0;

    auto fill = [&](map<string, int>& ans, string name, map<string, int>& pre, int cnt) -> void {
        if (name.size() > 0 || !pre.empty()) {
            cnt = cnt == 0 ? 1 : cnt;
            if (name.size() > 0) {
                ans[name] += cnt;
            } else {
                for (auto const& kv : pre) {
                    ans[kv.first] += kv.second * cnt;
                }
            }
        }
    };

    function<map<string, int>(int)> dfs = [&](int i) -> map<string, int> {
        map<string, int> ans;
        string name = "";
        map<string, int> pre;
        int cnt = 0;
        while (i < s.size() && s[i] != ')') {
            if ((s[i] >= 'A' && s[i] <= 'Z') || s[i] == '(') {
                fill(ans, name, pre, cnt);
                name = "";
                pre.clear();
                cnt = 0;
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    name += s[i++];
                } else {
                    pre = dfs(i + 1);
                    i = where + 1;
                }
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                name += s[i++];
            } else {
                cnt = cnt * 10 + s[i++] -'0';
            }
        }
        fill(ans, name, pre, cnt);
        where = i;
        return ans;
    };

    map<string, int> res = dfs(0);
    for (auto const& kv : res) {
        cout << kv.first;
        if (kv.second != 1) cout << kv.second;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
