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

    std::vector<std::array<int, 2>> nums(n);
    for (auto& [a, b] : nums) {
    	std::cin >> a >> b;
    }
    std::sort(nums.begin(), nums.end(), 
    	[](const auto& a, const auto& b) {
    		return a[1] < b[1];
    	});

    int ans = 0, cur = -1;
    for (int i = 0; i < n; i++) {
    	if (cur <= nums[i][0]) {
    		ans++;
    		cur = nums[i][1];
    	}
    }

    std::cout << ans << "\n";

    return 0;
}