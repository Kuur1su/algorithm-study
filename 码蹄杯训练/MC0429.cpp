#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

constexpr int P = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector dp(n, std::vector<i64>(n, 0));

    for (int i = 0; i < n; i++) {
    	dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
    	for (int i = 0; i <= n - len; i++) {
    		int j = i + len - 1;
    		if (s[i] == s[j]) {
    			dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % P;
    		} else {
    			dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + P) % P;
    		}
    	}
    }

    std::cout << dp[0][n - 1] << "\n";

    return 0;
}