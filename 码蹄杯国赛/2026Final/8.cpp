#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = array<int, 2>;

constexpr int mod1 = 1e9 + 7, base1 = 127;
constexpr int mod2 = 1e9 + 9, base2 = 131;

struct String {
    vector<int> val1, val2;
    vector<int> hash1, hash2;

    String(string s) {
        int n = s.size();
        val1.resize(n + 1, 1);
        val2.resize(n + 1, 1);
        hash1.resize(n + 1, 1);
        hash2.resize(n + 1, 1); 
        for (int i = 0; i < n; i++) {
            val1[i + 1] = (val1[i] * base1) % mod1;
            val2[i + 1] = (val2[i] * base2) % mod2;
            hash1[i + 1] = (hash1[i] * base1 + s[i]) % mod1;
            hash2[i + 1] = (hash2[i] * base2 + s[i]) % mod2;
        }
    }

    int sub(int l, int r) {
        int h1 = hash1[r + 1] - hash1[l] * val1[r - l + 1];
        h1 = (h1 % mod1 + mod1) % mod1;
        int h2 = hash2[r + 1] - hash2[l] * val2[r - l + 1];
        h2 = (h2 % mod2 + mod2) % mod2;
        return h1 * mod2 + h2;
    }
};

vector<int> manacher(string s) {
    string t = "#";
    for (auto &c : s) {
        t += c;
        t += "#";
    }
    int n = t.size();
    vector<int> r(n);
    for (int i = 0, j = 0; i < n; i++) {
        if (2 * j - i >= 0 && j + r[j] > i) {
            r[i] = min(r[2 * j - i], j + r[j] - i);
        }
        while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {
            r[i] ++;
        }
        if (i + r[i] > j + r[j]) {
            j = i;
        }
    }
    return r;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    auto r = manacher(s);
    String S(s);

    unordered_set<int> st;
    vector<int> p(n + 1);
    for (int i = 0; i < n; i++) {
        int R = r[i * 2 + 1] / 2;
        while (R) {
            int h = S.sub(i - R + 1, i + R - 1);
            if (st.count(h)) break;
            st.insert(h);
            p[i - R + 1] ++;
            p[i + R] --;
            R --;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int R = r[i * 2 + 2] / 2;
        while (R) {
            int h = S.sub(i - R + 1, i + R);
            if (st.count(h)) break;
            st.insert(h);
            p[i - R + 1] ++;
            p[i + R + 1] --;
            R --;
        }
    }
    for (int i = 1; i <= n; i++) {
        p[i] += p[i - 1];
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]] += p[i];
    }

    vector<pii> ans;
    for (auto &[c, val] : mp) {
        ans.push_back({val, c});
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (auto &[val, c] : ans) {
        cout << (char)c << ' ';
    }
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    solve();

    return 0;
}