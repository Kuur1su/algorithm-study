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

    std::string t1 = "matiji";
    std::string t2 = "MATIJI";

    if (s == t1 || s == t2) {
    	std::cout << "Yes\n";
    } else {
    	std::cout << "No\n";
    }

    return 0;
}