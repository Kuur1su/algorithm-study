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

	vector dp(n, vector<int>(n, -1));
	for (int l = 0; l < n - 1; l++) {
		dp[l][l] = 1;
		if ((s[l] == '(' && s[l + 1] == ')') || s[l] == '[' && s[l + 1] == ']') {
			dp[l][l + 1] = 0;
		} else {
			dp[l][l + 1] = 2;
		}
	}
	dp[n - 1][n - 1] = 1;

	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 2; j < n; j++) {
			int p1 = inf, p2 = inf;
			if ((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']')) {
				p1 = dp[i + 1][j - 1];
			}
			for (int m = i; m < j; m++) {
				p2 = min(p2, dp[i][m] + dp[m + 1][j]);
			}
			dp[i][j] = min(p1, p2);
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