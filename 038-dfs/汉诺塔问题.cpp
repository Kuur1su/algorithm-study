#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n; cin >> n;
    string from = "Left";
    string to = "Right";
    string other = "Middle";

    function<void(int, string, string, string)> dfs = [&](int i, string from, string to, string other) {
        if (i == 1) {
            cout << "Move 1 from " << from << " to " << to << '\n';
        } else {
            dfs(i - 1, from, other, to);
            cout << "Move " << i << " from " << from << " to " << to << '\n';
            dfs(i - 1, other, to, from);
        }
    };
    dfs(n, from, to, other);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
