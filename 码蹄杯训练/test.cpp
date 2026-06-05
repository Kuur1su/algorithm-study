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

    int a = 0, b = 0;
    bool ok = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            ok = true;
            continue;
        }
        if (!ok) {
            a = a * 10 + (s[i] - '0');
        } else {
            b = b * 10 + (s[i] - '0');
        }
    }

    std::cout << a << "+" << b << "=" << a + b << "\n";
    std::cout << a << "-" << b << "=" << a - b << "\n";

    return 0;
}