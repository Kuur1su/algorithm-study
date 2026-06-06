#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	std::unordered_set<int> cnt;
    	for (auto c : nums) {
    		cnt.insert(c);
    	}

    	int l = 0;

    	for (auto n : cnt) {
    		if (cnt.find(n - 1) == cnt.end()) {
    			int cur = n;
    			int s = 1;

    			while (cnt.find(cur + 1) != cnt.end()) {
    				cur += 1;
    				s += 1;
    			}

    			l = std::max(l, s);
    		}
    	}

    	return l;
    }
};