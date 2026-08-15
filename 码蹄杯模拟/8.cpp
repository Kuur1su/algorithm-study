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

    std::unordered_map<int, int> mp;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    	// mp[a[i]]++;
    }

    b = a;

    std::sort(b.begin(),b.end());
    mp[b[0]]= 0;

    int num = 1;
    for (int i = 1; i < n; i++) {
    	if (b[i] == b[i - 1]) {
    		num++;
    	} else {
    		mp[b[i]] = mp[b[i - 1]] + num;
    		num = 1;
    	}
    }

    // for (auto [e, v] : mp) {
    // 	std::cerr << "e: " << e << " v: " << v << " ";
    // }

    for (int i = 0; i < n; i++) {
    	std::cout << mp[a[i]] + 1 << " \n"[i == n - 1];
    }


    return 0;
}