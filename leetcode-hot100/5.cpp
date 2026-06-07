#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

class Solution {
public:
    int maxArea(vector<int>& height) {
    	int n = height.size();

    	int ans = 0;

    	for (int l = 0, r = n - 1; l <= r; ) {
    		if (height[l] <= height[r]) {
    			ans = std::max(ans, (height[r] * (r - l)));
    			l++;
    		} else {
    			ans = std::max(ans, (height[l] * (r - l)));    			
    			r--;
    		}
    	}

    	return ans;
    }
};