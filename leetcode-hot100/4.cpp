#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int n = nums.size();

    	int s = 0;

    	for (int f = 0; f < n; f++) {
    		if (nums[f] != 0) {
    			if (f != s) {
    				std::swap(nums[f], nums[s]);
    			}
    			s++;
    		}
    	}
    }
};