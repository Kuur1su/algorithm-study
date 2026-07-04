#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.size();
        std::unordered_map<char, int> mp;
        int l = 0;
        int ans = 0;

        for (int r = 0; r < n; r++) {
            l = std::max(l, mp[s[r]]);
            mp[s[r]] = r + 1; // 统计每个字符最后出现的位置
            ans = std::max(ans, r - l + 1);
        }
        
        return ans;
    }
};