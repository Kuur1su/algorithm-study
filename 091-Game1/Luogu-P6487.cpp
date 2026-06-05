#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::cin.tie(nullptr);
    
    i64 n;
    std::cin >> n;

    std::vector<i64> f;
    f.emplace_back(1); 
    f.emplace_back(2);
    int sz = 1;
    while (f[sz] <= n) {
    	f.emplace_back(f[sz] + f[sz - 1]);
    	sz++;
    }

    i64 ans = -1;
    while (n != 1 && n != 2) {
    	auto it = std::upper_bound(f.begin(), f.end(), n);
    	it--;
    	if (n == *it) {
    		ans = *it;
    		break;
    	}
    	n -= *it;
    }
    
    if (ans != -1) {
    	std::cout << ans << "\n";
    } else {
    	std::cout << n << "\n";
    }

    return 0;
}