#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
    int n;
    std::cin >> n;

    std::vector<int> key(n);
    for (int i = 0; i < n; i++) {
    	int x;
    	std::cin >> x;
    	x--;
    	key[x] = i;
    }

    std::vector<int> ls(n, -1), rs(n, -1);
    std::vector<int> stk;

    for (int i = 0; i < n; i++) {
    	int lst = -1;
    	while (stk.size() && key[stk.back()] > key[i]) {
    		lst = stk.back();
    		stk.pop_back();
    	}
    	if (stk.size()) {
    		rs[stk.back()] = i;
    	}
    	if (lst != -1) {
    		ls[i] = lst;
    	}
    	stk.emplace_back(i);
    }

    int root = stk.front();

    auto preorder = [&](auto&& self, int i) {
    	if (i == -1) return;
    	std::cout << i + 1 << " ";
    	self(self, ls[i]);
    	self(self, rs[i]);
    };

    preorder(preorder, root);
    std::cout << "\n";

    return 0;
}