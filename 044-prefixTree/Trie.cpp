#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr int MAXN = 100000;
vector<vector<int>> Tree(MAXN + 1, vector<int>(26, 0));
vector<int> pass(MAXN + 1, 0);
vector<int> endv(MAXN + 1, 0); // 避免与标准库函数end冲突
int cnt = 1;

void init() {
    fill(Tree[1].begin(), Tree[1].end(), 0);
    pass[1] = 0;
    endv[1] = 0;
    cnt = 1;
}

void solve() {
    int op;
    string s;
    cin >> op >> s;

    auto insert = [&](const string& word) {
        int cur = 1;
        pass[cur]++;
        for (char ch : word) {
            int path = ch - 'a';
            if (Tree[cur][path] == 0) {
                Tree[cur][path] = ++cnt;
            }
            cur = Tree[cur][path];
            pass[cur]++;
        }
        endv[cur]++;
    };

    auto search = [&](const string& word) -> int {
        int cur = 1;
        for (char ch : word) {
            int path = ch - 'a';
            if (Tree[cur][path] == 0) {
                return 0;
            }
            cur = Tree[cur][path];
        }
        return endv[cur];
    };

    auto prefixNumber = [&](const string& pre) -> int {
        int cur = 1;
        for (char ch : pre) {
            int path = ch - 'a';
            if (Tree[cur][path] == 0) {
                return 0;
            }
            cur = Tree[cur][path];
        }
        return pass[cur]; // 返回经过该节点的单词数
    };

    auto deletenode = [&](const string& word) -> void {
        if (search(word) > 0) {
            int cur = 1;
            pass[cur]--; // 减少根节点的pass计数
            for (char ch : word) {
                int path = ch - 'a';
                int next_node = Tree[cur][path];
                pass[next_node]--; // 减少子节点的pass计数
                cur = next_node;
            }
            endv[cur]--; // 减少单词结束节点的end计数
        }
    };

    if (op == 1) {
        insert(s);
    } else if (op == 2) {
        deletenode(s);
    } else if (op == 3) {
        cout << (search(s) != 0 ? "YES" : "NO") << '\n'; // 修复输出括号
    } else if (op == 4) {
        cout << prefixNumber(s) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
