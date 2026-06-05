#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    stack<int> st;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int j; cin >> j;
        st.emplace(j);
    }

    function<int()> bottomOut = [&]() -> int {
        int ans = st.top();
        st.pop();
        if (st.empty()) {
            return ans;
        } else {
            int last = bottomOut();
            st.emplace(ans);
            return last;
        }
    };

    function<void()> reverse = [&]() {
        if (st.empty()) {
            return;
        } else {
            int num = bottomOut();
            reverse();
            st.emplace(num);
        }
    };

    reverse();
    for (int i = 0; i < n; i++) {
        int ans = st.top();
        st.pop();
        cout << ans << " \n"[i == n - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
