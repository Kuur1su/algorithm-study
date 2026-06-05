#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int eorAll = 0, eorHas = 0;
    for (int i = 0; i < n; i++) {
        eorAll ^= i;
        eorHas ^= a[i];
    }
    eorAll ^= n;
    cout << (eorAll ^ eorHas);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
