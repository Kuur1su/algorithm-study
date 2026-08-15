#include <bits/stdc++.h>
#define int long long
using namespace std;

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;

    template<class T>
    LazySegmentTree(vector<T> v) {
        n = v.size();
        info.resize(4 << __lg(n));
        tag.resize(4 << __lg(n));
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l + 1 == r) {
                info[p] = v[l];
                return;
            }
            int m = (l + r) / 2;
            build(p << 1, l, m);
            build(p << 1 | 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }

    void pull(int p) {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }

    void apply(int p, const Tag &t) {
        info[p].apply(t);
        tag[p].apply(t);
    }

    void push(int p) {
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Tag();
    }

    void modify(int l, int r, const Tag &t) {
        return modify(1, 0, n, l, r, t);
    }
    void modify(int p, int l, int r, int x, int y, const Tag &t) {
        if (r <= x || y <= l) {
            return;
        }
        if (x <= l && r <= y) {
            apply(p, t);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        modify(p << 1, l, m, x, y, t);
        modify(p << 1 | 1, m, r, x, y, t);
        pull(p);
    }

    Info query(int l, int r) {
        return query(1, 0, n, l, r);
    }
    Info query(int p, int l, int r, int x, int y) {
        if (r <= x || y <= l) {
            return Info();
        }
        if (x <= l && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return query(p << 1, l, m, x, y) + query(p << 1 | 1, m, r, x, y);
    }
};

struct Tag {
    bool upd;
    Tag() : upd(false) {}
    Tag(bool u) : upd(true) {}
    void apply(const Tag &t) {
        if (t.upd) {
            upd = true;
        }
    }
};

struct Info {
    int sum;
    Info() : sum(0) {}
    Info(int x) : sum(x) {}
    void apply(const Tag &t) {
        if (t.upd) {
            sum = 0;
        }
    }
};

Info operator+ (const Info &a, const Info &b) {
    Info c;
    c.sum = a.sum + b.sum;
    return c;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    LazySegmentTree<Info, Tag> seg(a);

    int ans = accumulate(a.begin(), a.end(), 0ll);
    vector<int> stk;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            stk.emplace_back(i);
        } else if (stk.size()) {
            int l = stk.back();
            stk.pop_back();
            int sum = seg.query(l, i + 1).sum;
            if (sum < 0) {
                ans -= sum;
                seg.modify(l, i + 1, Tag(true));
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}