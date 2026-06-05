#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n; cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        int j; cin >> j;
        st.emplace(j);
    }

    // 找到栈中的最大值
    function<int(int)> fmax = [&](int deep) -> int {
        if (deep == 0) {
            return INT_MIN;
        } else {
            int num = st.top();
            st.pop();
            int restMax = fmax(deep - 1);
            int max_num = max(restMax, num);
            st.emplace(num);
            return max_num;
        }
    };

    // 告诉深度和栈最大值，找到最大值个数
    function<int(int, int)> times = [&](int deep, int max_num) -> int {
        if (deep == 0) {
            return 0;
        } else {
            int num = st.top();
            st.pop();
            int restTimes = times(deep - 1, max_num);
            int times = restTimes + (num == max_num ? 1 : 0);
            st.emplace(num);
            return times;
        }
    };

    // 把最大值沉底
    function<void(int, int, int)> down = [&](int deep, int max_num, int times) {
        if (deep == 0) {
            for (int i = 0; i < times; i++) {
                st.emplace(max_num);
            }
        } else {
            int num = st.top();
            st.pop();
            down(deep - 1, max_num, times);
            if (num != max_num) {
                st.emplace(num);
            }
        }
    };

    int deep = n;
    while (deep > 0) {
        int maxcur = fmax(deep);
        int k = times(deep, maxcur);
        down(deep, maxcur, k);
        deep -= k;
    }

    for (int i = 0; i < n; i++) {
        int j = st.top();
        cout << j << " ";
        st.pop();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
