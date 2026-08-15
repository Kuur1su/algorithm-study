#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int M = 1e6 + 5;

struct DSU {
    vector<int> f, siz;

    DSU(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] < siz[y]) {
            swap(x, y);
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
};

struct Euler {
    vector<int> primes;
    vector<bool> is_prime;

    Euler(int n) {
        is_prime.resize(n + 1, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i <= n; i++) {
            if (is_prime[i]) {
                primes.emplace_back(i);
            }
            for (auto &p : primes) {
                if (i * p > n) break;
                is_prime[i * p] = false;
                if (i % p == 0) break;
            }
        }
    }
};
Euler sieve(M);

vector<vector<int>> d(M);
void init() {
    for (auto &p : sieve.primes) {
        for (int j = p; j < M; j += p) {
            d[j].emplace_back(p);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        for (auto &p : d[a[i]]) {
            mp[p].emplace_back(i);
        }
    }

    vector<array<int, 3>> v;
    for (auto &[p, vec] : mp) {
        for (int i = 0; i + 1 < vec.size(); i++) {
            v.push_back({p * (vec[i + 1] - vec[i]), vec[i], vec[i + 1]});
        }
    }
    sort(v.begin(), v.end());

    DSU dsu(n);
    int cnt = 0;
    for (auto &[val, i, j] : v) {
        if (dsu.merge(i, j)) {
            cnt ++;
        }
        if (cnt == n - 1) {
            cout << val << '\n';
            return;
        }
    }
    cout << -1 << '\n';
    return;
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    init();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}