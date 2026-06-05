#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

constexpr int P = 1E9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    }

    int maxA = *std::max_element(a.begin(), a.end());
    std::vector<int> cnt(maxA + 1);
    for (int x : a) cnt[x]++;

    std::vector<int> pow2(n + 1);
	pow2[0] = 1;
    for (int i = 1; i <= n; i++) {
    	pow2[i] = (pow2[i - 1] * 2) % P;
    }

    std::vector<int> dp(maxA + 1);
    for (int i = maxA; i >= 1; i--) {
    	i64 c = 0;
    	for (int j = i; j <= maxA; j += i) {
    		c += cnt[j];
    	} 
    	dp[i] = (pow2[(int)c] - 1 + P) % P;
    	for (int j = 2 * i; j <= maxA; j += i) {
    		dp[i] = (dp[i] - dp[j] + P) % P;
    	}
    }

    std::cout << dp[1];

    return 0;
}