#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int remain = 0;
        for (int i = 0; i < n; i++) {
            remain = (remain + nums[i]) % p;
        }
        if (remain == 0) return 0;

        unordered_map<int, int> mp;
        mp.emplace(0, -1);
        int ans = n;
        for (int i = 0, cur = 0, find; i < n; i++) {
            cur = (cur + nums[i]) % p;
            find = (cur - remain + p) % p;
            if (mp.count(find)) {
                ans = min(i - mp[find], ans);
            }
            mp.emplace(cur, i);
        }

        return ans == n ? -1 : ans;
    }
};
