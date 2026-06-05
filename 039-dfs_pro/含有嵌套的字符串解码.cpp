#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    string s; cin >> s;

    int where = 0;

    function<string(int)> dfs = [&](int i) -> string {
        int cur = 0;
        string path = "";
        while (i < s.size() && s[i] != ']') {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                path += s[i++];
            } else if (s[i] >= '0' && s[i] <= '9') {
                cur = cur * 10 + s[i++] - '0';
            } else {
                for (int k = 0; k < cur; k++) path += dfs(i + 1);
                i = where + 1;
                cur = 0;
            }
        }
        where = i;
        return path;
    };

    cout << dfs(0);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
