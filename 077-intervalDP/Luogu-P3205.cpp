#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

constexpr int P = 19650827;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &i : a) cin >> i;

	if (n == 1) {
		cout << a[0] << "\n";
		return;
	}

	vector<int> dpl(n), dpr(n);
	if (a[n - 2] < a[n - 1]) {
		dpr[n - 1] = 1;
		dpl[n - 1] = 1;
	}

	for (int l = n - 3; l >= 0; l--) {
		if (a[l] < a[l + 1]) {
			dpl[l + 1] = 1;
			dpr[l + 1] = 1;
		} else {
			dpl[l + 1] = 0;
			dpr[l + 1] = 0;
		}
		for (int r = l + 2; r < n; r++) {
			int p1 = 0, p2 = 0;
			if (a[l] < a[l + 1]) {
				p1 = (p1 + dpl[r]) % P;
			}
			if (a[l] < a[r]) {
				p1 = (p1 + dpr[r]) % P;
			}
			if (a[r] > a[l]) {
				p2 = (p2 + dpl[r - 1]) % P;
			}
			if (a[r] > a[r - 1]) {
				p2 = (p2 + dpr[r - 1]) % P;
			}
			dpl[r] = p1;
			dpr[r] = p2;
		}
	}

	cout << (dpl[n - 1] + dpr[n - 1]) % P << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}