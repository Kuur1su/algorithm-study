#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	std::unordered_map<std::string, std::vector<std::string>> mp;

    	for (auto s : strs) {
    		std::string sorts = s;
    		std::sort(sorts.begin(), sorts.end());
    		mp[sorts].push_back(s);
    	}

    	std::vector<std::vector<std::string>> ans;
    	for (auto [_, cur] : mp) {
    		ans.push_back(cur);
    	}

    	return ans;
    }
};