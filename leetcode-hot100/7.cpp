#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();

        int lmax = height[0], rmax = height[n - 1];
        int ans = 0;

        for (int l = 1, r = n - 2; l <= r; ) {
            if (rmax > lmax) {
                ans += std::max(0, lmax - height[l]);
                lmax = std::max(lmax, height[l]);
                l++;
            } else {
                ans += std::max(0, rmax - height[r]);
                rmax = std::max(rmax, height[r]);
                r--;
            }
        }

        return ans;
    }
};