#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

constexpr int inf = 1e9;

void solve() {
	string s;
	cin >> s;

	int n = s.size();

	vector dp(n, vector<int>(n));
	for (int i = 0; i < n - 1; i++) {
		dp[i][i] = 1;
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = 1;
		} else {
			dp[i][i + 1] = 2;
		}
	}
	dp[n - 1][n - 1] = 1;

	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 2; j < n; j++) {
			int ans;
			if (s[i] == s[j]) {
				dp[i][j] = dp[i][j - 1];
			} else {
				ans = inf;
				for (int m = i; m < j; m++) {
					ans = min(ans, dp[i][m] + dp[m + 1][j]);
				}
				dp[i][j] = ans;
			}
		}
	}

	cout << dp[0][n - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}