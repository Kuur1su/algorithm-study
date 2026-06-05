#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> sums(n + 1);

        for (int i = 0; i < n; i++) {
            if (hours[i] > 8) hours[i] = 1;
            else hours[i] = -1;
        }

        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0, sum = 0; i < n; i++) {
            sum += hours[i];
            if (sum > 0) {
                ans = i + 1;
            } else {
                if (mp.count(sum - 1)) {
                    ans = max(ans, i - mp[sum - 1]);
                }
            }
            if (!mp.count(sum)) {
                mp.emplace(sum, i);
            }
        }
        return ans;
    }
};
