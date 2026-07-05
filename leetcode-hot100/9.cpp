#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> res;
        int n = s.size(), m = p.size();
        if (n < m) return res;

        std::vector<int> pCount(26, 0);
        std::vector<int> sCount(26, 0);

        for (char c : p) {
            pCount[c - 'a']++;
        }

        for (int i = 0; i < m; i++) {
            sCount[s[i] - 'a']++;
        }

        if (sCount == pCount) {
            res.emplace_back(0);
        }

        for (int i = m ; i < n; i++) {
            sCount[s[i - m] - 'a']--;
            sCount[s[i] - 'a']++;

            if (sCount == pCount) {
                res.emplace_back(i - m + 1);
            }
        }
        
        return res;
    }
};