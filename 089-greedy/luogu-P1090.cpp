#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::priority_queue<int, std::vector<int>, std::greater<>> pq;

    std::vector<int> a(n);
    for (auto& i : a) {
    	std::cin >> i;
    	pq.emplace(i);
	}
	
	int sum = 0;
	while (pq.size() > 1) {
		int a, b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		sum += a + b;
		pq.emplace(a + b);
	}
	std::cout << sum << "\n";

    return 0;
}