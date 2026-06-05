#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    string s; cin >> s;
    int where = 0;

    auto compute = [](deque<int>& nums, deque<char>& ops) -> int {
        int n = nums.size();
        int ans = nums.front();
        nums.pop_front();
        for (int i = 1; i < n; i++) {
            ans += ops.front() == '+' ? nums.front() : -nums.front();
            ops.pop_front();
            nums.pop_front();
        }
        return ans;
    };

    auto push = [](deque<int>& nums, deque<char>& ops, int cur, char op) -> void {
        int n = nums.size();
        if (n == 0 || ops.back() == '+' || ops.back() == '-') {
            nums.emplace_back(cur);
            ops.emplace_back(op);
        } else {
            int topNum = nums.back();
            char topOp = ops.back();
            if (topOp == '*') {
                nums.pop_back();
                nums.emplace_back(topNum * cur);
            } else {
                nums.pop_back();
                nums.emplace_back(topNum / cur);
            }
            ops.emplace_back(op);
        }
    };

    function<int(int)> dfs = [&](int i) -> int {
        deque<int> nums;
        deque<char> ops;
        int cur = 0;
        while (i < s.size() && s[i] != ')') {
            if (s[i] >= '0' && s[i] <= '9') {
                cur = cur * 10 + s[i++] - '0';
            } else if (s[i] != '(') {
                push(nums, ops, cur, s[i++]);
                cur = 0;
            } else {
                cur = dfs(i + 1);
                i = where + 1;
            }
        }
        push(nums, ops, cur, '+');
        where = i;
        return compute(nums, ops);
    };

    cout << dfs(0);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
