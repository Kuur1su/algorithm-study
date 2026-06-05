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

    std::vector<std::pair<int, int>> a;
    for (int i = 0; i < n; i++) {
    	int l, r;
    	std::cin >> l >> r;

    	a.push_back({l, r});
    }

    std::sort(a.begin(), a.end());

    std::vector<std::pair<int, int>> ans;
    int l = a[0].first, r = a[0].second;
    for (int i = 1; i < n; i++) {
    	// std::cerr << l << "! " << r << "! \n";
    	if (r < a[i].first) {
    		ans.push_back({l, r});
    		l = a[i].first;
    		r = a[i].second;
    	} else {
    		r = std::max(a[i].second, r);
    	}

    }

    ans.push_back({l, r});

    // std::cerr << ans[0].first << ans[0].second << "\n";

    int res = 0;
    for (auto [ll, rr] : ans) {
    	// std::cerr << ll << "! " << rr << "! \n";
    	res += rr - ll + 1;
    }

    std::cout << res << "\n";

    return 0;
}