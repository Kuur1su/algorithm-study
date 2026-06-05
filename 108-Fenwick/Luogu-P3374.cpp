#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

template<typename T>
struct Fenwick {
	int n;
	std::vector<T> a;

	Fenwick(int n_) {
		init(n_);
	}

	void init(int n_) {
		n = n_;
		a.assign(n, T{});
	}

	void add(int x, const T &v) {
		for (int i = x + 1; i <= n; i += i & -i) {
			a[i - 1] += v;
		}
	}

	T sum(int x) {
		T ans{};
		for (int i = x; i > 0; i -= i & -i) {
			ans = ans += a[i - 1];
		}
		return ans;
	}

	T rangeSum(int l, int r) {
		return sum(r) - sum(l);
	}

	// int select(const T &k) {
	// 	int x = 0;
	// 	T cur{};
	// 	for (int i = 1 << std::__lg(n); i; i /= 2) {

	// 	}
	// }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
    int n, m;
    std::cin >> n >> m;

    Fenwick<int> fenwick(n);
    for (int i = 0; i < n; i++) {
    	int v;
    	std::cin >> v;
    	fenwick.add(i, v);
    }

    while (m--) {
    	int q;
    	std::cin >> q;

    	if (q == 1) {
    		int x, k;
    		std::cin >> x >> k;

    		fenwick.add(x - 1, k);
    	} else {
    		int x, y;
    		std::cin >> x >> y;
    		// 0-base [x - 1, y) -> [x - 1, y - 1]
    		std::cout << fenwick.rangeSum(x - 1, y) << "\n";
    	}
    }

    return 0;
}