#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    std::vector<std::vector<int>> diff(n + 1, std::vector<int>(26));

    for (int i = 1; i <= n; i++) {
    	for (int j = 0; j < 26; j++) {
    		diff[i][j] = diff[i - 1][j];
    	}
    	diff[i][s[i - 1] - 'a']++;
    }

    while (q--) {
    	int l, r;
    	std::cin >> l >> r;

    	int y = 0;
    	for (int j = 0; j < 26; j++) {
    		int cnt = diff[r][j] - diff[l - 1][j];

    		if (cnt % 2) {
    			y++;
    		}
    	}
		std::cout << 26 - y << " " << y << "\n";
    }

    return 0;
}