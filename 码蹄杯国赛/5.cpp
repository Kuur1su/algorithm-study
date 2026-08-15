#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int sum = 0;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}

	std::vector<int> diff(n + 1);
	diff[1] = a[0];
	for (int i = 2; i <= n; i++) {
		diff[i] = diff[i - 1] + a[i - 1];
	}

	int sum1 = sum;
	int sum2 = sum;

	for (int i = n - 1; i >= 0; i--) {
		if (a[i] < 0 && s[i] != 'a') {
			int no_a = 1;
			int n_a = 0;
			int j = i - 1;
			while (1) {
				if (s[j] != 'a') {
					no_a++;
					j--;
				} else {
					n_a++;
					j--;
				}
				if (n_a == no_a) {
					int cur = diff[i + 1] - diff[j + 1];
					if (cur < 0) {
						sum1 -= cur;
					}
					i = j;
					break;
				}		
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i] < 0 && s[i] == 'a') {
			int no_a = 0;
			int n_a = 1;
			int j = i + 1;
			while (1) {
				if (s[j] != 'a') {
					no_a++;
					j++;
				} else {
					n_a++;
					j++;
				}
				if (n_a == no_a) {
					int cur = diff[j] - diff[i];
					if (cur < 0) {
						std::cerr << cur << "?";
						sum2 -= cur;
					}
					i = j;
					break;
				}		
			}
		}
	}

	std::cerr << sum1 << " " << sum2 <<"\n";

	std::cout << std::max(sum1, sum2) << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
 	int T;
 	std::cin >> T;

 	while (T--) {
 		solve();
 	}

    return 0;
}