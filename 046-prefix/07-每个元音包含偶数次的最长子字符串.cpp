#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        vector<int> map(32, -2);
        map[0] = -1;

        auto move = [&](char c) -> int {
            switch (c) {
                case 'a' : return 0;
                case 'e' : return 1;
                case 'i' : return 2;
                case 'o' : return 3;
                case 'u' : return 4;
                default: return -1;
            }
        };

        int ans = 0;
        for (int i = 0, status = 0; i < n; i++) {
            int m = move(s[i]);
            if (m != -1) {
                status ^= 1 << m;
            }
            if (map[status] != -2) {
                ans = max(ans, i - map[status]);
            } else {
                map[status] = i;
            }
        }
        return ans;
    }
};
