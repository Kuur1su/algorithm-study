#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        std::vector<std::vector<int>> ans;

        std::sort(nums.begin(), nums.end());

        for (int f = 0; f < n; f++) {
            if (f > 0 && nums[f] == nums[f - 1]) {
                continue;
            }

            int thr = n - 1;
            int tar = -nums[f];

            for (int s = f + 1; s < thr; s++) {
                if (s > f + 1 && nums[s] == nums[s - 1]) {
                    continue;
                }

                while (s < thr && nums[s] + nums[thr] > tar) {
                    thr--;
                }

                if (s == thr) {
                    break;
                }

                if (nums[s] + nums[thr] == tar) {
                    ans.push_back({nums[f], nums[s], nums[thr]});
                }
            }
        }

        return ans;

    }
};