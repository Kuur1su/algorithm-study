#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;

	for (int i = s.size() - 1; i >= 0; i--) {
		std::cout << s[i];
	}
	std::cout << "\n";

	return 0;
}