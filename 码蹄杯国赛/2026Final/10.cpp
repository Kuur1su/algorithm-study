#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 1e9 + 7;

int qpow(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}

int inv(int a) {
    return qpow(a, mod - 2);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int sum = accumulate(a.begin(), a.end(), 0ll) % mod;
    int isum = inv(sum);
    for (auto &i : a) i = i * isum % mod;

    int d = 1 - n;
    for (auto &p : a) {
        d += inv((1 + p + p * p) % mod);
        d %= mod;
    }
    if (d < 0) d += mod;
    cout << inv(d) << '\n';
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    solve();

    return 0;
}