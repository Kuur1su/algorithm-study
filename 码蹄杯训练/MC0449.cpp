#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
    int n, k;
    std::cin >> n >> k;

    std::priority_queue<i64, std::vector<i64>> h;
    for (int i = 0; i < n; i++) {
    	int a;
    	std::cin >> a;

    	h.push(a);
    }

    for (int i = 0; i < k; i++) {
    	i64 val = h.top();
    	h.pop();
    	val /= 2;
    	h.push(val);
    }

    i64 ans = 0;
    while (!h.empty()) {
    	ans += h.top();
    	h.pop();

    	// std::cerr << ans << "!\n";
    }

    std::cout << ans << "\n";

    return 0;
}