#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;

        hash.emplace(0, 1);
        int ans = 0;
        for (int i = 0, sum = 0; i < n; i++) {
            sum += nums[i];
            ans += hash[sum - k];
            if (hash.find(sum) == hash.end()) {
                hash.emplace(sum, 1);
            } else {
                hash[sum]++;
            }
        }
        return ans;
    }
};
